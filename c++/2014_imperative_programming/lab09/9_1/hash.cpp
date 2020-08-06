#include "ershovString.h"
#include "stringList.h"
#include "hash.h"
using namespace stringList;


hashType hash(String *string)
{
    hashType returnValue = 0;
    hashType power = 1;
    for (int i = len(string) - 1; i >= 0; i--)
    {
        returnValue += power * charAt(string, i);
        power *= hashBase;
    }
    return returnValue;
}


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
