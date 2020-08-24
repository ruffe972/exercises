#include <stdio.h>

const int maxLen = 1000;


void scanMatrix(int array[][maxLen], int arrayWidth, int arrayHeight)
{
    for (int row = 0; row < arrayHeight; row++)
        for (int column = 0; column < arrayWidth; column++)
            scanf("%d", &array[row][column]);
}


int main()
{
    printf("Enter an odd positive integer: ");
    int matrixLen = 0;
    scanf("%d", &matrixLen);
    printf("Enter integer elements of the matrix %d x %d:\n", matrixLen, matrixLen);
    int matrix[maxLen][maxLen];
    scanMatrix(matrix, matrixLen, matrixLen);
    printf("Spiral path:\n");
    int curLen = 1;
    int row = matrixLen / 2;
    int column = row;
    printf("%d ", matrix[row][column]);
    column++;
    if (matrixLen != 1)
        printf("%d ", matrix[row][column]);
    while (curLen < matrixLen - 1)
    {
        for (int i = 1; i <= curLen; i++)
            printf("%d ", matrix[row + i][column]);
        row += curLen;
        curLen++;
        for (int i = 1; i <= curLen; i++)
            printf("%d ", matrix[row][column - i]);
        column -= curLen;
        for (int i = 1; i <= curLen; i++)
            printf("%d ", matrix[row - i][column]);
        row -= curLen;
        if (curLen < matrixLen - 1)
            curLen++;            
        for (int i = 1; i <= curLen; i++)
            printf("%d ", matrix[row][column + i]);                                
        column += curLen;
    }
}    