#include <cstdio>
#include "matrixGraph.h"
#include "stack.h"
#include "list.h"
using namespace stack;
using namespace list;


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


ListElement *findElementBeforeClosestVertex(int *distances, List *list)
{
    ListElement *resultElement = leftBarrier(list);
    ListElement *currentElement = leftmostElement(list);
    int minDistance = distances[value(currentElement)];
    while (next(currentElement))
    {
        int nextDistance = distances[value(next(currentElement))];
        if (nextDistance < minDistance)
            resultElement = currentElement;
        currentElement = next(currentElement);
    }
    return resultElement;
}


void printDayReport(int day, int city, int distance, int *parents)
{
    printf("Day %d: city %d, %d km\n", day, city, distance);
    Stack *stack = createStack();
    while (city != -1)
    {
        append(stack, city);
        city = parents[city];
    }
    printf("Route: ");
    print(stack);
    deleteStack(stack);
    printf("\n");
}


void matrixDijkstraPrintingReports(int **edgesLens, int verticesNumber, int startVertex)
{
    int *parents = new int[verticesNumber];
    //if the graph has only one component
    parents[startVertex] = -1;
    int *distances = new int[verticesNumber];
    for (int i = 0; i < verticesNumber; i++)
        distances[i] = inf;
    distances[startVertex] = 0;
    bool *visited = new bool[verticesNumber]();
    List *seenOrVisited = createList();
    append(seenOrVisited, startVertex);
    int day = 1;
    while (len(seenOrVisited) != 0)
    {
        ListElement *elementBeforeClosestVertex = findElementBeforeClosestVertex(distances, seenOrVisited);
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
        printDayReport(day, currentVertex, distances[currentVertex], parents);
        day++;
    }
    deleteList(seenOrVisited);
    delete[] visited;
    delete[] distances;
    delete[] parents;
}
