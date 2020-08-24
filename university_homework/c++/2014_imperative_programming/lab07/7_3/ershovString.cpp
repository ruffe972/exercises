#include <cstring>
#include <iostream>
#include <cctype>
#include "standard.h"
#include "ershovString.h"
using std::cout;
using std::endl;


struct String
{
    int len;
    int capacity;
    char *array;
};


void addTerminatingCharacter(String *string)
{
    string->array[string->len] = '\0';
}


void changeLen(String *string, int newLen)
{
    if (newLen >= string->capacity)
    {
        addTerminatingCharacter(string);
        string->capacity = max(string->capacity * 2, newLen + 1);
        char *oldArray = string->array;
        string->array = new char[string->capacity];
        strcpy(string->array, oldArray);
        delete[] oldArray;
    }
    string->len = newLen;
}


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

//___

String *createString()
{
    String *string = new String;
    string->len = 0;
    const int newStringLen = 30;
    string->capacity = newStringLen + 1;
    string->array = new char[string->capacity];
    return string;
}


void deleteString(String *&string)
{
    delete[] string->array;
    delete string;
    string = nullptr;
}


char *toCString(String *string)
{
    char *cString = new char[string->len + 1];
    addTerminatingCharacter(string);
    strcpy(cString, string->array);
    return cString;
}

//___

String *substring(String *string, int leftBorder, int rightBorder)
{
    String *newString = createString();
    leftBorder = min(string->len - 1, leftBorder);
    rightBorder = min(string->len, rightBorder);
    changeLen(newString, rightBorder - leftBorder);
    addTerminatingCharacter(string);
    strncpy(newString->array, string->array + leftBorder, newString->len);
    return newString;
}


String *clone(String *string)
{    
    String *cloneString = substring(string, 0, string->len);
    return cloneString;
}


String *concatenate(String *string1, String *string2)
{
    String *newString = clone(string1);
    addTerminatingCharacter(newString);
    addTerminatingCharacter(string2);
    changeLen(newString, string1->len + string2->len);
    strcat(newString->array, string2->array);
    return newString;
}

//___

void print(std::ostream &output, String *string)
{
    addTerminatingCharacter(string);
    output << string->array;
}


bool scan(std::istream &input, String *string)
{    
    char character = ' ';
    while (character != EOF && isspace(character))
        character = input.get();
    if (character == EOF)
        return false;
    do
    {
        changeLen(string, string->len + 1);
        string->array[string->len - 1] = character;
        character = input.get();
    }
    while (character != EOF && !isspace(character));
    return true;
}


bool scanLine(std::istream &input, String *string)
{
    char character = input.get();
    if (character == EOF)
        return false;
    while (character != EOF && character != '\n')
    {
        changeLen(string, string->len + 1);
        string->array[string->len - 1] = character;
        character = input.get();
    }
    return true;
}


//___

bool areEqual(String *string1, String *string2)
{
    addTerminatingCharacter(string1);
    addTerminatingCharacter(string2);
    return strcmp(string1->array, string2->array) == 0;
}


int &len(String *string)
{
    return string->len;
}


char &charAt(String *string, int index)
{
    return string->array[index];
}
