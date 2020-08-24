#pragma once
#include <iostream>
#include "stack.h"


//! Stack based on a non-resizable dynamic array
template <typename T>
class ArrayStack : public Stack<T>
{
public:
    //! Destroy the stack
    ~ArrayStack();
    //! Create a stack with the default capacity
    ArrayStack() : Stack<T>(), capacity(defaultCapacity), valueArray(new T[capacity]) {}
    //! Create a stack
    /*! @param capacity - new stack capacity */
    ArrayStack(int capacity) : Stack<T>(), capacity(capacity), valueArray(new T[capacity]) {}
    //! Get stack capacity
    int getCapacity() const;
    int len() const;
    void print() const;
    void push(T value);
    T pop();
private:
    const static int defaultCapacity = 1000;
    int capacity;
    T *valueArray;
};


template <typename T>
ArrayStack<T>::~ArrayStack()
{
    delete[] valueArray;
}


template <typename T>
int ArrayStack<T>::getCapacity() const
{
    return capacity;
}


template <typename T>
int ArrayStack<T>::len() const
{
    return this->length;
}


template <typename T>
void ArrayStack<T>::print() const
{
    for (int i = 0; i < this->length; i++)
        std::cout << valueArray[i] << ' ';
}


template <typename T>
void ArrayStack<T>::push(T value)
{
    if (this->length < capacity)
    {
        valueArray[this->length] = value;
        this->length++;
    }
}


template <typename T>
T ArrayStack<T>::pop()
{
    if (this->length == 0)
        return 0;
    this->length--;
    return valueArray[this->length];
}
