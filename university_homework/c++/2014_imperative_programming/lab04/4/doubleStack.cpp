#include "doubleStack.h"
#include <stdio.h>


struct DoubleStackElement
{
    double value;
    DoubleStackElement *next;
};


struct DoubleStack
{
    DoubleStackElement *head;
    int size;
};


//not in header
DoubleStackElement *createDoubleElement(double value, DoubleStackElement *next)
{
    DoubleStackElement *newElement = new DoubleStackElement;
    newElement->value = value;
    newElement->next = next;
    return newElement;
}


DoubleStack *createDoubleStack()
{
    DoubleStack *stack = new DoubleStack;
    stack->size = 0;
    stack->head = createDoubleElement(0, nullptr);
    return stack;
}


void deleteDoubleStack(DoubleStack *stack)
{
    while (stack->size != 0)
        popDouble(stack);
    delete stack->head;
    delete stack;
}


double popDouble(DoubleStack *stack)
{
    if (stack->size == 0)
        return 0;
    DoubleStackElement *element = stack->head->next->next;
    double value = stack->head->next->value;
    delete stack->head->next;
    stack->head->next = element;
    stack->size--;
    return value;
}


double topDouble(DoubleStack *stack)
{
    return stack->head->next->value;
}


void appendDouble(double value, DoubleStack *stack)
{
    DoubleStackElement *element = createDoubleElement(value, stack->head->next);
    stack->head->next = element;
    stack->size++;
}


void printDoubleStack(DoubleStack *stack)
{
    DoubleStackElement *element = stack->head->next;
    while (element != nullptr)
    {
        printf("%f ", element->value);
        element = element->next;
    }
    printf("\n");
}


int doubleStackSize(DoubleStack *stack)
{
    return stack->size;
}

