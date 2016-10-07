/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Spiral Matrix 
 *             : https://leetcode.com/problems/spiral-matrix/
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MIN(a, b) ((a) > (b) ? (b) : (a))

void printMatrix(int **matrix, int rowNum, int colNum) {
    int i, j;
    for (i = 0; i < rowNum; ++i) {
        for (j = 0; j < colNum; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int elemNums = matrixColSize * matrixRowSize;
    int *ans = (int *)malloc(sizeof(int)* elemNums);
    int crow, crow_e = MIN(matrixColSize, matrixRowSize), irow_b = 0, irow_e = matrixRowSize - 1, icol_b = 0, icol_e = matrixColSize - 1, i = -1;
    for (crow = 0; crow < crow_e; ++crow) {
        if (crow & 1) {
            while (icol_b > icol_e) {
                ans[++i] = matrix[irow_b][icol_b];
                --icol_b;
            }
            while (irow_b >= irow_e) {
                ans[++i] = matrix[irow_b][icol_b];
                --irow_b;
            }
            ++icol_b;
            icol_e = matrixColSize - 1 - icol_b;
            ++irow_b;
            irow_e = matrixRowSize - 1 - irow_b;
        } else {
            while (icol_b < icol_e) {
                ans[++i] = matrix[irow_b][icol_b];
                ++icol_b;
            }
            while (irow_b <= irow_e) {
                ans[++i] = matrix[irow_b][icol_b];
                ++irow_b;
            }
            --icol_b;
            icol_e = matrixColSize - 2 - icol_b;
            --irow_b;
            irow_e = matrixRowSize - irow_b;
        }
    }
    return ans;
}

int main() {
    int rowsize = 3, colsize = 4;
    int **matrix = (int **)malloc(sizeof(int *)* rowsize);
    for (int i = 0; i < rowsize; ++i) {
        matrix[i] = (int *)malloc(sizeof(int)* colsize);
        matrix[i][0] = 1 + i;
        matrix[i][1] = 2 + i;
        matrix[i][2] = 3 + i;
        matrix[i][3] = 4 + i;
    }
    printMatrix(matrix, rowsize, colsize);
    int *ans = spiralOrder(matrix, rowsize, colsize);
    for (int i = 0; i < colsize * rowsize; ++i)
        printf("%d ", ans[i]);
    system("pause");
    return 0;
}
