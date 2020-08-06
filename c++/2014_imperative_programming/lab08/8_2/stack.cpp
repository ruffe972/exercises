#include <iostream>
#include "stack.h"


namespace stack
{
    struct StackElement
    {
        dataType value;
        StackElement *next;
    };


    struct Stack
    {
        StackElement *head;
        int len;
    };



    StackElement *createElement(dataType value, StackElement *next)
    {
        StackElement *newElement = new StackElement;
        newElement->value = value;
        newElement->next = next;
        return newElement;
    }


    Stack *createStack()
    {
        Stack *stack = new Stack;
        stack->len = 0;
        stack->head = createElement(0, nullptr);
        return stack;
    }


    void deleteStack(Stack *stack)
    {
        while (stack->len != 0)
            pop(stack);
        delete stack->head;
        delete stack;
    }


    dataType pop(Stack *stack)
    {
        if (stack->len == 0)
            return 0;
        StackElement *element = stack->head->next->next;
        dataType value = stack->head->next->value;
        delete stack->head->next;
        stack->head->next = element;
        stack->len--;
        return value;
    }


    dataType top(Stack *stack)
    {
        return stack->head->next->value;
    }


    void append(Stack *stack, dataType value)
    {
        StackElement *element = createElement(value, stack->head->next);
        stack->head->next = element;
        stack->len++;
    }


    void print(Stack *stack)
    {
        StackElement *element = stack->head->next;
        while (element != nullptr)
        {
            std::cout << element->value << ' ';
            element = element->next;
        }
        std::cout << '\n';
    }


    int len(Stack *stack)
    {
        return stack->len;
    }
}
