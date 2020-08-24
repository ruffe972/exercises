#pragma once
#include "ershovString.h"

namespace stringList
{
    typedef int dataType;
    struct ListElement;
    struct List;

    List *createList();
    void deleteList(List *list);
    int len(List *list);
    void printOnlyWords(std::ostream &file, List *list);
    void printWholeList(std::ostream &file, List *list);
    void appendLeft(String *word, List *list);
    int &amount(ListElement *element);
    ListElement *elementByString(String *string, List *list);
}
