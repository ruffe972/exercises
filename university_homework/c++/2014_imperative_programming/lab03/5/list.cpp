#include <stdio.h>
#include "list.h"


ListElement *elementBeforeValueInList(int value, List *list)
{
    ListElement *current = list->head;
    while (current->next != nullptr && current->next->value < value)
        current = current->next;        
    return current;
}


ListElement *createElement(int value, ListElement *next)
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
    return list;
}


void printList(List *list)
{
    ListElement *current = list->head->next;
    while (current != nullptr)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

    
void addValueToSortedList(int value, List *list)
{
    ListElement *elementBeforeValue = elementBeforeValueInList(value, list);
    ListElement *newElement = createElement(value, elementBeforeValue->next);
    elementBeforeValue->next = newElement;
}
    

void removeValueFromSortedList(int value, List *list)
{    
    ListElement *elementBeforeValue = elementBeforeValueInList(value, list);
    ListElement *current = elementBeforeValue->next;
    while (current != nullptr && current->value == value)
    {        
        ListElement *temporary = current->next;
        delete current;
        current = temporary;
    }
    elementBeforeValue->next = current;
}
