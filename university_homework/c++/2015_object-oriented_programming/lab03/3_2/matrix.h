#pragma once
#include <iostream>


//! Matrix class
template <typename T>
class Matrix
{
public:
    //! Create matrix with the given dimensions
    Matrix(int width, int height);
    //! Pseudo-destructor, deletes object data
    /*! Is useful with the static object */
    void deleteData();
    ~Matrix();
    //! Get matrix width
    int width() const;
    //! Get matrix height
    int height() const;
    //! Read matrix elements from input
    void read(std::istream &input);
    //! Print matrix
    void print() const;
    //! Access matrix[row][col] element
    T operator()(int row, int col) const;
    //! Modify matrix[row][col] element
    T &operator()(int row, int col);
private:
    int width_;
    int height_;
    T **data;
};

template <typename T>
Matrix<T>::Matrix(int width, int height) : width_(width), height_(height), data(new T*[height_])
{
    for (int row = 0; row < height_; row++)
        data[row] = new T[width_]();
}


template <typename T>
void Matrix<T>::deleteData()
{
    for (int row = 0; row < height_; row++)
        delete[] data[row];
    delete[] data;
}


template <typename T>
Matrix<T>::~Matrix()
{
    if (data)
        deleteData();
}


template <typename T>
int Matrix<T>::width() const
{
    return width_;
}


template <typename T>
int Matrix<T>::height() const
{
    return height_;
}


template <typename T>
void Matrix<T>::read(std::istream &input)
{
    for (int row = 0; row < height_; row++)
        for (int column = 0; column < width_; column++)
            input >> data[row][column];
}


template <typename T>
void Matrix<T>::print() const
{
    for (int row = 0; row < height_; row++)
    {
        for (int column = 0; column < width_; column++)
            std::cout << data[row][column] << ' ';
        std::cout << '\n';
    }
}


template <typename T>
T Matrix<T>::operator()(int row, int col) const
{
    return data[row][col];
}


template <typename T>
T &Matrix<T>::operator()(int row, int col)
{
    return data[row][col];
}
