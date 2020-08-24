#pragma once
#include "sorter.h"


//! Array QuickSorter
template <typename T>
class QuickSorter : public Sorter<T>
{
public:
    //! QuickSort an array
    void sort(vector<T> &array);
private:
    void sortSlice(vector<T> &array, int left, int right);
};


template <typename T>
void QuickSorter<T>::sort(vector<T> &array)
{
    if (array.size() != 0)
        QuickSorter::sortSlice(array, 0, array.size() - 1);
}


template <typename T>
void QuickSorter<T>::sortSlice(vector<T> &array, int left, int right)
{
    T median = array[left + (right - left) / 2];
    int i = left;
    int j = right;
    while (i <= j)
    {
        while (array[i] < median)
            ++i;
        while (array[j] > median)
            --j;
        if (i <= j)
        {
            std::swap(array[i], array[j]);
            ++i;
            --j;
        }
    }
    if (j > left)
        sortSlice(array, left, j);
    if (i < right)
        sortSlice(array, i, right);
}
