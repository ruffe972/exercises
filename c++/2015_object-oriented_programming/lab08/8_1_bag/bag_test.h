#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <sstream>
#include "bag.h"

class BagTest : public QObject
{
    Q_OBJECT
public:
    explicit BagTest(QObject *parent = 0) : QObject(parent) {}
private:

    void verifyOutputEqualsString(const std::string &string)
    {
        output.str("");
        bag.printAscending(output);
        QVERIFY(output.str() == string);
    }

    Bag<int> bag;
    std::stringstream output;
private slots:

    void emptyBagTest()
    {
        bag.printAscending(output);
        QVERIFY(output.str() == "");
        QVERIFY(!bag.exists(0));
        QVERIFY(bag.empty());
        bag.remove(0);
        QVERIFY(bag.empty());
    }

    void singleNodeTest()
    {
        bag.add(0);
        bag.printAscending(output);
        QVERIFY(bag.exists(0));
        bag.add(0);
        bag.printAscending(output);
        QVERIFY(output.str() == "0 0 0 ");
        bag.remove(0);
        QVERIFY(!bag.empty());
        bag.remove(0);
        QVERIFY(bag.empty());
    }

    void insertionTest()
    {
        bag.add(20);
        verifyOutputEqualsString("20 ");
        bag.add(4);
        verifyOutputEqualsString("4 20 ");
        bag.add(26);
        verifyOutputEqualsString("4 20 26 ");
        bag.add(3);
        verifyOutputEqualsString("3 4 20 26 ");
        bag.add(9);
        verifyOutputEqualsString("3 4 9 20 26 ");

        bag.add(4);
        verifyOutputEqualsString("3 4 4 9 20 26 ");
        bag.add(9);
        verifyOutputEqualsString("3 4 4 9 9 20 26 ");
        bag.add(20);
        verifyOutputEqualsString("3 4 4 9 9 20 20 26 ");
        bag.add(3);
        bag.add(3);
        verifyOutputEqualsString("3 3 3 4 4 9 9 20 20 26 ");
        bag.add(15);
        verifyOutputEqualsString("3 3 3 4 4 9 9 15 20 20 26 ");
    }

    void insertionAndExistanceCheckTest()
    {
        bag.add(20);
        bag.add(4);
        bag.add(26);
        bag.add(3);
        bag.add(9);
        bag.add(26);
        verifyOutputEqualsString("3 4 9 20 26 26 ");
        bag.add(8);
        verifyOutputEqualsString("3 4 8 9 20 26 26 ");
        QVERIFY(bag.exists(3));
        QVERIFY(bag.exists(4));
        QVERIFY(bag.exists(8));
        QVERIFY(bag.exists(9));
        QVERIFY(bag.exists(20));
        QVERIFY(bag.exists(26));
    }

    void removalTest1()
    {
        bag.add(2);
        bag.add(3);
        bag.add(1);
        bag.add(1);
        bag.remove(2);
        verifyOutputEqualsString("1 1 3 ");
    }

    void removalTest2()
    {
        bag.add(2);
        bag.add(0);
        bag.add(3);
        bag.add(1);
        bag.add(1);
        bag.remove(2);
        verifyOutputEqualsString("0 1 1 3 ");
    }

    void removalTest3()
    {
        bag.add(2);
        bag.add(1);
        bag.add(4);
        bag.add(3);
        bag.add(5);

        bag.add(1);
        bag.remove(1);
        bag.add(1);
        bag.remove(1);
        verifyOutputEqualsString("1 2 3 4 5 ");

        bag.remove(1);
        verifyOutputEqualsString("2 3 4 5 ");
        bag.remove(4);
        verifyOutputEqualsString("2 3 5 ");
        bag.remove(3);
        verifyOutputEqualsString("2 5 ");
        bag.remove(2);
        verifyOutputEqualsString("5 ");
        bag.remove(5);
        verifyOutputEqualsString("");
    }


    void stressTest()
    {
        for (int i = 1; i < 100; i++)
            for (int j = 0; j < i; j++)
                bag.add(i);
        for (int i = 1; i < 100; i++)
        {
            QVERIFY(bag.exists(i));
            for (int j = 0; j < i - 1; j++)
                bag.remove(i);
            QVERIFY(bag.exists(i));
            bag.remove(i);
            QVERIFY(!bag.exists(i));
        }
        QVERIFY(bag.empty());
    }

    void stringBagTest()
    {
        Bag<std::string> bag;
        bag.add("ab");
        bag.add("ba");
        bag.add("abc");
        bag.add("acb");
        bag.add("bac");
        bag.add("bca");

        bag.add("ab");
        bag.add("ba");
        bag.remove("bac");
        output.str("");
        bag.printAscending(output);
        QVERIFY(output.str() == "ab ab abc acb ba ba bca ");
    }

    void cleanup()
    {
        bag.clear();
        QVERIFY(bag.empty());
    }
};

QTEST_MAIN(BagTest)
