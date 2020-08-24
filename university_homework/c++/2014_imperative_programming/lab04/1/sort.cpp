#include <sort.h>


void swap(int& number1, int& number2)
{
    int temp = number1;
    number1 = number2;
    number2 = temp;
}


void recursiveSort(int *array, int left, int right)
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
        recursiveSort(array, left, j);
    if (i < right)
        recursiveSort(array, i, right);
}


void sort(int *array, int arrayLen)
{
    recursiveSort(array, 0, arrayLen - 1);
}

