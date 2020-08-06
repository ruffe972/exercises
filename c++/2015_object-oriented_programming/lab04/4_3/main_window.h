#pragma once
#include <QWidget>
#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QVector>
#include <QSignalMapper>
#include "two_operands_calculator.h"

//! Advanced calculator
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
private:
    enum class CurrentOperand {nonEmpty, emptyFirst, emptySecond};
private slots:
    void printDotOrDigitChangingWidgets(QString string);
    void processOperationPress(int operationCode);
    void processEqualsPress();
private:
    void moveCursorToTheEnd();
    void maintainConnections();
    void makeFancy();
    TwoOperandsCalculator::Operation currentOperation;
    CurrentOperand currentOperand;
    double firstOperand;
    QVector<QPushButton*> operationButtons;
    QWidget *centralWidget;
    QLineEdit *display;
    QPushButton *equalsButton;
    QPushButton *dotButton;
    QVector<QPushButton*> digitButtons;
};
