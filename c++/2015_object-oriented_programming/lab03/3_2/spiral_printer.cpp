#include "spiral_printer.h"


void SpiralPrinter::purePrint(const Matrix<int> &matrix, std::ostream &output) const
{
    output << "Spiral path:\n";
    int matrixLen = matrix.width();
    int currentLen = 1;
    int row = matrixLen / 2;
    int column = row;
    output << matrix(row, column) << ' ';
    column++;
    if (matrixLen != 1)
        output << matrix(row, column) << ' ';
    while (currentLen < matrixLen - 1)
    {
        for (int i = 1; i <= currentLen; i++)
            output << matrix(row + i, column) << ' ';
        row += currentLen;
        currentLen++;
        for (int i = 1; i <= currentLen; i++)
            output << matrix(row, column - i) << ' ';
        column -= currentLen;
        for (int i = 1; i <= currentLen; i++)
            output << matrix(row - i, column) << ' ';
        row -= currentLen;
        if (currentLen < matrixLen - 1)
            currentLen++;
        for (int i = 1; i <= currentLen; i++)
            output << matrix(row, column + i) << ' ';
        column += currentLen;
    }
}
