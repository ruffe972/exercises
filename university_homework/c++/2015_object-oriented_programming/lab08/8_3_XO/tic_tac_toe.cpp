#include <QPushButton>
#include <QApplication>
#include <QDesktopWidget>
#include "tic_tac_toe.h"

int TicTacToe::optimalWindowSize(int cellsInLine) const
{
    return std::max(cellsInLine * approximateMinButtonSize, 180);
}

int TicTacToe::getOptimalCellsInLine() const
{
    const int maxWindowSize = QApplication::desktop()->screenGeometry().height() - 100;
    if (optimalWindowSize(desiredCellsNumberInLine) > maxWindowSize)
        return maxWindowSize / approximateMinButtonSize;
    return desiredCellsNumberInLine;
}

TicTacToe::TicTacToe(QWidget *parent) :
    QMainWindow(parent),
    cellsInLine(getOptimalCellsInLine()),
    core(cellsInLine),
    centralWidget(new QWidget(this)),
    statusBar(new QStatusBar(this)),
    layout(new QGridLayout(centralWidget))
{
    setWindowTitle("XO");
    setFixedWidth(optimalWindowSize(cellsInLine));
    setFixedHeight(width() + statusBarHeight);
    statusBar->setGeometry(0, 0, width(), statusBarHeight);
    statusBar->setSizeGripEnabled(false);
    centralWidget->setGeometry(0, statusBarHeight - 3, width(), height() - statusBarHeight);
    layout->setSpacing(width() / cellsInLine / 10);
    QFont font;
    font.setPixelSize(width() / cellsInLine / 2);
    for (int i = 0; i < cellsInLine; i++)
    {
        for (int j = 0; j < cellsInLine; j++)
        {
            auto button = new QPushButton(centralWidget);
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            layout->addWidget(button, i, j);
            connect(button, &QPushButton::clicked, this, &buttonClick);
            button->setFont(font);
        }
    }
    setupNewGame();
}

void TicTacToe::setupNewGame()
{
    statusBar->showMessage(QString::number(core.victoryLineLength) + " cells to win.");
    newGameFlag = false;
    eraseCounter = clicksForNewGame;
    drawCounter = cellsInLine * cellsInLine;
    core.currentPlayer = 0;
    for (auto button: centralWidget->findChildren<QPushButton*>())
        button->setText("");
    for (int i = 0; i < cellsInLine; i++)
        core.fieldMatrix[i].fill(' ');
}

void TicTacToe::buttonClick()
{
    auto button = dynamic_cast<QPushButton*>(QObject::sender());
    if (newGameFlag)
        setupNewGame();
    else if (button->text() == "")
    {
        int row = 0;
        int col = 0;
        int unneeded = 0;
        layout->getItemPosition(layout->indexOf(button), &row, &col, &unneeded, &unneeded);
        QChar currentSymbol = core.symbols[core.currentPlayer];
        core.fieldMatrix[row][col] = currentSymbol;
        button->setText(currentSymbol);
        if (core.playerWon(row, col))
        {
            statusBar->showMessage(QString(currentSymbol) + " won! Click on any cell.");
            newGameFlag = true;
        }
        else if (drawCounter == 1)
        {
            statusBar->showMessage("Draw. Click on any cell.");
            newGameFlag = true;
        }
        else
        {
            core.currentPlayer = core.currentPlayer == 0 ? 1 : 0;
            eraseCounter = clicksForNewGame;
            drawCounter--;
        }
    }
    else
    {
        eraseCounter--;
        if (eraseCounter == 0)
            setupNewGame();
    }
}
