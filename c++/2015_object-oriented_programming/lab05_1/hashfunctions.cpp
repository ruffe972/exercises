#include "hashfunctions.h"


HashTable::HashType sumHash(const std::string &string)
{
    HashTable::HashType result = 0;
    for (auto character: string)
        result += character;
    return result;
}
