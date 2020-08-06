#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "set.h"


class SetTest : public QObject
{
    Q_OBJECT
public:
    explicit SetTest(QObject *parent = 0) : QObject(parent) {}
private slots:


    void emptySetBasicTest()
    {
        Set<int> set;
        QCOMPARE(set.size(), 0);
        QVERIFY(!set.exists(0));
        set.remove(0);
        QCOMPARE(set.size(), 0);      
    }


    void emptySetIntersectionTest()
    {
        Set<int> set;
        Set<int> anotherUselessSet;
        set.intersect(anotherUselessSet);
        QCOMPARE(set.size(), 0);
        QCOMPARE(anotherUselessSet.size(), 0);
    }


    void emptySetUnionTest()
    {
        Set<int> set;
        Set<int> anotherUselessSet;
        set.unite(anotherUselessSet);
        QCOMPARE(set.size(), 0);
        QCOMPARE(anotherUselessSet.size(), 0);
    }


    void additionTest()
    {
        Set<int> set;
        int x = 1;
        set.add(x);
        QCOMPARE(set.size(), 1);
        x = 3;
        QVERIFY(set.exists(1) && !set.exists(3));
        set.add(x);
        QCOMPARE(set.size(), 2);
        QVERIFY(set.exists(1) && set.exists(3));
        set.add(2);
        QCOMPARE(set.size(), 3);
        QVERIFY(set.exists(1) && set.exists(2) && set.exists(3));
    }


    void singleRemovalTest()
    {
        Set<int> set;
        set.add(0);
        set.remove(1);
        QVERIFY(set.exists(0));
        set.remove(0);
        QCOMPARE(set.size(), 0);
    }


    void removalTest()
    {
        Set<int> set;
        for (int i = 0; i < 1000; i++)
        {
            set.add(i);
        }
        set.remove(0);
        QCOMPARE(set.size(), 999);
        QVERIFY(!set.exists(0));
        for (int i = 999; i > 3; i--)
        {
            QCOMPARE(set.size(), i);
            set.remove(i);
        }
        for (int i = 4; i < 1000; i++)
        {
            QVERIFY(!set.exists(i));
        }
        set.remove(2);
        QVERIFY(!set.exists(2));
        QCOMPARE(set.size(), 2);
    }


    void emptyIntersectionTest()
    {
        Set<QString> set;
        set.add("");
        Set<QString> anotherSet;
        anotherSet.add("123");
        set.intersect(anotherSet);
        QCOMPARE(set.size(), 0);
    }


    void intersectionTest()
    {
        Set<int> firstSet;
        firstSet.add(5);
        firstSet.add(1);
        firstSet.add(3);
        Set <int> secondSet;
        secondSet.add(3);
        secondSet.add(2);
        secondSet.add(6);

        firstSet.intersect(secondSet);
        secondSet.remove(3);
        QCOMPARE(firstSet.size(), 1);
        QVERIFY(firstSet.exists(3));
    }


    void unionTest()
    {
        Set<double> firstSet;
        firstSet.add(1);
        firstSet.add(2);
        firstSet.add(3);
        Set<double> secondSet;
        secondSet.add(2);
        secondSet.add(3);
        secondSet.add(4);

        firstSet.unite(secondSet);
        QCOMPARE(firstSet.size(), 4);
        secondSet.remove(2);
        secondSet.add(2.5);
        QVERIFY(firstSet.exists(1) && firstSet.exists(2) && firstSet.exists(3) && firstSet.exists(4));
    }
};


QTEST_MAIN(SetTest)
