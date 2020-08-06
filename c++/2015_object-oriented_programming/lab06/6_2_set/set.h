#pragma once
#include <list>
#include <iterator>
#include <algorithm>


/// Inefficient implementation of ADT "Set"
template<typename T>
class Set
{
public:
    /// Get the set size
    int size() const;
    /// Check if the value exists in the set
    bool exists(const T &value) const;
    /// Remove value from the set
    void remove(const T &value);
    /// Add value to the set
    void add(const T &value);
    /// Merge 'that' set into 'this' set
    void unite(const Set<T> &that);
    /// Overwrite 'this' set with the intersection of 'this' and 'that' sets
    void intersect(const Set<T> &that);
private:
    std::list<T> data;
};


template<typename T>
bool Set<T>::exists(const T &value) const
{
    return std::find(data.begin(), data.end(), value) != data.end();
}


template<typename T>
void Set<T>::remove(const T &value)
{
    data.remove(value);
}


template<typename T>
void Set<T>::add(const T &value)
{
    auto it = data.begin();
    while (it != data.end() && *it < value)
    {
        it++;
    }
    if (it == data.end() || *it != value)
    {
        data.insert(it, value);
    }
}


template<typename T>
int Set<T>::size() const
{
    return data.size();
}


template<typename T>
void Set<T>::unite(const Set<T> &that)
{
    for (auto const &value: that.data)
    {
        add(value);
    }
}


template<typename T>
void Set<T>::intersect(const Set<T> &that)
{
    for (auto &elemOfThis: data)
    {
        if (!that.exists(elemOfThis))
        {
            remove(elemOfThis);
        }
    }
}
