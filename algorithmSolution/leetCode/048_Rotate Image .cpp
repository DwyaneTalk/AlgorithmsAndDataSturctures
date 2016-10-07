/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Rotate Image   
 *             : https://leetcode.com/problems/rotate-image/
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// 沿主对角线对称
void operation1(int **matrix, int size) {
    int i, j;
    for (i = 1; i < size; ++i) {
        for (j = 0; j < i; ++j) {
            swap(&matrix[i][j], &matrix[j][i]);
        }
    }
}

// 左右对称
void operation2(int **matrix, int size) {
    int i, j, k;
    for (i = 0; i < size; ++i) {
        for (j = 0, k = size - 1; j < k; ++j, --k) {
            swap(&matrix[i][j], &matrix[i][k]);
        }
    }
}

void printMatrix(int **matrix, int size) {
    int i, j;
    for (i = 0; i < size; ++i) {
        for (j = 0; j < size; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    if (!matrix || matrixColSize != matrixRowSize)  return;
    //printMatrix(matrix, matrixRowSize);
    operation1(matrix, matrixRowSize);
    //printMatrix(matrix, matrixRowSize);
    operation2(matrix, matrixRowSize);
    //printMatrix(matrix, matrixRowSize);
}

int main() {
    int size = 4;
    int **matrix = (int **)malloc(sizeof(int *) * size);
    for (int i = 0; i < size; ++i) {
        matrix[i] = (int *)malloc(sizeof(int)* size);
        matrix[i][0] = 1 + i;
        matrix[i][1] = 2 + i;
        matrix[i][2] = 3 + i;
        matrix[i][3] = 4 + i;
    }
    rotate(matrix, size, size);
    system("pause");
    return 0;
}
