/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Combination Sum 
*             : https://leetcode.com/problems/combination-sum/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define INIT_SIZE 500
#define RENEW_SIZE 20

typedef struct Vector{
    int width;
    int returnSize;
    int MaxSize;
    int **returnAns;
    int *columnSize;
} Vector;

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void initVector(Vector *vec, int width) {
    int i;
    vec->width = width;
    if (vec->columnSize = (int *)malloc(sizeof(int)* INIT_SIZE)) {
        if (vec->returnAns = (int **)malloc(sizeof(int*)* INIT_SIZE)) {
            for (i = 0; i < INIT_SIZE; ++i) {
                if (!(vec->returnAns[i] = (int *)malloc(sizeof(int)* width)))
                    exit(-1);
            }
            vec->returnSize = 0;
            vec->MaxSize = INIT_SIZE;
        }
    }
}

void newOneToVector(Vector *vec, int num, int candidate) {
    if (vec->returnSize == vec->MaxSize) {
        vec->columnSize = (int *)realloc(vec->columnSize, sizeof(int)* (vec->MaxSize + RENEW_SIZE));
        vec->returnAns = (int **)realloc(vec->returnAns, sizeof(int*)* (vec->MaxSize + RENEW_SIZE));
        vec->MaxSize += RENEW_SIZE;
        for (int i = vec->returnSize; i < vec->MaxSize; ++i) {
            vec->returnAns[i] = (int *)malloc(sizeof(int)* vec->width);
        }
    }
    for (int i = 0; i < num; ++i)
        vec->returnAns[vec->returnSize][i] = candidate;
    vec->columnSize[vec->returnSize] = num;
    vec->returnSize++;
}

void addOneToVector(Vector* vec, int index, int num, int candidate) {
    int i = vec->columnSize[index];
    vec->columnSize[index] += num;
    for (; i < vec->columnSize[index]; ++i) {
        vec->returnAns[index][i] = candidate;
    }
}

void subCombinationSum(int* candidate, int candidatesSize, int target, Vector* vec) {
    if (candidatesSize <= 0 || candidate[0] > target)    return;
    int pos = candidatesSize - 1;
    subCombinationSum(candidate, pos, target, vec);
    int i, j, val, last_size;
    for (i = 1, val = candidate[pos]; val < target; ++i, val += candidate[pos]) {
        last_size = vec->returnSize;
        subCombinationSum(candidate, pos, target - val, vec);
        for (j = last_size; j < vec->returnSize; ++j) {
            addOneToVector(vec, j, i, candidate[pos]);
        }
    }
    if (val == target) {
        newOneToVector(vec, i, candidate[pos]);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    Vector vec;
    qsort((void *)candidates, candidatesSize, sizeof(int), compare);
    initVector(&vec, target / candidates[0]);
    subCombinationSum(candidates, candidatesSize, target, &vec);
    *returnSize = vec.returnSize;
    *columnSizes = vec.columnSize;
    return vec.returnAns;
}

int main() {
    int candidates[] = { 2, 3, 6, 7 };
    int target = 7;
    int returnSize;
    int *columnSize;
    int **ans = combinationSum(candidates, sizeof(candidates) / sizeof(int), target, &columnSize, &returnSize);
    int i, j;
    for (i = 0; i < returnSize; ++i) {
        for (j = 0; j < columnSize[i]; ++j) {
            printf("%d  ", ans[i][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
