/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode90   : Subsets II
*                : https://leetcode.com/problems/subsets-ii/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <algorithm>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

typedef struct{
    int **ans;
    int *columnSizes;
    int max_size;
    int size;
} Result;

void initResult(Result* res) {
    res->ans = (int**)malloc(sizeof(int*)* 1000);
    res->columnSizes = (int*)malloc(sizeof(int)* 1000);
    res->max_size = 1000;
    res->size = 1;
    res->columnSizes[0] = 0;
    res->ans[0] = (int*)malloc(sizeof(int)* 0);
}

void reallocResult(Result* res) {
    res->ans = (int**)realloc(res->ans, sizeof(int*)* (res->max_size + 100));
    res->columnSizes = (int*)realloc(res->columnSizes, sizeof(int)* (res->max_size + 100));
    res->max_size += 100;
}

void resultAddOne(Result* res, int idx, int elem) {
    if (res->size >= res->max_size)
        reallocResult(res);
    int len = res->columnSizes[idx] + 1;
    res->ans[res->size] = (int *)malloc(sizeof(int) *len);
    memcpy(res->ans[res->size], res->ans[idx], sizeof(int)* res->columnSizes[idx]);
    res->ans[res->size][len - 1] = elem;
    res->columnSizes[res->size++] = len;
}

void freeResult(Result* res) {
    for (int i = 0; i < res->size; ++i) {
        free(res->ans[i]);
    }
    free(res->ans);
    free(res->columnSizes);
}

int** subsetsWithDup(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    Result result, *res = &result;
    int start = 0, end = 1;
    qsort(nums, numsSize, sizeof(int), compare);
    initResult(res);
    for (int i = 0; i < numsSize; ++i) {
        for (int j = start; j < end; ++j) {
            resultAddOne(res, j, nums[i]);
        }
        if (i + 1 < numsSize && nums[i + 1] == nums[i]) {
            start = end;
            end = res->size;
        } else {
            start = 0;
            end = res->size;
        }
    }
    *columnSizes = res->columnSizes;
    *returnSize = res->size;
    //freeResult(res);
    return res->ans;
}

int main() {
    int *columnSize, returnSize;
    int nums[] = { 4, 1, 0};
    int numsSize = sizeof(nums) / sizeof(int);
    int **ans = subsetsWithDup(nums, numsSize, &columnSize, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        for (int j = 0; j < columnSize[i]; ++j) {
            printf("%d  ", ans[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    system("pause");
    return 0;
}
