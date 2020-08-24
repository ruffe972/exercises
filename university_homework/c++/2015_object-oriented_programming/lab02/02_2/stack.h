#pragma once


//! Stack interface
template <typename T>
class Stack
{
public:
    virtual ~Stack() {}
    //! Get stack length
    int virtual len() const = 0;
    //! Print a stack
    /*! Stack bottom is on the left */
    void virtual print() const = 0;
    //! Put a new element on top of the stack
    /*! @param value - new element value */
    void virtual push(T value) = 0;
    //! Take away the topmost stack element
    /*! @returns removed element value */
    T virtual pop() = 0;
protected:
    Stack() : length(0) {}
    int length;
};
