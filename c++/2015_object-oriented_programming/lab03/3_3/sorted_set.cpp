#include <iostream>
#include "sorted_set.h"


SortedSet::SortedSet() : length(0), head(new Element(nullptr, nullptr)) {}


SortedSet::~SortedSet()
{
    Element *current = head;
    while (current)
    {
        Element *afterCurrent = current->next;
        delete current;
        current = afterCurrent;
    }
}


void SortedSet::removeNextIfNeeded(Element *preValueElement, IComparable *value)
{
    Element *current = preValueElement->next;
    if (current && value->compareTo(current->value) == IComparable::equal)
    {
        Element *postValueElement = current->next;
        delete current;
        preValueElement->next = postValueElement;
        length--;
    }
}


void SortedSet::add(IComparable *value)
{
    Element *preValueElement = elementBeforeValue(value);
    removeNextIfNeeded(preValueElement, value);
    Element *newElement = new Element(value, preValueElement->next);
    preValueElement->next = newElement;
    length++;
}


void SortedSet::remove(IComparable *value)
{
    removeNextIfNeeded(elementBeforeValue(value), value);
}


int SortedSet::len() const
{
    return length;
}


void SortedSet::print() const
{
    Element *current = head->next;
    while (current)
    {
        current->value->print();
        current = current->next;
    }
    std::cout << '\n';
}


SortedSet::Element* SortedSet::elementBeforeValue(IComparable *value) const
{
    Element *current = head;
    while (current->next && value->compareTo(current->next->value) == IComparable::more)
        current = current->next;
    return current;
}


SortedSet::Element::Element(IComparable *value, Element *next) : value(value), next(next) {}


SortedSet::Element::~Element()
{
    delete value;
}
