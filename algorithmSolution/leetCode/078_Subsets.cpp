/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Subsets 
*             : https://leetcode.com/problems/subsets/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    int size;
    int returnSize;
    int **ans;
    int *columnSizes;
} Result;

void initResult(Result *result, int returnSize) {
    if ((result->ans = (int **)malloc(sizeof(int *)* returnSize)) && (result->columnSizes = (int *)malloc(sizeof(int)* returnSize))) {
        result->columnSizes[0] = 0; //for subset : []
        result->ans[0] = NULL;
        result->size = 1;
        result->returnSize = returnSize;
    }
}

void addResult(Result *result, int num) {
    if (result->size * 2 <= result->returnSize) {
        int i, size = result->size;
        for (i = 0; i < size; ++i) {
            result->ans[result->size] = (int *)malloc(sizeof(int)* (result->columnSizes[i] + 1));
            memcpy(result->ans[result->size], result->ans[i], sizeof(int)* result->columnSizes[i]);
            result->ans[result->size][result->columnSizes[i]] = num;
            result->columnSizes[result->size] = result->columnSizes[i] + 1;
            result->size += 1;
        }
    }
}

int compare(const void *a, const void *b) {
    return *((int *)a) - *((int *)b);
}

int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    Result result;
    initResult(&result, 1 << numsSize);
    qsort(nums, numsSize, sizeof(int), compare);

    int i = 0;
    while (i < numsSize) {
        addResult(&result, nums[i]);
        ++i;
    }
    *columnSizes = result.columnSizes;
    *returnSize = result.returnSize;
    return result.ans;
}

int main() {
    int nums[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int numsSize = sizeof(nums) / sizeof(int), *columnSizes, returnSize;
    int **ans = subsets(nums, numsSize, &columnSizes, &returnSize);
    int i, j;
    for (i = 0; i < returnSize; ++i) {
        for (j = 0; j < columnSizes[i]; ++j) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
