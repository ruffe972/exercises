#include "network.h"
#include <iostream>

Network::Network(QObject *parent) :
    QObject(parent),
    neverChangedAndResized(false)
{}

Network::~Network()
{
    for (auto computer: computers)
    {
        if (computer)
            delete computer;
    }
}

void Network::setSizeForNewNetwork(int computersNumber)
{
    neverChangedAndResized = true;
    for (int i = 0; i < computersNumber; i++)
    {
        neighbors << QVector<int>();
        computers << nullptr;
    }
}

void Network::change()
{
    if (neverChangedAndResized)
    {
        for (int i = 0; i < computers.length(); i++)
        {
            for (auto neighborIndex: neighbors[i])
            {
                if (!neighbors[neighborIndex].contains(i))
                    neighbors[neighborIndex].append(i);
            }
            if (computers[i]->isInfected())
                infectedNow << i;
        }
        neverChangedAndResized = false;
    }

    for (auto infectedComputerIndex: infectedNow)
    {
        for (auto i: neighbors[infectedComputerIndex])
            computers[i]->setHasInfectedNeighboors();
    }
    infectedNow.clear();

    for (int i = 0; i < computers.length(); i++)
    {
        if (!computers[i]->isInfected() && computers[i]->hasInfectedNeighboors())
        {
            computers[i]->maybeBecomeInfected();
            if (computers[i]->isInfected())
                infectedNow << i;
        }
    }
    emit changed();
}
