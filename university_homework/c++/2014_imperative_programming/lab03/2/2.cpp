#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

const char firstChar = fmin(fmin('0', 'a'), 'A');
const char lastChar = fmax(fmax('9', 'z'), 'Z');
const int maxLen = 1000;
char possibleMsg[maxLen] = "It is possible to get one string from another by permutating the letters.";        
char notPossibleMsg[maxLen] = "It is not possible to get one string from another by permutating the letters.";        


void initArray(int array[], int arrayLen)
{
    for (int i = 0; i < arrayLen; ++i)
        array[i] = 0;
}


int main()
{
    printf("Enter two strings:\n");
    int charOccurences1[lastChar + 1];
    initArray(charOccurences1, lastChar);
    int charOccurences2[lastChar + 1];
    initArray(charOccurences2, lastChar);    
    char str1[maxLen];
    char str2[maxLen];    
    scanf("%s %s", str1, str2);
    int strLen = strlen(str1);    
    if (strLen != strlen(str2))
    {   
        printf(notPossibleMsg);
        return 0;
    }
    for (int i = 0; i < strLen; i++)
    {
        charOccurences1[str1[i]]++;    
        charOccurences2[str2[i]]++;
    }

    for (int i = firstChar; i <= lastChar; i++)
        if (charOccurences1[i] != charOccurences2[i])
        {   
            printf(notPossibleMsg);
            return 0;
        }
    printf(possibleMsg);        
    return 0;
}