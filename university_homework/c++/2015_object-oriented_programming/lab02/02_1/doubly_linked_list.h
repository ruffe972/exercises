#pragma once
#include <iostream>
#include "list.h"


//! Pointer-based doubly linked list
template <typename T>
class DoublyLinkedList: public List<T>
{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    int len() const;
    void print() const;
    void append(T value);
    T popleft();
private:
    struct Element
    {
        T value;
        Element *previous;
        Element *next;
        Element(T value, Element *previous, Element *next);
    };
    void addValueAfterElement(Element *previousElement, T value);
    void remove(Element *element);
    //auxiliary elements
    Element *head;
    Element *tail;
};


template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() :
    List<T>(),
    head(new Element(0, nullptr, nullptr)),
    tail(new Element(0, head, nullptr))
{
    head->next = tail;
}


template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
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
int DoublyLinkedList<T>::len() const
{
    return this->length;
}


template <typename T>
void DoublyLinkedList<T>::print() const
{
    Element *current = head->next;
    while (current != tail)
    {
        std::cout << current->value << ' ';
        current = current->next;
    }
    std::cout << '\n';
}


template <typename T>
void DoublyLinkedList<T>::append(T value)
{
    addValueAfterElement(tail->previous, value);
}


template <typename T>
T DoublyLinkedList<T>::popleft()
{
    if (len() == 0)
        return -1;
    T poppedValue = head->next->value;
    remove(head->next);
    return poppedValue;
}


template <typename T>
void DoublyLinkedList<T>::addValueAfterElement(Element *previousElement, T value)
{
    Element *nextElement = previousElement->next;
    Element *newElement = new Element(value, previousElement, nextElement);
    previousElement->next = newElement;
    nextElement->previous = newElement;
    this->length++;
}


template <typename T>
void DoublyLinkedList<T>::remove(Element *element)
{
    element->previous->next = element->next;
    element->next->previous = element->previous;
    delete element;
    this->length--;
}


template <typename T>
DoublyLinkedList<T>::Element::Element(T value, Element *previous, Element *next) :
    value(value), previous(previous), next(next) {}
