/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Number of Islands
*             : https://leetcode.com/problems/number-of-islands/
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int direction[4][2] = {
    { -1, 0 },
    { 1, 0 },
    { 0, 1 },
    { 0, -1 }
};

void DFS_map(char **grid, int numRows, int numColumns, int irow, int icol, int *visited) {
    visited[irow * numColumns + icol] = 1;
    int i, next_row, next_col;
    for (i = 0; i < 4; ++i) {
        next_row = irow + direction[i][0];
        next_col = icol + direction[i][1];
        if (next_row >= 0 && next_row < numRows && next_col >= 0 && next_col < numColumns && !visited[next_row * numColumns + next_col] && grid[next_row][next_col] == '1') {
            DFS_map(grid, numRows, numColumns, next_row, next_col, visited);
        }
    }
}

int numIslands(char **grid, int numRows, int numColumns) {
    int *visited = (int *)malloc(sizeof(int)* (numRows * numColumns));
    int ans = 0;
    int irow, icol;
    memset(visited, 0, sizeof(int)* (numRows * numColumns));
    for (irow = 0; irow < numRows; ++irow) {
        for (icol = 0; icol < numColumns; ++icol) {
            if (grid[irow][icol] == '1' && !visited[irow * numColumns + icol]) {
                ans++;
                DFS_map(grid, numRows, numColumns, irow, icol, visited);
            }
        }
    }
    return ans;
}

int main() {
    //char grid[][10] = {
    //    "11110",
    //    "11010",
    //    "11000",
    //    "00000"
    //};
    char *grid[4];
    grid[0] = "11000";
    grid[1] = "11000";
    grid[2] = "00100";
    grid[3] = "00011";
    //grid[4] = "";
    int ans, numRows = 4, numColumns = 5;
    ans = numIslands(grid, numRows, numColumns);
    printf("%d\n", ans);
    system("pause");
    return 0;
}
