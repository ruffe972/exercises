#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "sorted_set.h"
#include "singly_linked_list.h"


class SortedSetTest : public QObject
{
    Q_OBJECT
public:
    explicit SortedSetTest(QObject *parent = 0) : QObject(parent) {}
private:
    SortedSet *set;
private slots:

    void init()
    {
        set = new SortedSet;
    }


    void minimalisticTest()
    {
        QCOMPARE(set->len(), 0);
        auto list = new SinglyLinkedList<int>;
        set->remove(list);
        QCOMPARE(set->len(), 0);
        set->add(list);
        QCOMPARE(set->len(), 1);
        set->remove(list);
        QCOMPARE(set->len(), 0);
    }


    void correctLengthTest()
    {
//        add [1.5, 2.5]
//        add [1, 3]
//        add [-1, -1, -1, -1]
//        add [0]
//        remove [0, 0]
//        add [51]
//        remove [777]
//        remove [0, 0, 0, 0]

        auto listOfDoubles = new SinglyLinkedList<double>;
        listOfDoubles->append(1.5);
        listOfDoubles->append(2.5);
        set->add(listOfDoubles);
        QCOMPARE(set->len(), 1);

        auto list = new SinglyLinkedList<int>;
        list->append(1);
        list->append(3);
        set->add(list);
        QCOMPARE(set->len(), 1);

        list = new SinglyLinkedList<int>;
        for (int i = 0; i < 4; i++)
            list->append(-1);
        set->add(list);
        QCOMPARE(set->len(), 2);

        list = new SinglyLinkedList<int>;
        list->append(0);
        set->add(list);
        QCOMPARE(set->len(), 3);

        list = new SinglyLinkedList<int>;
        list->append(0);
        list->append(0);
        set->remove(list);
        delete list;
        QCOMPARE(set->len(), 2);

        list = new SinglyLinkedList<int>;
        list->append(51);
        set->add(list);
        QCOMPARE(set->len(), 2);

        list = new SinglyLinkedList<int>;
        list->append(777);
        set->remove(list);
        delete list;
        QCOMPARE(set->len(), 1);

        list = new SinglyLinkedList<int>;
        for (int i = 0; i < 4; i++)
            list->append(0);
        set->remove(list);
        delete list;
        QCOMPARE(set->len(), 0);
    }


    void cleanup()
    {
        delete set;
    }
};
