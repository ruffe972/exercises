#include <stdio.h>
#include <stdlib.h>
const int maxSum = 28;

void initArray(int array[maxSum], int length)
{
    for (int i = 0; i < length; ++i)
    {
        array[i] = 0;
    }
}

int main()
{
    int tickets[maxSum];
    initArray(tickets, maxSum);    
    for (int n1 = 0; n1 < 10; ++n1)
    {
        for (int n2 = 0; n2 < 10; ++n2)
        {
            for (int n3 = 0; n3 < 10; ++n3)
            {
                ++tickets[n1 + n2 + n3];
            }
        }
    }
    int result = 0;        
    for (int i = 0; i < maxSum; ++i)
    {
        result += tickets[i] * tickets[i];
    }
    printf("The number of lucky tickets is %d.", result);
}    