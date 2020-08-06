#pragma once
#include <functional>
#include <array>
#include <list>
#include <string>


/// Chained hash table with linked lists
class HashTable
{
public:
    typedef unsigned short int HashType;
    static const int maxHash = USHRT_MAX;
    typedef std::function<HashType(const std::string&)> HashFunction;

    /// Create a new table with the given hash function
    HashTable(HashFunction tableHashFunction = polynomialHash) : hash(tableHashFunction) {}

    /// Check if the string is in the hash table
    bool find(const std::string &string) const;

    /// Add a string to the hash table
    void add(const std::string &string);

    /// Remove a string from the hash table
    void remove(const std::string &string);

    /// Show information about the hash table
    void showStatistics() const;
private:
    static HashType polynomialHash(const std::string &string);
    bool find(HashType listIndex, const std::string &string) const;
    std::array<std::list<std::string>, maxHash> data;
    HashFunction hash;
};
