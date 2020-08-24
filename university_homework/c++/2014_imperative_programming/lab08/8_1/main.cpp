#include <iostream>
#include <fstream>
#include <cstring>
#include "list.h"
#include "graph.h"
using std::cin;
using std::cout;
using std::endl;


char *askForFileName(const char *message, const char *defaultName)
{
    cout << message;
    const int maxFileNameLen = 256;
    char *fileName = new char[maxFileNameLen];
    cin.getline(fileName, maxFileNameLen);
    if (strlen(fileName) == 0)
    {
        cout << defaultName << endl;
        strcpy(fileName, defaultName);
    }
    return fileName;
}


int main()
{
    char *fileName = askForFileName("Input file: ", "graph.txt");
    std::ifstream graphFile;
    graphFile.open(fileName);
    delete[] fileName;
    cout << "Start vertex: ";
    int startVertex = 0;
    cin >> startVertex;

    int verticesNumber = 0;
    graphFile >> verticesNumber;
    List **graph = graph::createArray(verticesNumber);
    int vertexFrom = 0;
    while (graphFile >> vertexFrom)
    {
        int vertexTo = 0;
        graphFile >> vertexTo;
        append(vertexTo, graph[vertexFrom]);
    }
    graphFile.close();
    arrayBFS(graph, verticesNumber, startVertex);
    graph::deleteArray(graph, verticesNumber);
    cout << endl;
    return 0;
}
