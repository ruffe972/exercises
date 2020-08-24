#pragma once
#include <utility>
#include <vector>
using std::vector;

//! Array sorter interface
template <typename T>
class Sorter
{
public:
    virtual ~Sorter() {}
    //! Sort an array
    void virtual sort(vector<T> &array) = 0;
};
