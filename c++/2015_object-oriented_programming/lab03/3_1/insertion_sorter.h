#pragma once
#include "sorter.h"


//! Array insertion sorter
template <typename T>
class InsertionSorter : public Sorter<T>
{
public:
    //! Sort an array with the insertion sort
    void sort(vector<T> &array);
};


template <typename T>
void InsertionSorter<T>::sort(vector<T> &array)
{
    for (unsigned int i = 1; i < array.size(); i++)
    {
        unsigned int j = i;
        while (j > 0 && array[j] < array[j - 1])
        {
            std::swap(array[j], array[j - 1]);
            j--;
        }
    }
}
