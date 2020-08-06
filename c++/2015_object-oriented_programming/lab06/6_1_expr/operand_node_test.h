#pragma once
#include <sstream>
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "operand_node.h"


class OperandNodeTest : public QObject
{
    Q_OBJECT
public:
    explicit OperandNodeTest(QObject *parent = 0) : QObject(parent) {}
private slots:


    void emptyOperandTest()
    {
        OperandNode operand;
        QCOMPARE(operand.calculate(), 0.);
    }


    void test()
    {
        OperandNode operand;
        std::istringstream input("0123");
        operand.read(input);
        QCOMPARE(operand.calculate(), 123.0);
    }
};
