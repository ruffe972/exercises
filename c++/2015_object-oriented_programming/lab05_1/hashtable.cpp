#include <iostream>
#include <algorithm>
#include "hashtable.h"


bool HashTable::find(HashType listIndex, const std::string &string) const
{
    auto list = &data[listIndex];
    return std::find(list->begin(), list->end(), string) != list->end();
}


bool HashTable::find(const std::string &string) const
{
    return find(hash(string), string);
}


void HashTable::add(const std::string &string)
{
    HashType currentHash = hash(string);
    if (!find(currentHash, string))
        data[currentHash].push_back(string);
}


void HashTable::remove(const std::string &string)
{
    data[hash(string)].remove(string);
}


void HashTable::showStatistics() const
{
    using std::cout;
    int nonEmptyListsNumber = 0;
    int longestListLength = 0;
    int listLengthsSum = 0;
    for (auto list: data)
        if (!list.empty())
        {
            nonEmptyListsNumber++;
            longestListLength = std::max((int)list.size(), longestListLength);
            listLengthsSum += list.size();
        }
    cout << std::fixed;
    cout.precision(10);
    cout << "Load factor: " << (double)nonEmptyListsNumber / maxHash;
    cout << "\nNumber of empty cells: " << maxHash - nonEmptyListsNumber << " / " << maxHash;
    cout << "\nThe longest chain contains " << longestListLength << " word(s)";
    cout << "\nAverage chain length: ";
    cout << (nonEmptyListsNumber == 0 ? 0 : (double)listLengthsSum / nonEmptyListsNumber);
    cout << "\nUnique strings number: " << listLengthsSum << "\n\n";
}


HashTable::HashType HashTable::polynomialHash(const std::string &string)
{
    HashType result = 0;
    HashType power = 1;
    for (auto character: string)
    {
        result += power * character;
        power *= 101;
    }
    return result;
}
