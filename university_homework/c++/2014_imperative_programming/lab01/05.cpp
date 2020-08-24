#include <stdio.h>
#include <stdlib.h>
const int maxLen = 1000;

int main()
{
    printf("Enter a sequence of the round brackets: ");
    char sequence[maxLen];
    scanf("%s", sequence);
    int balance = 0;    
    bool goodBalance = true;
    for (int i = 0; sequence[i] != '\0' && goodBalance; ++i)
    {
        if (sequence[i] == '(')
        {
            ++balance;
        }
        else
        {
            --balance;
            if (balance == -1)
            {
                goodBalance = false;
            }
        }
    }
    printf("Balance is ");
    if (goodBalance && balance == 0)
    {
        printf("good.");
    }
    else
    {
        printf("bad.");    
    }
}    