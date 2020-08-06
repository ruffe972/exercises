#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <stack>
#include "shared_pointer.h"


class SharedPointerTest : public QObject
{
    Q_OBJECT
public:
    explicit SharedPointerTest(QObject *parent = 0) : QObject(parent) {}
private slots:


    void singleNullPointerTest()
    {
        SharedPointer<int> pointer;
        QCOMPARE(pointer.usageCounter(), 0);
        QVERIFY_EXCEPTION_THROWN(*pointer, SharedPointer<int>::EmptyPointerDereferenceException);
        pointer = pointer;
        QCOMPARE(pointer.usageCounter(), 0);
    }


    void nullPointerTest()
    {
        SharedPointer<int> pointer1;
        auto pointer2(pointer1);
        auto pointer3 = pointer2;
        QCOMPARE(pointer1.usageCounter(), 0);
        QCOMPARE(pointer2.usageCounter(), 0);
        QCOMPARE(pointer3.usageCounter(), 0);
    }


    void singlePointerBasicTest()
    {
        SharedPointer<int> number(new int(9));
        QCOMPARE(number.usageCounter(), 1);
        QCOMPARE(*number, 9);
        *number = 8;
        QCOMPARE(*number, 8);
    }


    void copyConstructorTest()
    {
        SharedPointer<int> globalPointer(new int(6));
        {
            auto localPointer(globalPointer);
            QCOMPARE(localPointer.usageCounter(), 2);
            QCOMPARE(globalPointer.usageCounter(), 2);
        }
        QCOMPARE(globalPointer.usageCounter(), 1);
        QCOMPARE(*globalPointer, 6);
    }


    void selfAssignmentTest()
    {
        SharedPointer<bool> pointer(new bool(true));
        pointer = pointer;
        QCOMPARE(pointer.usageCounter(), 1);
    }


    void sameObjectAssignmentTest()
    {
        SharedPointer<int> pointer1(new int(4));
        auto pointer2(pointer1);
        pointer1 = pointer2;
        *pointer2 = 5;
        pointer1 = pointer1;
        QCOMPARE(pointer1.usageCounter(), 2);
        QCOMPARE(*pointer2, 5);
    }


    void finalTest()
    {
        SharedPointer<int> pointer1(new int(8));
        auto pointer2(pointer1);
        {
            auto pointer3 = pointer1;
            pointer1 = SharedPointer<int>(new int(4));
            QCOMPARE(*pointer3, 8);
            QCOMPARE(pointer1.usageCounter(), 1);
            QCOMPARE(*pointer1, 4);
            QCOMPARE(pointer2.usageCounter(), 2);
            QCOMPARE(*pointer2, 8);
            QCOMPARE(pointer3.usageCounter(), 2);
            QCOMPARE(*pointer3, 8);
        }
        QCOMPARE(pointer2.usageCounter(), 1);
    }


    void example1()
    {
        // Let's pretend that bool is some super complex type in this example
        std::stack<SharedPointer<bool>> stack;
        stack.push(new bool(true));
        auto element = stack.top();
        *element = false;
        QCOMPARE(*stack.top(), false);

        stack.push(element);
        QCOMPARE(element.usageCounter(), 3);
        QCOMPARE(*stack.top(), false);
        stack.pop();

        QCOMPARE(element.usageCounter(), 2);
        QCOMPARE(*stack.top(), false);
        stack.pop();

        QCOMPARE(element.usageCounter(), 1);
    }


    void example2()
    {
         SharedPointer<double> number1(new double(4.4));
         SharedPointer<double> number2 = new double(2.2);
         SharedPointer<double> minimum;
         if (*number1 < *number2)
             minimum = number1;
         else
             minimum = number2;
         *minimum /= 2;
         QCOMPARE(*number2, 1.1);
    }
};


QTEST_MAIN(SharedPointerTest)
