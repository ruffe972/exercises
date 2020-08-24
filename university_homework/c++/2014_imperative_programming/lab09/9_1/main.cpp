#include <iostream>
#include <fstream>
#include "ershovString.h"
#include "standard.h"
#include "hash.h"
using namespace stringList;
using std::cout;
using std::endl;


int main()
{
    cout << "Name of the first file: ";
    char *fileName = scanFileName("file1.txt");
    std::ifstream input1;
    input1.open(fileName);
    delete[] fileName;

    List *hashArray[maxHashSize] = {};
    String *line = createString();
    while (scanLine(input1, line))
    {
        if (len(line) != 0)
            update(hashArray, line);
        deleteString(line);
        line = createString();
    }
    deleteString(line);
    input1.close();

    cout << "Name of the second file: ";
    fileName = scanFileName("file2.txt");
    std::ifstream input2;
    input2.open(fileName);
    delete[] fileName;
    cout << "Name of the third file: ";
    fileName = scanFileName("file3.txt");
    std::ofstream output;
    output.open(fileName);
    delete[] fileName;

    line = createString();
    while (scanLine(input2, line))
    {
        if (len(line) != 0 && stringOccurences(hashArray, line) != 0)
        {
            print(output, line);
            output << endl;
        }
        deleteString(line);
        line = createString();
    }
    deleteString(line);

    deleteContents(hashArray);
    input2.close();
    output.close();
    return 0;
}
