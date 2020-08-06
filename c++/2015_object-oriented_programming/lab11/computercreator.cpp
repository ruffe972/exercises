#include "computercreator.h"

Computer *ComputerCreator::createWindowsComputer(bool isInfected)
{
    return new WindowsComputer(isInfected);
}

Computer *ComputerCreator::createLinuxComputer(bool isInfected)
{
    return new LinuxComputer(isInfected);
}
