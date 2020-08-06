#pragma once
#include <algorithm>


/// Smart pointers with the shared ownership of objects
template <typename T>
class SharedPointer
{
public:
    class EmptyPointerDereferenceException {};
    /// Warp a raw pointer inside a smart pointer
    SharedPointer(T *rawPointer = nullptr) :
        rawPointer(rawPointer), counter(rawPointer ? new int(1) : nullptr) {}
    /// Self-destroy only if unique
    ~SharedPointer() { removeOwnership(); }
    /// Shallow copy
    SharedPointer(const SharedPointer &that) { becomeOwner(that); }
    /// Shallow assignment
    SharedPointer<T> &operator=(const SharedPointer &that);
    /// Dereference the raw pointer
    T &operator*();
    /// Get the owners amount
    int usageCounter() const { return counter ? *counter : 0; }
private:
    void removeOwnership();
    void becomeOwner(const SharedPointer &that);
    T *rawPointer;
    int *counter;
};


template <typename T>
void SharedPointer<T>::removeOwnership()
{
    if (rawPointer)
    {
        if (*counter > 1)
            *counter -= 1;
        else
        {
            delete rawPointer;
            delete counter;
        }
    }
}


template <typename T>
void SharedPointer<T>::becomeOwner(const SharedPointer &that)
{
    rawPointer = that.rawPointer;
    counter = that.counter;
    if (counter)
        *counter += 1;
}


template <typename T>
SharedPointer<T> &SharedPointer<T>::operator=(const SharedPointer &that)
{
    if (rawPointer != that.rawPointer)
    {
        removeOwnership();
        becomeOwner(that);
    }
    return *this;
}


template <typename T>
T &SharedPointer<T>::operator*()
{
    if (!rawPointer)
        throw EmptyPointerDereferenceException();
    return *rawPointer;
}
