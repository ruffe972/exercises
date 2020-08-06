#include <stdio.h>
#include <string.h>
#include "textOperations.h"


int max(int number1, int number2)
{
    if (number1 > number2)
        return number1;
    return number2;
}


void scanString(char string[], int &stringLen, FILE *file)
{
    if (file == stdin)
        fflush(stdin);
    fgets(string, maxStringLength, file);
    stringLen = max(0, strlen(string) - 1);
    string[stringLen] = '\0';
}




int toDigit(char symbol)
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
