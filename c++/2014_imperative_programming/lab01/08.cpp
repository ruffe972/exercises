#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


int recursiveFactorial(int number)
{
    if (number == 0)
    {
        return 1;
    }
    return recursiveFactorial(number - 1) * number;
}    

/*
int iterativeFactorial(int number)
{
    int iterativeFactorial = 1; 
    for (int i = 2; i <= number; ++i)
    {
        iterativeFactorial *= i;
    }
    return iterativeFactorial;
}
*/

int iterativeFactorial(int number)
{
    int result = 1; 
    for (int i = 2; i <= number; ++i)
    {
        result *= i;
    }
    return result;
}


int main()
{
    printf("Enter a positive integer n: ");
    int number = 0;
    scanf("%d", &number);        
    printf("n! = %d (iterative implementation)\n", iterativeFactorial(number));
    printf("n! = %d (recursive implementation)", recursiveFactorial(number));
}    