#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <fstream>
#include "standard.h"
#include "quick_sorter.h"


class QuickSorterTest : public QObject
{
    Q_OBJECT
public:
    explicit QuickSorterTest(QObject *parent = 0) : QObject(parent) {}
private:
    QuickSorter<int> *sorter;
private slots:


    void init()
    {
        sorter = new QuickSorter<int>;
    }


    void emptyVectorTest()
    {
        vector<int> testVector;
        sorter->sort(testVector);
        QCOMPARE(testVector.size(), (UInt)0);
    }


    void singleElementVectorTest()
    {
        const int someNumber = -3;
        vector<int> testVector = {someNumber};
        sorter->sort(testVector);
        QCOMPARE(testVector.size(), (UInt)1);
        QCOMPARE(testVector[0], someNumber);
    }


    void shortVectorTest()
    {
        vector<int> testVector = {0, -9, 5, 9, -17, -17, -1, 1, 2, 3, 9};
        vector<int> correctVector = {-17, -17, -9, -1, 0, 1, 2, 3, 5, 9, 9};
        sorter->sort(testVector);
        QCOMPARE(testVector, correctVector);
    }


    void largeReverseTest()
    {
        const int bigNumber = 10000;
        vector<int> testVector(bigNumber);
        int value = bigNumber - 1;
        for (int i = 0; i < bigNumber; i++)
            testVector[i] = value--;
        sorter->sort(testVector);
        for (int i = 0; i < bigNumber; i++)
            QCOMPARE(i, testVector[i]);
    }


    void cleanup()
    {
        delete sorter;
    }


};
