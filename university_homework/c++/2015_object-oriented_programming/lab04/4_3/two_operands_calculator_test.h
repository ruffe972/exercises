#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "two_operands_calculator.h"


class TwoOperandsCalculatorTest : public QObject
{
    Q_OBJECT
public:
    explicit TwoOperandsCalculatorTest(QObject *parent = 0) : QObject(parent) {}
private:
    typedef TwoOperandsCalculator calc;
private slots:


    void sumTest()
    {
        QCOMPARE(calc::calculate(3, calc::Operation::plus, 2), 5.0);
    }


    void subtractionTest()
    {
        QCOMPARE(calc::calculate(3, calc::Operation::minus, 2), 1.0);
    }


    void multiplicationTest()
    {
        QCOMPARE(calc::calculate(3, calc::Operation::multiply, 2), 6.0);
    }


    void divisionTest()
    {
        QCOMPARE(calc::calculate(3, calc::Operation::divide, 2), 1.5);
    }


    void divisionByZeroTest()
    {
        QVERIFY_EXCEPTION_THROWN(calc::calculate(3, calc::Operation::divide, 0), calc::DivisionByZero);
    }
};
