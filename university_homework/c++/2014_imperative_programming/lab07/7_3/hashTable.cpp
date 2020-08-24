#include "ershovString.h"
#include "stringList.h"
#include "hashTable.h"
using namespace stringList;
using std::endl;


void update(List **hashArray, String *string)
{
    hashType wordHash = hash(string);
    if (hashArray[wordHash] == nullptr)
        hashArray[wordHash] = createList();
    ListElement *element = elementByString(string, hashArray[wordHash]);
    if (element == nullptr)
        appendLeft(string, hashArray[wordHash]);
    else
        amount(element)++;
}

void deleteContents(List **hashArray)
{
    for (int i = 0; i < maxHashSize; i++)
        if (hashArray[i] != nullptr)
            deleteList(hashArray[i]);
}


int stringOccurences(List **hashArray, String *string)
{
    hashType wordHash = hash(string);
    if (hashArray[wordHash] == nullptr)
        return 0;
    ListElement *element = elementByString(string, hashArray[wordHash]);
    if (element == nullptr)
        return 0;
    return amount(element);
}


void printAnalysis(std::ostream &file, List **hashArray)
{    
    file << "Word - number of occurences:" << endl;
    int listAmount = 0;
    List *longestList = nullptr;
    int longestListLen = 0;
    int listLenSum = 0;
    for (int i = 0; i < maxHashSize; i++)
        if (hashArray[i] != nullptr)
        {
            listAmount++;
            printWholeList(file, hashArray[i]);
            if (len(hashArray[i]) > longestListLen)
            {
                longestList = hashArray[i];
                longestListLen = len(longestList);
            }
            listLenSum += len(hashArray[i]);
        }
    file << endl << "Load factor: " << (double)listAmount / maxHashSize << endl;
    file << "Number of empty cells: " << maxHashSize - listAmount << " / " << maxHashSize;
    file << "\n\n" << "The longest chain (" << longestListLen << " words):" << endl;
    printOnlyStrings(file, longestList);
    file << endl << "Average chain length: " << (double)listLenSum / listAmount << endl;
    file << "Unique words number: " << listLenSum << endl;
}
