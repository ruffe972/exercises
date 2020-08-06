#include <stdio.h>
//#include <stdlib.h>
#include <math.h>
//#include <string.h>


const int maxLen = 1000;


void printArray(int array[], int arrayLen)
{
    for (int i = 0; i < arrayLen; ++i)
        printf("%d ", array[i]);
    printf("\n");
}


void partition(int number, int biggestNumber, int partArray[], int partArrayLen)
{
    if (number == 0)
    {
        printArray(partArray, partArrayLen);
        return;
    }
    for (int i = biggestNumber; i > 0; i--)
    {
        
        partArray[partArrayLen] = i;
        partition(number - i, fmin(i, number - i), partArray, partArrayLen + 1);    
    }
}        


int main()
{
    printf("Enter the positive integer n: ");
    int number = 0;
    scanf("%d", &number);    
    printf("All possible partitions of n:\n");
    int partArray[maxLen];
    partition(number, number, partArray, 0);      
}    
