#include <iostream>
#include "list.h"


struct ListElement
{
    dataType value;
    ListElement *next;
};


struct List
{
    int len;
    //head is an additional element
    ListElement *head;
    ListElement *rightmost;
};


ListElement *createElement(dataType value, ListElement *next)
{
    ListElement *newElement = new ListElement;
    newElement->value = value;
    newElement->next = next;
    return newElement;
}


void recursiveDelete(ListElement *element, List *list)
{
    if (element == nullptr)
        return;
    recursiveDelete(element->next, list);
    delete element;
}


void deleteList(List *list)
{
    recursiveDelete(list->head, list);
    delete list;
}


List *createList()
{
    List *list = new List;    
    list->head = createElement(0, nullptr);
    list->rightmost = list->head;
    list->len = 0;
    return list;
}


void print(List *list)
{
    ListElement *current = list->head->next;
    while (current != nullptr)
    {
        std::cout << current->value << ' ';
        current = current->next;
    }
    std::cout << '\n';
}
    

void addValueAfterElement(dataType value, ListElement *previousElement, List *list)
{    
    ListElement *newElement = createElement(value, previousElement->next);    
    previousElement->next = newElement;
    if (previousElement == list->rightmost)
        list->rightmost = newElement;
    list->len++;
}
    

void removeNextElement(ListElement *previousElement, List *list)
{
    if (previousElement->next == list->rightmost)
        list->rightmost = previousElement;
    ListElement *temporary = previousElement->next->next;
    delete previousElement->next;
    previousElement->next = temporary;
    list->len--;
}


dataType popLeft(List *list)
{
    if (list->len == 0)
        return 0;
    dataType poppedValue = list->head->next->value;
    removeNextElement(list->head, list);
    return poppedValue;
}


void append(dataType value, List *list)
{
    addValueAfterElement(value, list->rightmost, list);
}


void appendLeft(dataType value, List *list)
{
    addValueAfterElement(value, list->head, list);
}


int len(List *list)
{
    return list->len;
}


ListElement *first(List *list)
{
    return list->head->next;
}


ListElement *next(ListElement *element)
{
    return element->next;
}


dataType value(ListElement *element)
{
    return element->value;
}
