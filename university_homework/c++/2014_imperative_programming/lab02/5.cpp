#include <stdio.h>

const int maxLen = 10000;
const int lenIndex = 0;


void swap(int& number1, int& number2)
{
    int temp = number1;
    number1 = number2;
    number2 = temp;
}


void printArray(int array[])
{
    for (int i = 1; i <= array[lenIndex]; ++i)
        printf("%d ", array[i]);
    printf("\n");        
}


void scanArray(int array[])
{
    for (int i = 1; i <= array[lenIndex]; ++i)
        scanf("%d", &array[i]);
}
    
    
void siftDown(int array[], int siftedElementIndex, int borderIndex)
{
    int leftChildIndex = siftedElementIndex * 2;
    int minIndex = siftedElementIndex - 1;
    while (siftedElementIndex != minIndex && leftChildIndex <= borderIndex)
    {
        minIndex = siftedElementIndex;
        if (array[minIndex] > array[leftChildIndex])
            minIndex = leftChildIndex;
        int rightChildIndex = siftedElementIndex * 2 + 1;
        if (rightChildIndex <= borderIndex && array[minIndex] > array[rightChildIndex])
            minIndex = rightChildIndex;
        if (siftedElementIndex != minIndex)
        {
            swap(array[siftedElementIndex], array[minIndex]);
            swap(siftedElementIndex, minIndex);
        }
        leftChildIndex = siftedElementIndex * 2;
    }
}
        
    
void heapSort(int array[])
{
    for (int i = array[lenIndex] / 2; i > 0; i--)
        siftDown(array, i, array[lenIndex]);    
    for (int i = array[lenIndex]; i > 1; i--)
    {
        swap(array[1], array[i]);
        siftDown(array, 1, i - 1);
    }
}


int main()
{
    printf("Enter a number of elements in an array:\n");
    int array[maxLen];
    scanf("%d", &array[lenIndex]);    
    printf("Enter the integer elements of the array:\n"); 
    scanArray(array);      
    heapSort(array);     
    printf("Sorted array:\n");
    printArray(array);
}    