#include <iostream>
#include "matrixGraph.h"
#include "list.h"
using namespace list;
using std::cout;
using std::endl;


bool **createUnweightedMatrix(int verticesNumber)
{
    bool **matrix = new bool*[verticesNumber];
    for (int i = 0; i < verticesNumber; i++)
        matrix[i] = new bool[verticesNumber]();
    return matrix;
}


void deleteUnweightedMatrix(bool **matrix, int verticesNumber)
{
    for (int i = 0; i < verticesNumber; i++)
        delete[] matrix[i];
    delete[] matrix;
}


int **createWeightedMatrix(int verticesNumber)
{
    int **matrix = new int*[verticesNumber];
    for (int i = 0; i < verticesNumber; i++)
    {
        matrix[i] = new int[verticesNumber];
        for (int j = 0; j < verticesNumber; j++)
            matrix[i][j] = inf;
    }
    return matrix;
}


void deleteWeightedMatrix(int **edgesLens, int verticesNumber)
{
    for (int i = 0; i < verticesNumber; i++)
        delete[] edgesLens[i];
    delete[] edgesLens;
}


ListElement *findElementBeforeOneWithMinArrayValue(int *array, List *list)
{
    ListElement *resultElement = leftBarrier(list);
    ListElement *currentElement = leftmostElement(list);
    int minArrayValue = array[value(currentElement)];
    while (next(currentElement))
    {
        int nextArrayValue = array[value(next(currentElement))];
        if (nextArrayValue < minArrayValue)
            resultElement = currentElement;
        currentElement = next(currentElement);
    }
    return resultElement;
}


void matrixDijkstra(int **edgesLens, int verticesNumber, int startVertex)
{
    int *parents = new int[verticesNumber];
    parents[startVertex] = -1;
    int *distances = new int[verticesNumber];
    for (int i = 0; i < verticesNumber; i++)
        distances[i] = inf;
    distances[startVertex] = 0;
    bool *visited = new bool[verticesNumber]();
    List *seenOrVisited = createList();
    append(seenOrVisited, startVertex);
    while (len(seenOrVisited) != 0)
    {
        ListElement *elementBeforeClosestVertex = findElementBeforeOneWithMinArrayValue(distances, seenOrVisited);
        int currentVertex = value(next(elementBeforeClosestVertex));
        visited[currentVertex] = true;
        for (int i = 0; i < verticesNumber; i++)
            if (edgesLens[currentVertex][i] != inf && !visited[i])
            {
                int newPath = distances[currentVertex] + edgesLens[currentVertex][i];
                if (newPath < distances[i])
                {
                    if (distances[i] == inf)
                        append(seenOrVisited, i);
                    distances[i] = newPath;
                    parents[i] = currentVertex;
                }
            }
        removeNext(seenOrVisited, elementBeforeClosestVertex);
        cout << currentVertex << ' ' << distances[currentVertex] << endl;
    }
    deleteList(seenOrVisited);
    delete[] visited;
    delete[] distances;
    delete[] parents;
}


void matrixPrim(int **edgesLens, int verticesNumber, int startVertex)
{
    int *parents = new int[verticesNumber];
    parents[startVertex] = -1;
    int *minEdges = new int[verticesNumber];
    for (int i = 0; i < verticesNumber; i++)
        minEdges[i] = inf;
    minEdges[startVertex] = 0;
    bool *visited = new bool[verticesNumber]();
    List *seenOrVisited = createList();
    append(seenOrVisited, startVertex);
    while (len(seenOrVisited) != 0)
    {
        ListElement *elementBeforeCurrent = findElementBeforeOneWithMinArrayValue(minEdges, seenOrVisited);
        int currentVertex = value(next(elementBeforeCurrent));
        visited[currentVertex] = true;
        for (int i = 0; i < verticesNumber; i++)
            if (edgesLens[currentVertex][i] < minEdges[i] && !visited[i])
            {
                if (minEdges[i] == inf)
                    append(seenOrVisited, i);
                minEdges[i] = edgesLens[currentVertex][i];
                parents[i] = currentVertex;
            }
        removeNext(seenOrVisited, elementBeforeCurrent);
        if (currentVertex != startVertex)
            cout << currentVertex << ' ' << parents[currentVertex] << endl;
    }
    deleteList(seenOrVisited);
    delete[] visited;
    delete[] minEdges;
    delete[] parents;
}
