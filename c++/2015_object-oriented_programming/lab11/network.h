#pragma once
#include <QObject>
#include <QVector>
#include "computer.h"

/// self-expl-y
class Network : public QObject
{
    Q_OBJECT
public:
    friend class NetworkTest;
    friend class InputOutput;
    explicit Network(QObject *parent = 0);
    ~Network();
public slots:
    /// simulate one step
    void change();
signals:
    /// emitted after the change()
    void changed();
private:
    void setSizeForNewNetwork(int computersNumber);
    QVector<QVector<int>> neighbors;
    QVector<int> infectedNow;
    QVector<Computer*> computers;
    bool neverChangedAndResized;
};
