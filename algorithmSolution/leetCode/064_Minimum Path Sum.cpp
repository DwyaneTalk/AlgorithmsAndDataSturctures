/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Minimum Path Sum 
*             : https://leetcode.com/problems/minimum-path-sum/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MIN(a, b) ((a) > (b) ? (b) : (a))

int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int i, j, m = gridRowSize, n = gridColSize;
    for (i = 1; i < m; ++i) {
        grid[i][0] += grid[i - 1][0];
    }
    for (j = 1; j < n; ++j) {
        grid[0][j] += grid[0][j - 1];
    }

    for (i = 1; i < m; ++i) {
        for (j = 1; j < n; ++j) {
            grid[i][j] += MIN(grid[i - 1][j], grid[i][j - 1]);
        }
    }
    return grid[m - 1][n - 1];
}

int main() {
    int m = 3, n =2, i;
    int **grid = (int **)malloc(sizeof(int *)* m);
    for (i = 0; i < m; ++i) {
        grid[i] = (int *)malloc(sizeof(int)* n);
        grid[i][0] = 1 + i;
        grid[i][1] = 5 + i;
    }
    // construct the test cases here
    int ans = minPathSum(grid, m, n);
    printf("%d\n", ans);
    system("pause");
    return 0;
}