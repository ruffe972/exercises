#pragma once
#include <sstream>
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "expression.h"


class ExpressionTest : public QObject
{
    Q_OBJECT
public:
    explicit ExpressionTest(QObject *parent = 0) : QObject(parent) {}
private slots:


    void emptyExpressionTest()
    {
        Expression expression;
        QVERIFY_EXCEPTION_THROWN(expression.calculate(), Expression::EmptyExpressionError);
    }


    void singleOperandTest()
    {
        Expression expression;
        std::istringstream input("012");
        expression.read(input);
        QCOMPARE(expression.calculate(), 12.0);
    }


    void singleOperationTest()
    {
        Expression expression;
        std::istringstream input("(/ 1 4)");
        expression.read(input);
        QCOMPARE(expression.calculate(), 0.25);
    }


    void finalTest()
    {
        Expression expression;
        std::istringstream input("(/ (- 1 (+ (* 2 2) 7)) 4)");
        expression.read(input);
        QCOMPARE(expression.calculate(), -2.5);
    }
};
