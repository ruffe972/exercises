#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
const int maxLen = 1000;


int main()
{
    printf("Enter lines s and s1:\n");
    char s[maxLen];
    char s1[maxLen];
    scanf("%s", s);    
    scanf("%s", s1);
    int j = 0;    
    int answer = 0;
    for (int i = 0; i < strlen(s) - strlen(s1) + 1; ++i)
    {
        for (j = 0; j < strlen(s1) && s[j + i] == s1[j]; ++j);                
        if (j == strlen(s1))
        {
            answer++;
        }                        
    }                      
    printf("s1 occurs in s %d time(s)", answer);
}    