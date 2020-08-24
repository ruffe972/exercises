#include "calculator.h"
#include "ui_calculator.h"
#include <QStringList>


Calculator::Calculator(QWidget *parent) : QMainWindow(parent), ui(new Ui::Calculator)
{
    ui->setupUi(this);
    connect(ui->leftOperand, SIGNAL(valueChanged(int)), this, SLOT(updateResult()));    
    QStringList operations;
    operations << "+" << "-" << "*" << "/";
    ui->operation->addItems(operations);
    connect(ui->operation, SIGNAL(currentIndexChanged(int)), this, SLOT(updateResult()));
    connect(ui->rightOperand, SIGNAL(valueChanged(int)), this, SLOT(updateResult()));
}


Calculator::~Calculator()
{
    delete ui;
}


double Calculator::calculate(int left, char operation, int right) const
{
    double result = -1;
    switch (operation)
    {
    case '+':
        result = left + right;
        break;
    case '-':
        result = left - right;
        break;
    case '*':
        result = left * right;
        break;
    case '/':
    {
        if (right == 0)
            result = 0;
        else
            result = (double)left / right;
        break;
    }
    }
    return result;
}


void Calculator::updateResult()
{
    char operation = ui->operation->currentText()[0].toLatin1();
    QString resultString;
    double resultNumber = calculate(ui->leftOperand->value(), operation, ui->rightOperand->value());
    ui->result->setText(resultString.setNum(resultNumber));
}
