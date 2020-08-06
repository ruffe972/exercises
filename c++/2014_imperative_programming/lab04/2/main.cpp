#include <stdio.h>
#include "calculator.h"
#include "textOperations.h"


int main()
{
    printf("Enter an expression written in infix notation:\n");
    char infixString[maxStringLen];
    scanString(infixString, maxStringLen);
    printf("Postfix notation:\n");
    char postfixString[maxStringLen];
    printf("%s\n", infixToPostfix(infixString, postfixString));
}
