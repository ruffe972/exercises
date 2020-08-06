#include <stdio.h>
#include <stdlib.h>
#include "textOperations.h"


const int maxArrayLen = 'z' + 1;


void resetUsedLetters(bool *array)
{
    for (int i = 'a'; i <= 'z'; i++)
        array[i] = false;
}


int main()
{
    FILE* inputFile = fopen("input.txt", "r");

    char symbol = '0';
    bool previousSymbolIsLetter = false;
    bool usedLetters[maxArrayLen];
    resetUsedLetters(usedLetters);

    while (fscanf(inputFile, "%c", &symbol) != EOF)
        if (isLetter(symbol))
        {
            if (!usedLetters[(int)symbolToLowerCase(symbol)])
            {
                usedLetters[(int)symbolToLowerCase(symbol)] = true;
                printf("%c", symbol);
            }
            previousSymbolIsLetter = true;
        }
        else
        {
            printf("%c", symbol);
            if (!(symbol == '-' && previousSymbolIsLetter))
                resetUsedLetters(usedLetters);
            previousSymbolIsLetter = false;
        }

    printf("\n");
    fclose(inputFile);
    return 0;
}
