#include <iostream>
#include <fstream>
#include <cstring>
#include "standard.h"
using std::cout;


void debug()
{
    cout << '~';
}


char *readFileName(const char *defaultName)
{
    const int maxFileNameLen = 256;
    char *fileName = new char[maxFileNameLen];
    std::cin.getline(fileName, maxFileNameLen);
    using std::endl;
    if (strlen(fileName) == 0)
    {
        cout << defaultName << endl;
        strcpy(fileName, defaultName);
    }
    cout << endl;
    return fileName;
}


bool fileIsEqualToString(const char *fileName, const char *string)
{
    std::ifstream file(fileName);
    file.seekg(0, std::ios::end);
    int fileLen = (int)file.tellg() - 1;
    file.seekg(0, std::ios::beg);
    auto fileString = new char[fileLen + 1];
    fileString[fileLen] = '\0';
    file.read(fileString, fileLen);
    file.close();
    bool result = strcmp(fileString, string) == 0;
    delete[] fileString;
    return result;
}
