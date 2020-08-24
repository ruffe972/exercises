#include <iostream>
#include <cstring>
#include "standard.h"


std::string readFileName(const char *defaultName)
{
    std::string result;
    std::getline(std::cin, result);
    if (result.empty())
    {
        return std::string(defaultName);
    }
    return result;
}
