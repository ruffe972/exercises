#include <iostream>
#include "ershovString.h"
#include "stringList.h"
using std::endl;


namespace stringList
{
    struct ListElement
    {
        int amount;
        String *string;
        ListElement *next;
    };


    struct List
    {
        int len;
        //head is an additional element
        ListElement *head;
    };


    ListElement *createElement(String *string, ListElement *next)
    {
        ListElement *newElement = new ListElement;
        newElement->string = clone(string);
        newElement->amount = 1;
        newElement->next = next;
        return newElement;
    }


    void deleteElement(ListElement *element)
    {
        deleteString(element->string);
        delete element;
    }


    void recursiveDelete(ListElement *element, List *list)
    {
        if (element == nullptr)
            return;
        recursiveDelete(element->next, list);
        deleteElement(element);
    }


    void deleteList(List *list)
    {
        recursiveDelete(list->head, list);
        delete list;
    }


    List *createList()
    {
        List *list = new List;
        String *emptyString = createString();
        list->head = createElement(emptyString, nullptr);
        deleteString(emptyString);
        list->len = 0;
        return list;
    }


    void printOnlyStrings(std::ostream &file, List *list)
    {
        ListElement *current = list->head->next;
        while (current != nullptr)
        {
            print(file, current->string);
            file << ' ';
            current = current->next;
        }
        file << endl;
    }


    void printWholeList(std::ostream &file, List *list)
    {
        ListElement *current = list->head->next;
        while (current != nullptr)
        {
            file << current->amount << ' ';
            print(file, current->string);
            file << endl;
            current = current->next;
        }
    }


    void appendLeft(String *string, List *list)
    {
        ListElement *newElement = createElement(string, list->head->next);
        list->head->next = newElement;
        list->len++;
    }


    int len(List *list)
    {
        return list->len;
    }


    int &amount(ListElement *element)
    {
        return element->amount;
    }


    ListElement *elementByString(String *string, List *list)
    {
        ListElement *element = list->head->next;
        while (element != nullptr && !areEqual(element->string, string))
            element = element->next;
        return element;
    }
}
