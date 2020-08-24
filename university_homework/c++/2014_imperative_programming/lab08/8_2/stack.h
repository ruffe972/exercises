#pragma once

namespace stack
{
    typedef int dataType;
    struct StackElement;
    struct Stack;

    Stack *createStack();
    void deleteStack(Stack *stack);
    void print(Stack *stack);
    int len(Stack *stack);

    dataType pop(Stack *stack);
    dataType top(Stack *stack);
    void append(Stack *stack, dataType value);
}
