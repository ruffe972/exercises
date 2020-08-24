#include <stdio.h>
#include "circularList.h"


void removeNextElementFromList(ListElement *element)
{
    ListElement *temporary = element->next->next;
    delete element->next;
    element->next = temporary;
}


void deleteCircularList(List *list)
{
    ListElement *listHead = list->head;
    while (listHead->next != listHead)
        removeNextElementFromList(listHead);
    delete listHead;
    delete list;
}


ListElement *createElement(int value, ListElement *next)
{
    ListElement *newElement = new ListElement;
    newElement->value = value;
    newElement->next = next;
    return newElement;
}


List *createCircularList(int headValue)
{
    List *list = new List;    
    list->head = createElement(headValue, nullptr);
    list->head->next = list->head;
    return list;
}


void addValueAfterElement(int value, ListElement *element)
{
    ListElement *newElement = createElement(value, element->next);
    element->next = newElement;
}


void solveCounting(int soldiersNumber, int step)
{
    List *list = createCircularList(soldiersNumber);
    for (int i = soldiersNumber - 1; i > 0; i--)
        addValueAfterElement(i, list->head);
    for (int i = 0; i < soldiersNumber - 1; i++)
    {
        for (int j = 0; j < step - 1; j++)
            list->head = list->head->next;
        removeNextElementFromList(list->head);
    }
    printf("The last remaining soldier is #%d.\n", list->head->value);
    deleteCircularList(list);
}
