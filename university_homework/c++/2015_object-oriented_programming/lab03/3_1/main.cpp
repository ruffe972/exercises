#include <iostream>
#include <fstream>
#include <vector>
#include "standard.h"
#include "quick_sorter.h"
#include "quick_sorter_test.h"
#include "insertion_sorter.h"
#include "insertion_sorter_test.h"
using std::cout;


//! Print an int vector
void print(const std::vector<int> &array)
{
    for (auto number : array)
        cout << number << ' ';
    cout << '\n';
}


int main()
{
    InsertionSorterTest insertionSorterTest;
    QuickSorterTest quickSorterTest;
    if (QTest::qExec(&insertionSorterTest) != 0 || QTest::qExec(&quickSorterTest) != 0)
        return -1;
    cout << "\nEnter the input file name with the array length and its elements:\n";
    auto fileName = readFileName("input.txt");
    std::ifstream input(fileName);
    delete fileName;
    int arrayLen = 0;
    input >> arrayLen;
    std::vector<int> arrayForQSort(arrayLen);
    for (UInt i = 0; i < arrayForQSort.size(); i++)
        input >> arrayForQSort[i];
    input.close();
    cout << "Unsorted array:\n";
    print(arrayForQSort);
    std::vector<int> arrayForInsertionSort = arrayForQSort;

    Sorter<int> *sorter = new QuickSorter<int>;
    sorter->sort(arrayForQSort);
    cout << "\nQuickSorted array:\n";
    print(arrayForQSort);
    delete sorter;

    sorter = new InsertionSorter<int>;
    sorter->sort(arrayForInsertionSort);
    delete sorter;
    cout << "\nArray, sorted by insertion sort\n";
    print(arrayForInsertionSort);
    cout << '\n';
    return 0;
}
