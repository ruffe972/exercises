#pragma once
#include "list.h"

namespace graph
{
    bool **createMatrix(int verticesNumber);
    void deleteMatrix(bool **matrix, int verticesNumber);
    List **createArray(int verticesNumber);
    void deleteArray(List **array, int verticesNumber);
}

void arrayBFS(List **graph, int verticesNumber, int startVertex);