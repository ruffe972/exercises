#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "hashtable.h"
#include "hashfunctions.h"


class HashTableTest : public QObject
{
    Q_OBJECT
public:
    explicit HashTableTest(QObject *parent = 0) : QObject(parent) {}
private slots:
    void emptyTableTest()
    {
        HashTable table;
        QVERIFY(!table.find("dog"));
        std::string wow = "wow";
        QVERIFY(!table.find(wow));
        table.remove(wow);
        table.remove("dog");
    }


    void additionTest()
    {
        HashTable table;
        std::string string = "summer";
        table.add(string);
        QVERIFY(table.find("summer"));
        string = "winter";
        QVERIFY(table.find("summer"));
        table.add(string);
        QVERIFY(table.find("winter"));
    }


    void bigStringTest()
    {
        HashTable table;
        std::string string;
        for (int i = 0; i < 1000; i++)
            string.push_back('a');
        table.add(string);
        QVERIFY(table.find(string));
        table.remove(string);
        QVERIFY(!table.find(string));
    }


    void finalTest()
    {
        HashTable table(sumHash);
        table.add("1aa");
        table.add("a1a");
        table.add("aa1");
        QVERIFY(table.find("1aa") && table.find("a1a") && table.find("aa1"));

        table.remove("a1a");
        QVERIFY(table.find("1aa") && !table.find("a1a") && table.find("aa1"));
        table.remove("1aa");
        QVERIFY(!table.find("1aa") && !table.find("a1a") && table.find("aa1"));
        table.remove("aa1");

        QVERIFY(!table.find("1aa") && !table.find("a1a") && !table.find("aa1"));
    }
};
