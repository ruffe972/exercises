#include <stdio.h>
#include <string.h>


void setStringLen(int stringLen, char *string)
{
    for (int i = strlen(string); i < stringLen; i++)
        string[i] = 'z';
    string[stringLen] = '\0';
}


void scanString(char *string, int maxStringLen)
{
    fgets(string, maxStringLen + 1, stdin);
    if (strlen(string) > 0)
        setStringLen(strlen(string) - 1, string);
}


void addSymbol(char symbol, char *string, int& stringLen)
{
    setStringLen(stringLen + 1, string);
    stringLen++;
    string[stringLen - 1] = symbol;
}


int symbolToDigit(char symbol)
{
    return symbol - '0';
}


bool isDigit(char symbol)
{
    return symbol >= '0' && symbol <= '9';
}


bool isLetter(char symbol)
{
    return (symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z');
}


char symbolToLowerCase(char symbol)
{
    return isLetter(symbol) && symbol >= 'A' && symbol <= 'Z' ? symbol + 'a' - 'A' : symbol;
}
