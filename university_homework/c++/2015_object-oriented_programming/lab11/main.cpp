#include <QCoreApplication>
#include <QObject>
#include <QTime>
#include <QTimer>
#include <iostream>
#include "networktest.h"
#include "inputoutput.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    NetworkTest networkTest;
    if (QTest::qExec(&networkTest))
        return -1;

    QTimer timer;
    Network network;
    // not very random, only 1000 variants
    qsrand(QTime::currentTime().msec());
    InputOutput inputOutput(&network);
    inputOutput.readFromFile();
    std::cout << "\nOutput format: computer indeces, prepended with a special symbol.\n"
              << "'#' means infected computer, '_' is for healthy ones.\n"
              << "Press Enter to start simulation. Press ^C to exit.\n";
    inputOutput.printStatus();
    QObject::connect(&timer, &QTimer::timeout, &network, &Network::change);
    QObject::connect(&network, &Network::changed, &inputOutput, &InputOutput::printStatus);
    std::cin.get();
    timer.start(100);
    return a.exec();
}
