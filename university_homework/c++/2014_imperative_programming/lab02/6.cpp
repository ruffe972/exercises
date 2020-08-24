#include <stdio.h>
#include <stdlib.h>
#include <time.h>


const int seqLen = 4;
const int digitsNumber = 10;    


void initBoolArray(bool array[], int arrayLen)
{
    for (int i = 0; i < arrayLen; ++i)
        array[i] = false;
}


void generateGuessedSeqArray(int guessedSeqArray[])
{    
    srand(time(0));    
    bool isUsed[digitsNumber];
    initBoolArray(isUsed, digitsNumber);
    for (int i = seqLen; i >= 0; i--)
    {
        guessedSeqArray[i] = rand() % digitsNumber;
        while (isUsed[guessedSeqArray[i]])
            guessedSeqArray[i] = rand() % digitsNumber;
        isUsed[guessedSeqArray[i]] = true;
        if (i == 1)
            isUsed[0] = true;            
    }
}   
    

void seqNumberToSeqArray(int seqNumber, int seqArray[])
{    
    for (int i = seqLen - 1; i >= 0; i--)
    {
        seqArray[i] = seqNumber % digitsNumber;
        seqNumber /= digitsNumber;
    }
}


int main()
{
    printf("Bulls & cows\n");
    int bulls = 0;
    int guessedSeqArray[seqLen];
    generateGuessedSeqArray(guessedSeqArray);
    while (bulls != seqLen)
    {
        printf("Your guess: ");    
        int userSeqNumber = 0;
        scanf("%d", &userSeqNumber);    
        int userSeqArray[seqLen];
        seqNumberToSeqArray(userSeqNumber, userSeqArray);
        int cows = 0;
        bulls = 0;        
        for (int i = 0; i < seqLen; i++)
            for (int j = 0; j < seqLen; j++)
                if (userSeqArray[i] == guessedSeqArray[j])
                    if (i == j)
                        bulls++;
                    else
                        cows++;
        printf("Bulls: %d, cows: %d\n", bulls, cows);      
    }
}    

