#pragma once
#include <QObject>
#include <QtTest/QtTest>
#include <QDebug>
#include "network.h"
#include "computercreator.h"

class NetworkTest : public QObject
{
    Q_OBJECT
public:
    explicit NetworkTest(QObject *parent = 0) : QObject(parent) {}
private slots:

    void test1()
    {
        Network network;
        network.setSizeForNewNetwork(2);
        network.computers[0] = ComputerCreator::createLinuxComputer(true);
        network.computers[1] = ComputerCreator::createWindowsComputer();
        network.neighbors[1] = {0};
        double probability = network.computers[1]->infectionProbabilty;

        Computer::randomNumber = probability + 0.01;
        network.change();
        QVERIFY(!network.computers[1]->isInfected());

        Computer::randomNumber = probability - 0.01;
        network.change();
        QVERIFY(network.computers[1]->isInfected());
    }

    void test2()
    {
        int numberOfComputers = 6;
        Network network;
        network.setSizeForNewNetwork(numberOfComputers);
        network.neighbors[0] = {1};
        network.neighbors[1] = {2};
        network.neighbors[2] = {3, 4};
        network.neighbors[3] = {4};
        network.neighbors[4] = {5};
        network.computers[0] = ComputerCreator::createLinuxComputer();
        network.computers[1] = ComputerCreator::createWindowsComputer();
        network.computers[2] = ComputerCreator::createLinuxComputer();
        network.computers[3] = ComputerCreator::createWindowsComputer(true);
        network.computers[4] = ComputerCreator::createWindowsComputer();
        network.computers[5] = ComputerCreator::createWindowsComputer();
        double eps = network.computers[0]->infectionProbabilty / 10000;
        double probabilityA = network.computers[0]->infectionProbabilty - eps;
        double probabilityB = probabilityA + 2 * eps;

        Computer::randomNumber = 1;
        network.change();
        QVERIFY(!network.computers[2]->isInfected());
        QVERIFY(!network.computers[4]->isInfected());

        Computer::randomNumber = probabilityB;
        network.change();
        QVERIFY(!network.computers[2]->isInfected());
        QVERIFY(network.computers[4]->isInfected());

        Computer::randomNumber = probabilityA;
        network.change();
        QVERIFY(network.computers[2]->isInfected());
        QVERIFY(network.computers[5]->isInfected());

        Computer::randomNumber = 1;
        network.change();
        QVERIFY(!network.computers[1]->isInfected());

        Computer::randomNumber = probabilityB;
        network.change();
        QVERIFY(network.computers[1]->isInfected());

        network.change();
        QVERIFY(!network.computers[0]->isInfected());

        Computer::randomNumber = probabilityA;
        network.change();
        QVERIFY(network.computers[0]->isInfected());
    }

    void cleanupTestCase()
    {
        Computer::randomNumber = Computer::trulyRandom;
    }

};
