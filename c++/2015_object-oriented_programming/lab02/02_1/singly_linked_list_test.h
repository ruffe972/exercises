#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "singly_linked_list.h"


class SinglyLinkedListTest : public QObject
{
    Q_OBJECT
public:
    explicit SinglyLinkedListTest(QObject *parent = 0) : QObject(parent) {}
private:
    SinglyLinkedList<int> *testList;
private slots:

    void init()
    {
        testList = new SinglyLinkedList<int>;
    }


    void cleanup()
    {
        delete testList;
    }


    void simpleTest()
    {
        QCOMPARE(0, testList->len());
        testList->append(-101);
        QCOMPARE(1, testList->len());
        QCOMPARE(-101, testList->popleft());
        QCOMPARE(0, testList->len());

        testList->append(10);
        testList->append(20);
        QCOMPARE(2, testList->len());
        testList->append(30);
        QCOMPARE(3, testList->len());
        QCOMPARE(10, testList->popleft());
        testList->append(40);
        QCOMPARE(20, testList->popleft());
        QCOMPARE(30, testList->popleft());
        QCOMPARE(40, testList->popleft());
        QCOMPARE(0, testList->len());
    }


    void stressTest()
    {
        const int uberNumber = 100000;
        for (int i = 0; i < uberNumber; i++)
        {
            testList->append(i);
            QCOMPARE(i, testList->popleft());
            QVERIFY(testList->len() == 0);
        }

        for (int i = 0; i < uberNumber; i++)
            testList->append(i);
        QCOMPARE(testList->len(), uberNumber);
        for (int i = 0; i < uberNumber; i++)
            QCOMPARE(i, testList->popleft());
        QCOMPARE(0, testList->len());
    }
};
