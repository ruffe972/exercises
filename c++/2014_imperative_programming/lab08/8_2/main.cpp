#include <iostream>
#include <fstream>
#include "standard.h"
#include "matrixGraph.h"


int main()
{    
    std::cout << "Enter the file name: ";
    char *fileName = getFileName("input.txt");
    std::ifstream input;
    input.open(fileName);
    delete[] fileName;
    int citiesNumber = 0;
    int roadsNumber = 0;
    input >> citiesNumber >> roadsNumber;
    //adding barrier city #0
    citiesNumber++;
    int cityFrom = 0;
    int **roadsLens = createWeightedMatrix(citiesNumber);
    while (input >> cityFrom)
    {
        int cityTo = 0;
        input >> cityTo;
        int len = 0;
        input >> len;
        roadsLens[cityFrom][cityTo] = len;
        roadsLens[cityTo][cityFrom] = len;
    }
    input.close();
    matrixDijkstraPrintingReports(roadsLens, citiesNumber, 1);
    deleteWeightedMatrix(roadsLens, citiesNumber);    
    return 0;
}
