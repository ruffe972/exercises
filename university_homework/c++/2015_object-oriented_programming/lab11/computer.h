#pragma once
#include <QtGlobal>
#include <QString>

/// Computer, a Network class graph node.
class Computer
{
public:
    friend class NetworkTest;
    virtual ~Computer() {}

    /// check if is infected by computer viruses
    bool isInfected() const;

    /// become infected if not lucky
    virtual void maybeBecomeInfected();

    //@{
    /// hasInfectedNeighbors flag helps in optimizing the network changing algorithm
    bool hasInfectedNeighboors() const;    
    void setHasInfectedNeighboors();
    //@}
protected:
    Computer(bool infected) : isInfected_(infected) {}
    double infectionProbabilty;
private:
    static const double trulyRandom;
    static double randomNumber;
    bool hasInfectedNeighboors_ = false;
    bool isInfected_;
};
