#include "inputoutput.h"
#include <iostream>
#include <QString>
#include <QDebug>
#include "computercreator.h"

InputOutput::InputOutput(Network *network, QObject *parent) :
    QObject(parent),
    network(network)
{
    if (!network)
        throw NullNetworkException();
}

void InputOutput::readFromFile()
{
    QFile file("../02/input.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream inStream(&file);

    for (int i = 0; i < 3; i++)
        inStream.readLine();
    int computersNumber = inStream.readLine().toInt();
    network->setSizeForNewNetwork(computersNumber);
    QString line;
    for (int i = 0; i < 4; i++)
        line = inStream.readLine();
    while (!line.isEmpty())
    {
        QStringList stringList = line.split(" ");
        int from = stringList.at(0).toInt();
        int to = stringList.at(1).toInt();
        network->neighbors[from].append(to);
        line = inStream.readLine();
    }

    // read computers data
    for (int i = 0; i < 2; i++)
        inStream.readLine();
    for (int i = 0; i < computersNumber; i++)
    {
        QStringList stringList = inStream.readLine().split(" ", QString::SplitBehavior::SkipEmptyParts);
        int index = stringList.at(0).toInt();
        bool isInfected = stringList.at(1).toInt();
        //todo switch
        if (stringList.at(2) == "windows")
            network->computers[index] = ComputerCreator::createWindowsComputer(isInfected);
        else if (stringList.at(2) == "linux")
            network->computers[index] = ComputerCreator::createLinuxComputer(isInfected);
        else
        {
            std::cout << "Error: unknown OS.\n";
            exit(1);
        }
    }
}

void InputOutput::printStatus() const
{
    for (int i = 0; i < network->computers.length(); i++)
        std::cout << (network->computers[i]->isInfected() ? '#' : '_') << i << ' ';
    std::cout << '\n';
}
