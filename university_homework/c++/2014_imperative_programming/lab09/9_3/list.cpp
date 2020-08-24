#include <iostream>
#include "list.h"


namespace list
{
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


    void addValueAfterElement(List *list, ListElement *previousElement, dataType value)
    {
        ListElement *newElement = createElement(value, previousElement->next);
        previousElement->next = newElement;
        if (previousElement == list->rightmost)
            list->rightmost = newElement;
        list->len++;
    }


    void removeNext(List *list, ListElement *previousElement)
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
        removeNext(list, list->head);
        return poppedValue;
    }


    void append(List *list, dataType value)
    {
        addValueAfterElement(list, list->rightmost, value);
    }


    void appendLeft(List *list, dataType value)
    {
        addValueAfterElement(list, list->head, value);
    }


    int len(List *list)
    {
        return list->len;
    }


    ListElement *leftBarrier(List *list)
    {
        return list->head;
    }


    ListElement *leftmostElement(List *list)
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
}
