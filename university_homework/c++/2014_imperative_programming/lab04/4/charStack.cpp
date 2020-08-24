#include "charStack.h"
#include <stdio.h>


struct CharStackElement
{
    char value;
    CharStackElement *next;
};


struct CharStack
{
    CharStackElement *head;
    int size;
};


//not in header
CharStackElement *createCharElement(char value, CharStackElement *next)
{
    CharStackElement *newElement = new CharStackElement;
    newElement->value = value;
    newElement->next = next;
    return newElement;
}


CharStack *createCharStack()
{
    CharStack *stack = new CharStack;
    stack->size = 0;
    stack->head = createCharElement(0, nullptr);
    return stack;
}


void deleteCharStack(CharStack *stack)
{
    while (stack->size != 0)
        popChar(stack);
    delete stack->head;
    delete stack;
}


char popChar(CharStack *stack)
{
    if (stack->size == 0)
        return 0;
    CharStackElement *element = stack->head->next->next;
    char value = stack->head->next->value;
    delete stack->head->next;
    stack->head->next = element;
    stack->size--;
    return value;
}


char topChar(CharStack *stack)
{
    return stack->head->next->value;
}


void appendChar(char value, CharStack *stack)
{
    CharStackElement *element = createCharElement(value, stack->head->next);
    stack->head->next = element;
    stack->size++;
}


void printCharStack(CharStack *stack)
{
    CharStackElement *element = stack->head->next;
    while (element != nullptr)
    {
        printf("%c", element->value);
        element = element->next;
    }
    printf("\n");
}


int charStackSize(CharStack *stack)
{
    return stack->size;
}
