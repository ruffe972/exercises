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


void deleteCircularList(List *list);

List *createCircularList(int headValue);

void addValueAfterElement(int value, ListElement *element);

void removeNextElementFromList(ListElement *element);

void solveCounting(int soldiersNumber, int step);
