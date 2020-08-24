#include <stdio.h>

const int maxArrayLen = 10000;


void reverse(int intArray[maxArrayLen], int left, int right)
{
    int temp = 0;
    for (int i = left; i < (left + right + 1) / 2; ++i)
    {
        temp = intArray[i];
        intArray[i] = intArray[left + right - i];    
        intArray[left + right - i] = temp;
    }
}


int main()
{
    printf("Enter positive integers m and n (m + n <= %d): ", maxArrayLen);
    int m = 0;
    int n = 0;
    scanf("%d %d", &m, &n);
    printf("Enter an array of m + n integers: ");
    int intArray[maxArrayLen + 1];
    for (int i = 0; i < m + n; i++)
    {
        scanf("%d", &intArray[i]);
    }
    reverse(intArray, 0, m - 1);
    reverse(intArray, m, m + n - 1);
    reverse(intArray, 0, m + n - 1);
    for (int i = 0; i < m + n; i++)
    {
        printf("%d ", intArray[i]);
    }
}
