/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode85  : Maximal Rectangle
*                : https://leetcode.com/problems/maximal-rectangle/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX(a, b)   ((a) > (b) ? (a) : (b))
#define MIN(a, b)   ((a) > (b) ? (b) : (a))

int maximalRectangle(char** matrix, int matrixRowSize, int matrixColSize) {
    if (!matrix || !matrixColSize || !matrixRowSize)    return 0;
    int max_ans = 0;
    int curr_left, curr_right;
    int *left = (int*)calloc(matrixColSize, sizeof(int));
    int *right = (int*)malloc(matrixColSize * sizeof(int));
    int *height = (int*)calloc(matrixColSize, sizeof(int));
    for (int ii = 0; ii < matrixColSize; ++ii)
        right[ii] = matrixColSize - 1;
    for (int i = 0; i < matrixRowSize; ++i) {
        curr_left = 0;
        curr_right = matrixColSize - 1;
        for (int j = 0; j < matrixColSize; ++j) {
            if (matrix[i][j] == '1') {
                left[j] = MAX(left[j], curr_left);
            } else {
                left[j] = 0;
                curr_left = j + 1;
            }
        }

        for (int j = matrixColSize - 1; j >= 0; --j) {
            if (matrix[i][j] == '1') {
                right[j] = MIN(right[j], curr_right);
            } else {
                right[j] = matrixColSize - 1;
                curr_right = j - 1;
            }
        }

        for (int j = 0; j < matrixColSize; ++j) {
            if (matrix[i][j] == '1')    ++height[j];
            else    height[j] = 0;
        }

        for (int j = 0; j < matrixColSize; ++j) {
            max_ans = MAX(max_ans, height[j] * (right[j] - left[j] + 1));
        }
    }
    free(left);
    free(right);
    free(height);
    return max_ans;
}

int main() {
    char *matrix[3];
    matrix[0] = new char[8];
    matrix[1] = new char[8];
    matrix[2] = new char[8];
    matrix[0] = "0001000";
    matrix[1] = "0011100";
    matrix[2] = "0111110";
    int ans = maximalRectangle((char**)matrix, 3, 7);
    printf("%d\n", ans);
    system("pause");
    return 0;
}
