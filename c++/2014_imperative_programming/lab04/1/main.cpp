#include <stdio.h>
#include "sort.h"


int main()
{
    printf("Enter the array length and its integer elements:\n");
    int arrayLen = 0;
    scanf("%d", &arrayLen);
    int *array = new int[arrayLen];
    for (int i = 0; i < arrayLen; i++)
        scanf("%d", &array[i]);
    sort(array, arrayLen);
    int i = arrayLen - 2;
    while (i > - 2 && array[i] != array[i + 1])
        i--;
    if (i == -2)
        printf("There is no doublemaximum\n");
    else
        printf("Doublemaximum is %d\n", array[i]);
    delete[] array;
}

