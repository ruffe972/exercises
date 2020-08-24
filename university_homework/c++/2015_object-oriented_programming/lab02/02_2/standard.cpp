#include <iostream>
#include <cstring>
#include "standard.h"
using std::cin;
using std::cout;


void debug()
{
    cout << '~';
}


int min(int a, int b)
{
    return a < b ? a : b;
}


int max(int a, int b)
{
    return a < b ? b : a;
}


char *readFileName(const char *defaultName)
{
    const int maxFileNameLen = 256;
    char *fileName = new char[maxFileNameLen];
    cin.getline(fileName, maxFileNameLen);
    if (strlen(fileName) == 0)
    {
        cout << defaultName << '\n';
        strcpy(fileName, defaultName);
    }
    cout << '\n';
    return fileName;
}
