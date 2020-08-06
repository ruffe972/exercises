#pragma once

namespace list
{
    typedef int dataType;
    struct ListElement;
    struct List;

    void deleteList(List *list);
    List *createList();
    void print(List *list);

    void addValueAfterElement(List *list, ListElement *previousElement, dataType value);
    void removeNext(List *list, ListElement *previousElement);

    dataType popLeft(List *list);
    void appendLeft(List *list, dataType value);
    void append(List *list, dataType value);
    int len(List *list);

    ListElement *leftmostElement(List *list);
    ListElement *leftBarrier(List *list);
    ListElement *next(ListElement *element);
    dataType value(ListElement *element);
}
