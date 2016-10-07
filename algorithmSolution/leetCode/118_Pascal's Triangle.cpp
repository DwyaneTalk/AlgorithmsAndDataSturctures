/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode118  : Pascal's Triangle
*                : https://leetcode.com/problems/pascals-triangle/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int** generate(int numRows, int** columnSizes) {
    if (numRows <= 0) {
        *columnSizes = NULL;
        return NULL;
    }
    *columnSizes = (int*)malloc(sizeof(int) * numRows);
    int** ans = (int**)malloc(sizeof(int*) * numRows);
    for (int i = 0; i < numRows; ++i) {
        ans[i] = (int*)malloc(sizeof(int)* (i + 1));
        (*columnSizes)[i] = i + 1;
    }
    ans[0][0] = 1;
    for (int i = 1; i < numRows; ++i) {
        ans[i][0] = ans[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
    }
    return ans;
}

int main() {
    int numRows = 1, *columnSizes;
    int** ans = generate(numRows, &columnSizes);
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < columnSizes[i]; ++j) {
            printf("%d  ", ans[i][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
