#pragma once
#include <QObject>
#include <QFile>
#include "network.h"

/// Network input from file and output to console
class InputOutput : public QObject
{
    Q_OBJECT
public:
    /// Impossible to create InputOutput instance with *network = nullptr
    class NullNetworkException {};

    explicit InputOutput(Network *network, QObject *parent = 0);

    /// read from file
    void readFromFile();
public slots:
    /// print the current state of the network to console
    void printStatus() const;
private:
    Network *network;
};
