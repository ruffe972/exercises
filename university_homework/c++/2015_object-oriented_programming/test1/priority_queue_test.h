#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <string>
#include "priority_queue.h"


class PriorityQueueTest : public QObject
{
    Q_OBJECT
public:
    explicit PriorityQueueTest(QObject *parent = 0) : QObject(parent) {}
private slots:
    //no emptyQueueTest, it's ok for now
    void OneEnqueueOneDequeueIntTest()
    {
        PriorityQueue<int> queue;
        queue.enqueue(4, 3);
        QCOMPARE(queue.dequeue(), 4);
    }


    void OneEnqueueOneDequeueStringTest()
    {
        using std::string;
        PriorityQueue<string> queue;
        string orange = "orange";
        queue.enqueue(orange, 1);
        QCOMPARE(queue.dequeue().compare(orange), 0);
    }


    void doubleTest()
    {
        PriorityQueue<double> queue;
        queue.enqueue(3.5, 0);
        queue.enqueue(1.5, -1);
        queue.enqueue(2.5, -1);
        queue.enqueue(4.5, 1);
        queue.enqueue(5.5, 1);
        double value = queue.dequeue();
        QVERIFY(value == 5.5 || value == 4.5);
        value = queue.dequeue();
        QVERIFY(value == 5.5 || value == 4.5);
        QCOMPARE(queue.dequeue(), 3.5);
        value = queue.dequeue();
        QVERIFY(value == 1.5 || value == 2.5);
        value = queue.dequeue();
        QVERIFY(value == 1.5 || value == 2.5);
    }
};
