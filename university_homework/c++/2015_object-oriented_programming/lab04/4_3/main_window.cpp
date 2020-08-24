#include <QShortcut>
#include <QGridLayout>
#include "main_window.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    currentOperand(CurrentOperand::emptyFirst),
    firstOperand(0),
    centralWidget(new QWidget(this)),
    display(new QLineEdit(centralWidget)),
    equalsButton(new QPushButton("=", centralWidget)),
    dotButton(new QPushButton(".", centralWidget)),
    digitButtons(10)
{
    setFixedSize(250, 260);
    centralWidget->resize(size());
    auto layout = new QGridLayout(centralWidget);
    layout->addWidget(display, 0, 0, 1, 4);
    digitButtons[0] = new QPushButton("0", centralWidget);
    for (int i = 1; i < digitButtons.size(); i++)
    {
        digitButtons[i] = new QPushButton(QString().setNum(i), centralWidget);
        layout->addWidget(digitButtons[i], (i + 2) / 3, (i - 1) % 3);
    }

    for (int i = 0; i < TwoOperandsCalculator::operations.size(); i++)
    {
        char buttonText = static_cast<char>(TwoOperandsCalculator::operations[i]);
        operationButtons << new QPushButton(QChar(buttonText), centralWidget);
        layout->addWidget(operationButtons[i], i + 1, 3);
    }
    layout->addWidget(dotButton, 4, 0);
    layout->addWidget(digitButtons[0], 4, 1);
    layout->addWidget(equalsButton, 4, 2);
    maintainConnections();
    makeFancy();
}


void MainWindow::maintainConnections()
{
    auto digitMapper = new QSignalMapper(centralWidget);
    for (auto button: digitButtons)
    {
        connect(button, SIGNAL(clicked()), digitMapper, SLOT(map()));
        digitMapper->setMapping(button, button->text());
    }
    connect(digitMapper, SIGNAL(mapped(QString)), this, SLOT(printDotOrDigitChangingWidgets(QString)));

    auto operationMapper = new QSignalMapper(centralWidget);
    for (int i = 0; i < operationButtons.size(); i++)
    {
        connect(operationButtons[i], SIGNAL(clicked()), operationMapper, SLOT(map()));
        operationMapper->setMapping(operationButtons[i], i);
    }
    connect(operationMapper, SIGNAL(mapped(int)), this, SLOT(processOperationPress(int)));

    auto dotSlot = [this]() { dotButton->setEnabled(false); printDotOrDigitChangingWidgets("."); };
    connect(dotButton, &QPushButton::clicked, dotSlot);
    connect(equalsButton, &QPushButton::clicked, this, &processEqualsPress);
}


void MainWindow::makeFancy()
{
    setWindowTitle("Calculator");
    display->setAlignment(Qt::AlignRight);
    display->setReadOnly(true);
    equalsButton->setEnabled(false);
    for (auto widget: centralWidget->findChildren<QWidget*>())
    {
        QFont font("Consolas");
        font.setPointSize(14);
        widget->setFont(font);
        widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }
    for (auto button: findChildren<QPushButton*>())
        button->setShortcut(button->text());
    equalsButton->setShortcut(QStringLiteral("Return"));
    for (auto button: operationButtons)
        button->setEnabled(false);
}


inline void MainWindow::moveCursorToTheEnd()
{
    display->setCursorPosition(display->text().length());
}


void MainWindow::printDotOrDigitChangingWidgets(QString string)
{
    if (currentOperand != CurrentOperand::nonEmpty)
    {
        if (currentOperand == CurrentOperand::emptyFirst)
            for (auto button: operationButtons)
                button->setEnabled(true);
        else
            equalsButton->setEnabled(true);
        currentOperand = CurrentOperand::nonEmpty;
        display->clear();
    }
    else
        moveCursorToTheEnd();
    display->insert(string);
}


void MainWindow::processOperationPress(int operationCode)
{
    firstOperand = display->text().toDouble();
    for (auto button: operationButtons)
        button->setEnabled(false);
    currentOperand = CurrentOperand::emptySecond;
    currentOperation = TwoOperandsCalculator::operations[operationCode];
    dotButton->setEnabled(true);
    moveCursorToTheEnd();
}


void MainWindow::processEqualsPress()
{
    double secondOperand = display->text().toDouble();
    try
    {
        double result = TwoOperandsCalculator::calculate(firstOperand, currentOperation, secondOperand);
        display->setText(QString("%1").arg(result, 0, 'g', 12));
    }
    catch (TwoOperandsCalculator::DivisionByZero)
    {
        display->setText("Error");
    }
    currentOperand = CurrentOperand::emptyFirst;
    equalsButton->setEnabled(false);
    dotButton->setEnabled(true);
    moveCursorToTheEnd();
}
