#include <iostream>
#include <cstring>
#include "standard.h"
using std::cin;
using std::cout;
using std::endl;


void d()
{
    cout << '~';
}


void e()
{
    cout << endl;
}


void w()
{
    cin.ignore();
}


int min(int a, int b)
{
    return a < b ? a : b;
}


int max(int a, int b)
{
    return a < b ? b : a;
}


char *scanFileName(const char *defaultName)
{
    const int maxFileNameLen = 256;
    char *fileName = new char[maxFileNameLen];
    cin.getline(fileName, maxFileNameLen);
    if (strlen(fileName) == 0)
    {
        cout << defaultName << endl;
        strcpy(fileName, defaultName);
    }
    cout << endl;
    return fileName;
}
