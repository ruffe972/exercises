#pragma once


//! Interface for printable objects comparable by len
class IComparable
{
public:
    //! constants for comparing two objects
    enum ComparisonResult
    {
        less = -1,
        equal,
        more
    };

    virtual ~IComparable() {}

    //! Compares two objects
    /*! @returns this <ComparisonResult> that */
    int compareTo(IComparable *that) const;

    //! Get object length
    int virtual len() const = 0;

    //! Print object
    void virtual print() const = 0;
};
