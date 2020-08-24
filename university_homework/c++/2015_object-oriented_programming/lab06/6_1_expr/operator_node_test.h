#pragma once
#include <sstream>
#include <memory>
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "operator_node.h"


class OperatorNodeTest : public QObject
{
    Q_OBJECT
public:
    explicit OperatorNodeTest(QObject *parent = 0) : QObject(parent) {}
private:
    std::unique_ptr<OperatorNode> operatorNode;
private slots:


    void initTestCase()
    {
        operatorNode.reset(new OperatorNode);
    }


    void emptyOperatorNodeTest()
    {
        QVERIFY_EXCEPTION_THROWN(operatorNode->calculate(), OperatorNode::NoOperandError);
    }


    void singleAdditionTest()
    {
        std::istringstream input("(+ 1 2)");
        operatorNode->read(input);
        QCOMPARE(operatorNode->calculate(), 3.0);
    }


    void singleSubtracktionTest()
    {
        std::istringstream input("(- 1 3)");
        operatorNode->read(input);
        QCOMPARE(operatorNode->calculate(), -2.0);
    }


    void singleMultiplicationTest()
    {
        std::istringstream input("(* 3 2)");
        operatorNode->read(input);
        QCOMPARE(operatorNode->calculate(), 6.0);
    }


    void singleDivisionTest()
    {
        std::istringstream input("(/ 1 2)");
        operatorNode->read(input);
        QCOMPARE(operatorNode->calculate(), 0.5);
    }


    void testWithDeapthTwoN1()
    {
        std::istringstream input("(/ (- 4 3) 2)");
        operatorNode->read(input);
        QCOMPARE(operatorNode->calculate(), 0.5);
    }


    void testWithDeapthTwoN2()
    {
        std::istringstream input("(/ 2 (- 4 3))");
        operatorNode->read(input);
        QCOMPARE(operatorNode->calculate(), 2.0);
    }


    void testWithDeapthTwoN3()
    {
        std::istringstream input("(/ (+ 2 6) (- 5 3))");
        operatorNode->read(input);
        QCOMPARE(operatorNode->calculate(), 4.0);
    }


    void finalTest()
    {
        std::istringstream input("(/ (- 1 (+ (* 2 2) 7)) 4)");
        operatorNode->read(input);
        QCOMPARE(operatorNode->calculate(), -2.5);
    }
};
