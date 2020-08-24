#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

const int maxLen = 10000;


void swap(int& number1, int& number2)
{
    int temp = number1;
    number1 = number2;
    number2 = temp;
}
    

void qSort(int array[maxLen], int left, int right)
{                         
    int median = array[left + (right - left) / 2];
    int i = left;
    int j = right;
    while (i <= j)
    {
        while (array[i] < median)
            ++i;
        while (array[j] > median)
            --j;
        if (i <= j)
        {
            swap(array[i], array[j]);
            ++i;
            --j;
        }
    }
    if (j > left)
        qSort(array, left, j);
    if (i < right)
        qSort(array, i, right);
}


int main()
{
    printf("Enter a number of elements in an array:\n");
    int arrayLen = 0;
    scanf("%d", &arrayLen);    
    printf("Enter the integer elements of the array:\n");
    int array[maxLen];    
    for (int i = 0; i < arrayLen; ++i)
        scanf("%d", &array[i]);
    qSort(array, 0, arrayLen - 1);
    printf("Sorted array:\n");
    for (int i = 0; i < arrayLen; ++i)
        printf("%d ", array[i]);
}    
