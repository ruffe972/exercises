#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "unique_list.h"


class UniqueListTest : public QObject
{
    Q_OBJECT
public:
    explicit UniqueListTest(QObject *parent = 0) : QObject(parent) {}
private slots:


    void singleAppendingTest()
    {
        UniqueList<int> list;
        list.append(1);
        QCOMPARE(list.len(), 1);
        QCOMPARE(list.popleft(), 1);
    }


    void duplicateAppendingSimpleTest()
    {
        UniqueList<int> list;
        list.append(1);
        QVERIFY_EXCEPTION_THROWN(list.append(1), UniqueList<int>::DuplicateElementError);
    }


    void noExceptionsAppendingTest()
    {
        UniqueList<int> list;
        list.append(0);
        list.append(1);
        list.append(2);
        QCOMPARE(list.len(), 3);
        QCOMPARE(list.popleft(), 0);
        QCOMPARE(list.popleft(), 1);
        QCOMPARE(list.popleft(), 2);
    }


    void almostFinalAppendingTest()
    {
        UniqueList<int> list;
        list.append(0);
        list.append(1);
        QVERIFY_EXCEPTION_THROWN(list.append(1), UniqueList<int>::DuplicateElementError);
    }


    void finalAppendingTest()
    {
        UniqueList<int> list;
        list.append(0);
        list.append(1);
        QVERIFY_EXCEPTION_THROWN(list.append(0), UniqueList<int>::DuplicateElementError);
    }


    void emptyListRemovalTest()
    {
        UniqueList<int> list;
        QVERIFY_EXCEPTION_THROWN(list.remove(0), UniqueList<int>::NoElementError);
    }


    void simpleSingleSuccessfulRemovalTest()
    {
        UniqueList<int> list;
        list.append(1);
        list.remove(1);
        QCOMPARE(list.len(), 0);
    }


    void singleSuccessfulRemovalTest()
    {
        UniqueList<int> list;
        list.append(1);
        list.append(2);
        list.append(3);
        list.remove(2);
        QCOMPARE(list.len(), 2);
        QCOMPARE(list.popleft(), 1);
        QCOMPARE(list.popleft(), 3);
    }


    void unsuccessfulRemovalTest()
    {
        UniqueList<int> list;
        list.append(1);
        list.append(3);
        QVERIFY_EXCEPTION_THROWN(list.remove(2), UniqueList<int>::NoElementError);
    }
};


QTEST_MAIN(UniqueListTest)
