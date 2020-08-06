#pragma once
#include "singly_linked_list.h"


//! List that containts no duplicate elements
template <typename T>
class UniqueList : public SinglyLinkedList<T>
{
public:
    //! Thrown when appending an already existing value
    class DuplicateElementError {};
    //! Append a new element to the list if there is no such element; otherwise throw an ex-n
    void append(const T &value);
    //! Remove an element; throw an exception if there is nothing to remove
    void remove(const T &value);
private:
    //! Check if there is such an element in the list
    /*! @return pointer to the previous element, or nullptr if there is no given element */
    typename SinglyLinkedList<T>::Element *findPrevious(const T &value);
};


template <typename T>
typename SinglyLinkedList<T>::Element* UniqueList<T>::findPrevious(const T &value)
{
    auto current = this->head;
    while (current->next && current->next->value != value)
        current = current->next;
    if (current->next)
        return current;
    return nullptr;
}


template <typename T>
void UniqueList<T>::append(const T &value)
{
    if (findPrevious(value))
        throw DuplicateElementError();
    else
        SinglyLinkedList<T>::append(value);
}


template <typename T>
void UniqueList<T>::remove(const T &value)
{
    auto previousElementOrNullptr = findPrevious(value);
    this->removeNext(previousElementOrNullptr);
}
