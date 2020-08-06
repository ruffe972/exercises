#include <iostream>
#include "graph.h"
using std::cin;
using std::cout;
using std::endl;


void DFSPrintingVertices(bool visited[], int vertex, bool **graph, int verticesNumber)
{
    cout << vertex << ' ';
    visited[vertex] = true;
    for (int i = 0; i < verticesNumber; i++)
        if (!visited[i] && graph[vertex][i])
            DFSPrintingVertices(visited, i, graph, verticesNumber);
}


int main()
{
    cout << "Enter the number of vertices (the numeration starts from 0): ";
    int verticesNumber = 0;
    cin >> verticesNumber;
    cout << endl << "Enter the edges in format <vertex vertex\\n>.";
    cout << "An empty line stops the input." << endl;
    cin.get();
    bool **graph = graph::createMatrix(verticesNumber);
    while (cin.get() != '\n')
    {
        cin.unget();
        int vertex1 = 0;
        int vertex2 = 0;
        cin >> vertex1 >> vertex2;
        graph[vertex1][vertex2] = true;
        graph[vertex2][vertex1] = true;
        cin.get();
    }

    cout << "Graph components (each line is a component):" << endl;
    bool *visited = new bool[verticesNumber]();
    for (int i = 0; i < verticesNumber; i++)
        if (!visited[i])
        {
            DFSPrintingVertices(visited, i, graph, verticesNumber);
            cout << endl;
        }

    delete[] visited;
    graph::deleteMatrix(graph, verticesNumber);
    cout << endl;
    return 0;
}
