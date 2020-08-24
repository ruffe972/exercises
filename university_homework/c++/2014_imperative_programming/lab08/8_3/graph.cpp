#include "graph.h"


namespace graph
{
    bool **createMatrix(int verticesNumber)
    {
        bool **matrix = new bool*[verticesNumber];
        for (int i = 0; i < verticesNumber; i++)
            matrix[i] = new bool[verticesNumber]();
        return matrix;
    }


    void deleteMatrix(bool **matrix, int verticesNumber)
    {
        for (int i = 0; i < verticesNumber; i++)
            delete[] matrix[i];
        delete[] matrix;
    }
}
