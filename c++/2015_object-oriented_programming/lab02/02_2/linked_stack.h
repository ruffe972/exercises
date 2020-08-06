#pragma once
#include <iostream>
#include "stack.h"


//! Stack based on a linked list
template <typename T>
class LinkedStack : public Stack<T>
{
public:
    //! Destroy the stack
    ~LinkedStack();
    //! Create a stack
    LinkedStack() : Stack<T>(), head(new Element(0, nullptr)) {}
    int len() const;
    void print() const;
    void push(T value);
    T pop();
private:
    class Element
    {
    public:
        T value;
        Element *next;
        Element(T value, Element *next) : value(value), next(next) {}
    };
    //auxiliary element
    Element *head;
    void print(Element *element) const
    {
        if (!element)
            return;
        print(element->next);
        std::cout << element->value << ' ';
    }
};


template <typename T>
LinkedStack<T>::~LinkedStack()
{
    while (this->length != 0)
        pop();
    delete head;
}


template <typename T>
int LinkedStack<T>::len() const
{
    return this->length;
}


template <typename T>
void LinkedStack<T>::print() const
{
    print(head->next);
}


template <typename T>
void LinkedStack<T>::push(T value)
{
    head->next = new Element(value, head->next);
    this->length++;
}


template <typename T>
T LinkedStack<T>::pop()
{
    if (this->length == 0)
        return 0;
    Element *newTop = head->next->next;
    T value = head->next->value;
    delete head->next;
    head->next = newTop;
    this->length--;
    return value;
}
