/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Combinations
*             : https://leetcode.com/problems/combinations/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    int size;
    int returnSize;
    int *columnSizes;
    int **ans;
} Result;

int getreturnSize(int n, int k) {
    int a = 1, b = 1;
    while (k) {
        a *= (n - k + 1);
        b *= k--;
    }
    return a / b;
}

void initResult(Result *result, int returnsize, int k) {
    if ((result->columnSizes = (int *)malloc(sizeof(int)* returnsize)) && (result->ans = (int **)malloc(sizeof(int *)* returnsize))) {
        for (int i = 0; i < returnsize; ++i) {
            result->ans[i] = (int *)malloc(sizeof(int)* k);
            result->columnSizes[i] = k;
        }
        result->size = 0;
        result->returnSize = returnsize;
    }
}

void backTracking(int l, int n, int k, int curr, int *oneAns, int *used, Result *result) {
    if (curr >= k) {
        memcpy(result->ans[result->size], oneAns, sizeof(int)* k);
        result->size += 1;
        return;
    }
    for (int i = l; i < n; ++i) {
        if (!used[i]) {
            used[i] = 1;
            oneAns[curr] = i + 1;
            backTracking(i + 1, n, k, curr + 1, oneAns, used, result);
            used[i] = 0;
        }
    }
}

int** combine(int n, int k, int** columnSizes, int* returnSize) {
    if (!n || !k || n < k) {
        *returnSize = 0;
        return NULL;
    }
    Result result;
    initResult(&result, getreturnSize(n, k), k);
    int *used = (int *)calloc(n, sizeof(int));
    int *oneAns = (int *)malloc(sizeof(int)* k);

    backTracking(0, n, k, 0, oneAns, used, &result);

    *returnSize = result.returnSize;
    *columnSizes = result.columnSizes;
    return result.ans;
}

int main() {
    int n = 0, k = 2, i, j;
    int **ans, *columnSizes, returnSize;
    ans = combine(n, k, &columnSizes, &returnSize);
    for (i = 0; i < returnSize; ++i) {
        for (j = 0; j < columnSizes[i]; ++j) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
