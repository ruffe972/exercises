#include "computer.h"

bool Computer::isInfected() const
{
    return isInfected_;
}

void Computer::maybeBecomeInfected()
{
    double temp_randomNumber = randomNumber;
    if (temp_randomNumber == trulyRandom)
        temp_randomNumber = (double) qrand() / RAND_MAX;
    if (temp_randomNumber < infectionProbabilty)
        isInfected_ = true;
}

bool Computer::hasInfectedNeighboors() const
{
    return hasInfectedNeighboors_;
}

void Computer::setHasInfectedNeighboors()
{
    hasInfectedNeighboors_ = true;
}

const double Computer::trulyRandom = -1;

double Computer::randomNumber = Computer::trulyRandom;
