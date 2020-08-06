#include <stdio.h>

const int digitsAmount = 10;


void initArray(int array[], int arrayLen)
{
    for (int i = 0; i < arrayLen; ++i)
        array[i] = 0;
}


int main()
{
    printf("Enter a positive integer:\n");
    char character = '0';
    int digitArray[digitsAmount];
    initArray(digitArray, digitsAmount);
    while (character != '\n')
    {     
        scanf("%c", &character);        
        digitArray[character - '0']++;
        //надеюсь, так можно
    }
    printf("The smallest number obtained by permutating the given digits:\n");
    int digit = 1;
    while (digitArray[digit] == 0)
        digit++;
    printf("%d", digit);
    digitArray[digit]--;
    for (digit = 0; digit < digitsAmount; digit++)
        for (int i = 0; i < digitArray[digit]; i++)
            printf("%d", digit);    
}    