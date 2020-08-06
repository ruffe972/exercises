#pragma once


struct ListElement
{
    int value;
    ListElement *next;
};


struct List
{
    ListElement *head;
};


void deleteList(List *list);
List *createList();
void printList(List *list);
void addValueToSortedList(int value, List *list);
void removeValueFromSortedList(int value, List *list);