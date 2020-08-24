#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

const int maxLen = 10000;
    

int main()
{    
    char word[maxLen];
    printf("Enter a word:\n");
    scanf("%s", word);
    int i = 0;
    bool wordIsPalindrome = true;
    for (i = 0; i < strlen(word) / 2 && wordIsPalindrome; i++)
    {
        if (word[i] != word[strlen(word) - i - 1])
        {
            wordIsPalindrome = false;
        }
    }

    if (wordIsPalindrome)
    {
        printf("It is a palindrome");
    }
    else
    {
        printf("It is not a palindrome");
    }                          
}    