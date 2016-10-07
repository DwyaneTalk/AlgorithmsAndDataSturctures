/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Set Matrix Zeroes
*             : https://leetcode.com/problems/set-matrix-zeroes/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void printMatrix(int **matrix, int rowsize, int colsize) {
    int i, j;
    for (i = 0; i < rowsize; ++i) {
        for (j = 0; j < colsize; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void setZeroes(int **matrix, int matrixRowSize, int matrixColSize) {
    int irow, icol, val = 1;
    for (irow = 0; irow < matrixRowSize; ++irow) {
        if (!matrix[irow][0]) {
            matrix[irow][0] = 0;
            val = 0;
        }
        for (icol = 1; icol < matrixColSize; ++icol) {
            if (!matrix[irow][icol]) {
                matrix[irow][0] = 0;
                matrix[0][icol] = 0;
            }
        }
    }
    for (irow = matrixRowSize - 1; irow >= 0; --irow) {
        for (icol = 1; icol < matrixColSize; ++icol) {
            if (!matrix[irow][0] || !matrix[0][icol])
                matrix[irow][icol] = 0;
        }
        if (!val)   matrix[irow][0] = 0;
    }
}

int main() {
    int size = 4;
    int **matrix = (int **)malloc(sizeof(int *)* size);
    for (int i = 0; i < size; ++i) {
        matrix[i] = (int *)malloc(sizeof(int)* size);
        matrix[i][0] = 1 - i;
        matrix[i][1] = 2 + i;
        matrix[i][2] = 4 - i;
        matrix[i][3] = 4 + i;
    }
    printMatrix(matrix, size, size);
    setZeroes(matrix, size, size);
    printMatrix(matrix, size, size);
    system("pause");
    return 0;
}
