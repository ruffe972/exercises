#pragma once
#include <initializer_list>
#include <array>


/// Mathematical vector
template <typename T, size_t size>
class Vector
{
public:
    friend class VectorTest;
    class TooManyArgsInInitList {};
    /// Thrown when the size is 0 or bigger than the unsigned short int max value
    class InvalidVectorSize {};
    /// Create a new vector from the init. list
    Vector(const std::initializer_list<T> &list = {});
    // This is useless, because the compiler generates the same thing.
    // Vector(const Vector &that) { data = that.data; }
    /// Check if all the coordinates = 0
    bool isNull() const;
    /// Add two vectors
    const Vector operator+(const Vector &that) const;
    /// Vector subtraction
    const Vector operator-(const Vector &that) const;
    // Not overloaded because of the vector product
    /// Calculate dot product
    T dotProduct(const Vector &that) const;
private:
    std::array<T, size> data;
};


template <typename T, size_t size>
Vector<T, size>::Vector(const std::initializer_list<T> &list)
{
    if (size == 0 || size > USHRT_MAX)
        throw InvalidVectorSize();
    if (list.size() > size)
        throw TooManyArgsInInitList();
    size_t i = 0;
    auto listElement = list.begin();
    while (listElement != list.end() && i < list.size())
    {
        data[i++] = *listElement;
        ++listElement;
    }
    for (size_t i = list.size(); i < size; i++)
        data[i] = 0;
}


template <typename T, size_t size>
bool Vector<T, size>::isNull() const
{
    size_t i = 0;
    while (data[i] == 0 && i < size)
        ++i;
    return i == size;
}


template <typename T, size_t size>
const Vector<T, size> Vector<T, size>::operator+(const Vector &that) const
{
    Vector<T, size> sum;
    for (size_t i = 0; i < size; i++)
        sum.data[i] = data[i] + that.data[i];
    return sum;
}


template <typename T, size_t size>
const Vector<T, size> Vector<T, size>::operator-(const Vector &that) const
{
    Vector<T, size> residual;
    for (size_t i = 0; i < size; i++)
        residual.data[i] = data[i] - that.data[i];
    return residual;
}


template <typename T, size_t size>
T Vector<T, size>::dotProduct(const Vector &that) const
{
    T result = 0;
    for (size_t i = 0; i < size; i++)
        result += data[i] * that.data[i];
    return result;
}
