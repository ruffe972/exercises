#include <string.h>
#include <stdio.h>
#include "textOperations.h"
#include "calculator.h"
#include "charStack.h"
#include "doubleStack.h"


bool symbolIsOperation(char symbol)
{
    return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}


int priority(char operation)
{
    if (operation == '+' || operation == '-')
        return 0;
    return 1;
}

char *infixToPostfix(char *infixString, char *postfixString)
{
    CharStack *stack = createCharStack();
    int postfixStringLen = 0;    
    int infixStringLen = strlen(infixString);
    for (int i = 0; i < infixStringLen; i++)
    {
        char symbol = infixString[i];
        if (symbolIsDigit(symbol))
            addSymbol(symbol, postfixString, postfixStringLen);
        else if (symbol == '(')
            appendChar(symbol, stack);
        else if (symbol == ')')
        {
            while (topChar(stack) != '(')
                addSymbol(popChar(stack), postfixString, postfixStringLen);
            popChar(stack);
        }
        else if (symbolIsOperation(symbol))
        {
            bool loopCondition = true;
            while (loopCondition)
                if (charStackSize(stack) == 0 || topChar(stack) == '(')
                    loopCondition = false;
                else if (priority(topChar(stack)) < priority(symbol))
                    loopCondition = false;
                else
                    addSymbol(popChar(stack), postfixString, postfixStringLen);
            appendChar(symbol, stack);
        }
    }
    while (charStackSize(stack) > 0)
        addSymbol(popChar(stack), postfixString, postfixStringLen);
    deleteCharStack(stack);
    return postfixString;
}


double calculateFromPostfix(char *string)
{
    DoubleStack *stack = createDoubleStack();
    int stringLen = strlen(string);
    for (int i = 0; i < stringLen; i++)
    {
        if (symbolIsDigit(string[i]))
            appendDouble(symbolToDigit(string[i]), stack);
        else if (symbolIsOperation(string[i]))
        {
            double number2 = popDouble(stack);
            double number1 = popDouble(stack);
            if (string[i] == '+')
                appendDouble(number1 + number2, stack);
            else if (string[i] == '-')
                appendDouble(number1 - number2, stack);
            else if (string[i] == '*')
                appendDouble(number1 * number2, stack);
            else if (string[i] == '/')
                appendDouble(number1 / number2, stack);
        }
    }
    double result = popDouble(stack);
    deleteDoubleStack(stack);
    return result;
}


double calculate(char *infixString)
{
    char postfixString[maxStringLen];
    return calculateFromPostfix(infixToPostfix(infixString, postfixString));
}
