#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "vector.h"


class VectorTest : public QObject
{
    Q_OBJECT
public:
    explicit VectorTest(QObject *parent = 0) : QObject(parent) {}
private slots:


    void NoInitializationListAndNullTest()
    {
        Vector<int, 2> vector;
        QCOMPARE(vector.data[0], 0);
        QCOMPARE(vector.data[1], 0);
        QVERIFY(vector.isNull());
    }


    void smallerInitializationListAndNullTest()
    {
        Vector<int, 3> vector({8, 9});
        QCOMPARE(vector.data[0], 8);
        QCOMPARE(vector.data[1], 9);
        QCOMPARE(vector.data[2], 0);
        QVERIFY(!vector.isNull());
    }


    void largerInitializationList()
    {
        //QVERIFY_EXCEPTION_THROWN doesn't work here
        bool testPassed = false;
        try
        {
            Vector<int, 2> vector({1, 2, 3});
            vector.isNull(); // Prevents compiler warning
        }
        catch(Vector<int, 2>::TooManyArgsInInitList)
        {
            testPassed = true;
        }
        QVERIFY(testPassed);
    }


    void nullTest()
    {
        Vector<float, 1> vector({0});
        QVERIFY(vector.isNull());
    }


    void sizeTest()
    {
        //QVERIFY_EXCEPTION_THROWN doesn't work here
        bool testPassed = false;
        try
        {
            Vector<int, 0> vector;
            vector.isNull(); // Prevents compiler warning
        }
        catch(Vector<int, 0>::InvalidVectorSize)
        {
            testPassed = true;
        }
        QVERIFY(testPassed);
    }


    void copyTest()
    {
        Vector<bool, 1> trueVector({true});
        auto falseVector(trueVector);
        falseVector.data[0] = false;
        QCOMPARE(trueVector.data[0], true);
    }


    void additionTest()
    {
        Vector<int, 2> vector1({1, 1});
        Vector<int, 2> vector2({2, 2});
        Vector<int, 2> vector3(vector1 + vector2);
        QCOMPARE(vector3.data[1], 3);
        QCOMPARE(vector2.data[1], 2);
        QCOMPARE(vector1.data[1], 1);
    }


    void substractionTest()
    {
        Vector<int, 2> vector1({1, 2});
        Vector<int, 2> vector2({2, 3});
        Vector<int, 2> vector3(vector1 - vector2);
        QCOMPARE(vector3.data[0], -1);
        QCOMPARE(vector3.data[1], -1);
    }


    void dotProductTest()
    {
        Vector<int, 3> vector1({1, 2, 3});
        Vector<int, 3> vector2({3, 2, 0});
        QCOMPARE(vector1.dotProduct(vector2), 7);
    }
};


QTEST_MAIN(VectorTest)
