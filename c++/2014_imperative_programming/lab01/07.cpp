#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

const int maxNum = 10000;
   

int main()
{
    printf("Enter positive integer n: ");
    int number = 0;
    scanf("%d", &number);    
    bool isPrime[maxNum];
    for (int i = 0; i <= number; ++i)
    {
        isPrime[i] = true;
    }
    printf("Prime numbers <= n:\n");
    for (int i = 2; i <= number; i++)
    {
        if (isPrime[i])
        {
            printf("%d\n", i);
            for (int j = i + i; j <= number; j += i)
            {
                isPrime[j] = false;
            }
        }
    }                 
}    