#include <stdio.h>

const int maxLen = 10000;


int gcd(int number1, int number2)
{
    int temp = number1 % number2;
    while (temp != 0)
    {
        number1 = number2;
        number2 = temp;
        temp = number1 % number2;
    }
    return number2;
}


void printFractionArrays(int numeratorArray[], int denominatorArray[], int arrayLen)
{
    for (int i = 0; i < arrayLen; i++)
        printf("%d/%d  ", numeratorArray[i], denominatorArray[i]);
    for (int i = arrayLen - 2; i > -1; i--)
        printf("%d/%d  ", denominatorArray[i] - numeratorArray[i], denominatorArray[i]);
}
    

void swap(int& number1, int& number2)
{
    int temp = number1;
    number1 = number2;
    number2 = temp;
}

    
void swapFractions(int numeratorArray[], int denominatorArray[], int index1, int index2)
{ 
    swap(numeratorArray[index1], numeratorArray[index2]);
    swap(denominatorArray[index1], denominatorArray[index2]);
}


bool fractionIsLess(int numeratorArray[], int denominatorArray[], int index1, int index2)    
{
    return (denominatorArray[index2] * numeratorArray[index1] < denominatorArray[index1] * numeratorArray[index2]);
}
    
    
void sortFractions(int numeratorArray[], int denominatorArray[], int fractionArraysLen)
{    
    for (int i = 0; i < fractionArraysLen - 1; i++)
    {
        int indexOfMin = i;
        for (int j = i + 1; j < fractionArraysLen; j++)
            if (fractionIsLess(numeratorArray, denominatorArray, j, indexOfMin))
                indexOfMin = j;
        swapFractions(numeratorArray, denominatorArray, i, indexOfMin);
    }
}


int main()
{
    printf("Enter integer n > 1: ");
    int maxDenominator = 0;
    scanf("%d", &maxDenominator);    
    int numeratorArray[maxLen];
    int denominatorArray[maxLen];
    int fractionArraysLen = 0;
    for (int denominator = 2; denominator < maxDenominator + 1; denominator++)
        for (int numerator = 1; numerator < denominator / 2 + 1; numerator++)
            if (gcd(denominator, numerator) == 1)
            {
                numeratorArray[fractionArraysLen] = numerator;
                denominatorArray[fractionArraysLen] = denominator;
                fractionArraysLen++;
            }
    printf("All simple fractions between 0 & 1 with the denominator <= n:\n");
    sortFractions(numeratorArray, denominatorArray, fractionArraysLen);
    printFractionArrays(numeratorArray, denominatorArray, fractionArraysLen);      
}    