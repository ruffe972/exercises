#include <iostream>
#include <fstream>
#include "standard.h"
#include "matrixGraph.h"
using std::cout;
using std::endl;


int main()
{    
    cout << "The graph must be connected." << endl << "Enter the file name: ";
    char *fileName = getFileName("input.txt");
    cout << "Minimum spanning tree edges:" << endl;
    std::ifstream input;
    input.open(fileName);
    delete[] fileName;
    int verticesNumber = 0;
    input >> verticesNumber;
    int vertexFrom = 0;
    int **edgesLens = createWeightedMatrix(verticesNumber);
    while (input >> vertexFrom)
    {
        int vertexTo = 0;
        input >> vertexTo;
        int len = 0;
        input >> len;
        edgesLens[vertexFrom][vertexTo] = len;
        edgesLens[vertexTo][vertexFrom] = len;
    }
    input.close();   
    matrixPrim(edgesLens, verticesNumber, 1);
    deleteWeightedMatrix(edgesLens, verticesNumber);
    return 0;
}
