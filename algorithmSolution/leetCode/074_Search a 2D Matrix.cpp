/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Search a 2D Matrix
*             : https://leetcode.com/submissions/detail/28746129/
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

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int lo = 0, hi = matrixRowSize - 1, mid, row;
    if (target < matrix[0][0])  return false;
    while (lo < hi) {
        if (lo + 1 == hi) {
            if (matrix[hi][0] <= target)    ++lo;
            else                            --hi;
        } else {
            mid = (lo + hi) / 2;
            if (matrix[mid][0] <= target)   lo = mid;
            else                            hi = mid - 1;
        }
    }
    row = lo;
    lo = 0;
    hi = matrixColSize - 1;
    while (lo <= hi) {
        mid = (lo + hi);
        if (matrix[row][mid] == target) return true;
        if (matrix[row][mid] > target)  hi = mid - 1;
        else                            lo = mid + 1;
    }
    return false;
}
int main() {
    int size = 4;
    int **matrix = (int **)malloc(sizeof(int *)* size);
    for (int i = 0; i < size; ++i) {
        matrix[i] = (int *)malloc(sizeof(int)* size);
        matrix[i][0] = 1 + i * 5;
        matrix[i][1] = 2 + i * 5;
        matrix[i][2] = 3 + i * 5;
        matrix[i][3] = 4 + i * 5;
    }
    int target = 0;
    printMatrix(matrix, size, size);
    bool ans = searchMatrix(matrix, size, size, target);
    if (ans)    printf("Yes!\n");
    else        printf("No!!\n");
    system("pause");
    return 0;
}
