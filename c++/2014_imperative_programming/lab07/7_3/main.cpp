#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include "standard.h"
#include "ershovString.h"
#include "stringList.h"
#include "hashTable.h"
using std::cout;
using std::endl;


void skipToWord(std::ifstream &file)
{
    char character = ' ';
    while (character != EOF && !isalpha(character))
        character = file.get();
    if (character != EOF)
        file.unget();
}


int main()
{
    std::ifstream inputFile;
    cout << "Enter the input file name: ";
    char *inputFileName = scanFileName("text.txt");
    inputFile.open(inputFileName);
    delete[] inputFileName;

    String *word = createString();
    skipToWord(inputFile);
    List *hashArray[maxHashSize] = {nullptr};
    while (scan(inputFile, word))
    {
        while (!isalpha(charAt(word, len(word) - 1)))
            len(word)--;
        charAt(word, 0) = tolower(charAt(word, 0));
        update(hashArray, word);
        deleteString(word);
        word = createString();
        skipToWord(inputFile);
    }
    deleteString(word);
    inputFile.close();

    std::ofstream outputFile;
    cout << "Enter the file name for the word occurency statistics: ";
    char *outputFileName = scanFileName("word analysis.txt");
    outputFile.open(outputFileName);
    printAnalysis(outputFile, hashArray);
    outputFile.close();
    delete[] outputFileName;
    deleteContents(hashArray);
    return 0;
}
