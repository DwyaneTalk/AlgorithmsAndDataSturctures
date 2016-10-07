/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode119  : Pascal's Triangle II
*                : https://leetcode.com/problems/pascals-triangle-ii/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int* getRow(int rowIndex, int* returnSize) {
    if (rowIndex < 0) {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = rowIndex + 1;
    int* ans = (int*)malloc(sizeof(int) * (*returnSize));
    ans[0] = 1;
    int tmp1, tmp2;
    for (int i = 1; i <= rowIndex; ++i) {
        ans[0] = ans[i] = 1;
        tmp1 = 1;
        for (int j = 1; j < i; ++j) {
            tmp2 = tmp1 + ans[j];
            tmp1 = ans[j];
            ans[j] = tmp2;
        }
    }
    return ans;
}

int main() {
    int numRows = 0, columnSizes;
    int* ans = getRow(numRows, &columnSizes);
    for (int i = 0; i < columnSizes; ++i) {
        printf("%d  ", ans[i]);
    }
    system("pause");
    return 0;
}
