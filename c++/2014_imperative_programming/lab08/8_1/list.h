#pragma once

typedef int dataType;
struct ListElement;
struct List;

void deleteList(List *list);
List *createList();
void print(List *list);

void addValueAfterElement(dataType value, ListElement *previousElement, List *list);
void removeNextElement(ListElement *previousElement, List *list);

dataType popLeft(List *list);
void appendLeft(dataType value, List *list);
void append(dataType value, List *list);
int len(List *list);

ListElement *first(List *list);
ListElement *next(ListElement *element);
dataType value(ListElement *element);
