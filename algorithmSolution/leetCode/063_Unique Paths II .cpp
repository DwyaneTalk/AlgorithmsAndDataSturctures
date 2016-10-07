/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Unique Paths II 
*             : https://leetcode.com/problems/unique-paths-ii/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    int lookup[100][100];
    int i, j, m = obstacleGridRowSize, n = obstacleGridColSize;
    if (obstacleGrid[0][0])  lookup[0][0] = 0;
    else    lookup[0][0] = 1;
    for (i = 1; i < m; ++i) {
        if (obstacleGrid[i][0])  lookup[i][0] = 0;
        else    lookup[i][0] = lookup[i - 1][0];
    }
    for (j = 1; j < n; ++j) {
        if (obstacleGrid[0][j])  lookup[0][j] = 0;
        else    lookup[0][j] = lookup[0][j - 1];
    }

    for (i = 1; i < m; ++i) {
        for (j = 1; j < n; ++j) {
            if (obstacleGrid[i][j])    lookup[i][j] = 0;
            else    lookup[i][j] = lookup[i - 1][j] + lookup[i][j - 1];
        }
    }
    return lookup[m - 1][n - 1];
}

int main() {
    int m = 34, n =24, i;
    int **grid = (int **)malloc(sizeof(int *)* m);
    for (i = 0; i < m; ++i)
        grid[i] = (int *)malloc(sizeof(int)* n);
    // construct the test cases here
    int ans = uniquePathsWithObstacles(grid, m, n);
    printf("%d\n", ans);
    system("pause");
    return 0;
}