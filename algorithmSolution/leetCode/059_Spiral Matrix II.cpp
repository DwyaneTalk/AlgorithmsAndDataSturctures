/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Maximum Subarray
 *             : https://leetcode.com/problems/maximum-subarray/
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


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

int** generateMatrix(int n) {
    if(!n)  return NULL;
    int i, **ansMatrix = (int **)malloc(sizeof(int *) * n);
    for(i = 0; i < n; ++i)
        ansMatrix[i] = (int *)malloc(sizeof(int) * n);
    int crow, crow_e = n, irow_b = 0, irow_e = n - 1, icol_b = 0, icol_e = n - 1;
    i = 1;
    for (crow = 0; crow < crow_e; ++crow) {
        if (crow & 1) {
            while (icol_b > icol_e) {
                ansMatrix[irow_b][icol_b] = i++;
                --icol_b;
            }
            while (irow_b >= irow_e) {
                ansMatrix[irow_b][icol_b] = i++;
                --irow_b;
            }
            ++icol_b;
            icol_e = n - 1 - icol_b;
            ++irow_b;
            irow_e = n - 1 - irow_b;
        } else {
            while (icol_b < icol_e) {
                ansMatrix[irow_b][icol_b] = i++;
                ++icol_b;
            }
            while (irow_b <= irow_e) {
                ansMatrix[irow_b][icol_b] = i++;
                ++irow_b;
            }
            --icol_b;
            icol_e = n - 2 - icol_b;
            --irow_b;
            irow_e = n - irow_b;
        }
    }
    return ansMatrix;
}

int main() {
    int n = 4;
    int **ans = generateMatrix(n);
    printMatrix(ans, n, n);
    return 0;
}
