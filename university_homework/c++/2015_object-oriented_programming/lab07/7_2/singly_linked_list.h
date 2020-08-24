#pragma once
#include <iostream>
#include "list.h"


//! Pointer-based singly linked list
template <typename T>
class SinglyLinkedList: public List<T>
{
public:
    SinglyLinkedList(): List<T>(), head(new Element(0, nullptr)), lastElement(head) {}
    ~SinglyLinkedList();
    int len() const;
    void print() const;
    void append(const T &value);
    T popleft();
protected:
    class Element
    {
    public:
        T value;
        Element *next;
        Element(const T &value, Element *next) : value(value), next(next) {}
    };
    void addValueAfterElement(Element *previousElement, T value);
    void removeNext(Element *previousElement);
    //auxiliary element
    Element *head;
    Element *lastElement;
};


template <typename T>
void SinglyLinkedList<T>::removeNext(Element *previousElement)
{
    if (!previousElement || previousElement == lastElement)
        throw typename List<T>::NoElementError();
    if (previousElement->next == lastElement)
        lastElement = previousElement;
    Element *auxiliary = previousElement->next->next;
    delete previousElement->next;
    previousElement->next = auxiliary;
    this->length--;
}


template <typename T>
T SinglyLinkedList<T>::popleft()
{
    if (len() == 0)
        throw typename List<T>::NoElementError();
    T poppedValue = head->next->value;
    removeNext(head);
    return poppedValue;
}


template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    Element *current = head;
    while (current)
    {
        Element *afterCurrent = current->next;
        delete current;
        current = afterCurrent;
    }
}


template <typename T>
int SinglyLinkedList<T>::len() const
{
    return this->length;
}


template <typename T>
void SinglyLinkedList<T>::print() const
{
    Element *current = head->next;
    while (current)
    {
        std::cout << current->value << ' ';
        current = current->next;
    }
    std::cout << '\n';
}


template <typename T>
void SinglyLinkedList<T>::append(const T &value)
{
    addValueAfterElement(lastElement, value);
}


template <typename T>
void SinglyLinkedList<T>::addValueAfterElement(Element *previousElement, T value)
{
    Element *newElement = new Element(value, previousElement->next);
    previousElement->next = newElement;
    if (previousElement == lastElement)
        lastElement = newElement;
    this->length++;
}
