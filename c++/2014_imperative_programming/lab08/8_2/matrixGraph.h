#pragma once
#include <climits>

const int inf = INT_MAX;

bool **createUnweightedMatrix(int verticesNumber);
void deleteUnweightedMatrix(bool **matrix, int verticesNumber);

int **createWeightedMatrix(int verticesNumber);
void deleteWeightedMatrix(int **edgesLens, int verticesNumber);
void matrixDijkstraPrintingReports(int **edgesLens, int verticesNumber, int startVertex);
