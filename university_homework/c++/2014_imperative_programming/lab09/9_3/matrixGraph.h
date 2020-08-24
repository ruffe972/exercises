#pragma once
#include <climits>

const int inf = INT_MAX;

bool **createUnweightedMatrix(int verticesNumber);
void deleteUnweightedMatrix(bool **matrix, int verticesNumber);

int **createWeightedMatrix(int verticesNumber);
void deleteWeightedMatrix(int **edgesLens, int verticesNumber);

//The graph should be connected for these 2 algorithms
void matrixDijkstra(int **edgesLens, int verticesNumber, int startVertex);
void matrixPrim(int **edgesLens, int verticesNumber, int startVertex);
