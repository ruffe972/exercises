#include <iostream>
#include "list.h"
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


    List **createArray(int verticesNumber)
    {
        List **array = new List*[verticesNumber];
        for (int i = 0; i < verticesNumber; i++)
            array[i] = createList();
        return array;
    }


    void deleteArray(List **array, int verticesNumber)
    {
        for (int i = 0; i < verticesNumber; i++)
            deleteList(array[i]);
        delete[] array;
    }    
}


void arrayBFS(List **graph, int verticesNumber, int startVertex)
{
    bool *seen = new bool[verticesNumber]();
    List *queue = createList();
    append(startVertex, queue);
    seen[startVertex] = true;
    char letter = 'a';
    while (len(queue) != 0)
    {
        int currentVertex = popLeft(queue);
        std::cout << currentVertex << ' ' << letter << '\n';
        letter++;
        ListElement *neighboorElement = first(graph[currentVertex]);
        while (neighboorElement)
        {
            int neighboorVertex = value(neighboorElement);
            if (!seen[neighboorVertex])
            {
                append(neighboorVertex, queue);
                seen[neighboorVertex] = true;
            }
            neighboorElement = next(neighboorElement);
        }
    }
    deleteList(queue);
    delete[] seen;
}
