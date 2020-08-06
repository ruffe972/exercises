#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "linked_stack.h"


class LinkedStackTest : public QObject
{
    Q_OBJECT
public:
    explicit LinkedStackTest(QObject *parent = 0) : QObject(parent) {}
private:
    LinkedStack<int> *testStack;
private slots:

    void init()
    {
        testStack = new LinkedStack<int>;
    }


    void cleanup()
    {
        delete testStack;
    }


    void simpleTest()
    {
        QCOMPARE(0, testStack->len());
        testStack->push(-101);
        QCOMPARE(1, testStack->len());
        QCOMPARE(-101, testStack->pop());
        QCOMPARE(0, testStack->len());

        testStack->push(10);
        testStack->push(20);
        QCOMPARE(2, testStack->len());
        testStack->push(30);
        QCOMPARE(3, testStack->len());
        QCOMPARE(30, testStack->pop());
        testStack->push(40);
        QCOMPARE(40, testStack->pop());
        QCOMPARE(20, testStack->pop());
        QCOMPARE(10, testStack->pop());
        QCOMPARE(0, testStack->len());
    }


    void stressTest()
    {
        const int uberNumber = 100000;
        for (int i = 0; i < uberNumber; i++)
        {
            testStack->push(i);
            QCOMPARE(i, testStack->pop());
            QVERIFY(testStack->len() == 0);
        }

        for (int i = 0; i < uberNumber; i++)
            testStack->push(i);
        QCOMPARE(testStack->len(), uberNumber);
        int last = uberNumber - 1;
        for (int i = 0; i < uberNumber; i++)
            QCOMPARE(last--, testStack->pop());
        QCOMPARE(0, testStack->len());
    }
};
