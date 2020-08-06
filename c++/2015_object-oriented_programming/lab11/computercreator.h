#pragma once
#include "windowscomputer.h"
#include "linuxcomputer.h"

/// Creates the concrete Computer objects for looser relations between classes
class ComputerCreator
{
public:
    static Computer *createWindowsComputer(bool isInfected = false);
    static Computer *createLinuxComputer(bool isInfected = false);
};
