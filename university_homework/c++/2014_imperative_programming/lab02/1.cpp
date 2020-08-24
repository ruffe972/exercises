#include <stdio.h>
#include <stdlib.h>


const int maxLen = 10000;


void initArray(int array[], int arrayLen)
{
    for (int i = 0; i < arrayLen; ++i)
        array[i] = -1;
}


int iterativeFib(int fibIndex)
{
    int fibNumber0 = 0;
    int fibNumber1 = 1;
    for (int i = 0; i < fibIndex; i++)
    {
        fibNumber1 += fibNumber0;
        fibNumber0 = fibNumber1 - fibNumber0;
    }
    return fibNumber0;
}


int recursiveFib(int fibIndex, int fibArray[])
{
    if (fibArray[fibIndex] != -1)
        return fibArray[fibIndex];
    return recursiveFib(fibIndex - 1, fibArray) + recursiveFib(fibIndex - 2, fibArray);
}
    

int main()
{
    printf("Enter the integer n >= 0: ");
    int fibIndex = 0;
    scanf("%d", &fibIndex);    
    printf("nth fib number is:\n");              
    printf("%d (iterative implementation)\n", iterativeFib(fibIndex));    
    int fibArray[maxLen];
    initArray(fibArray, fibIndex + 1);
    fibArray[0] = 0;
    fibArray[1] = 1;
    printf("%d (recursive implementation)", recursiveFib(fibIndex, fibArray));
}    
