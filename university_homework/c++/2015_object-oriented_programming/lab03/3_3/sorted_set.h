#pragma once
#include "i_comparable.h"


//! Sorted set of printable objects comparable by length
class SortedSet
{
public:
    //! Create empty set
    SortedSet();
    ~SortedSet();
    //! Add object to the set
    /*! Deletes object with the same length before addition */
    void add(IComparable *value);
    //! Remove object with the same length
    void remove(IComparable *value);
    //! Get set length
    int len() const;
    //! Print set
    void print() const;
private:
    class Element
    {
    public:
        Element(IComparable *value, Element *next);
        ~Element();
        IComparable *value;
        Element *next;
    };
    Element *elementBeforeValue(IComparable *value) const;
    void removeNextIfNeeded(Element *preValueElement, IComparable *value);
    int length;
    Element *head;
};
