/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Permutations II
 *             : https://leetcode.com/problems/permutations-ii/
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    int size;
    int max_size;
    int line_size;
    int **elem;
} IntArray;

void initIntArray(IntArray *intArray, int size, int line_size) {
    if (intArray->elem = (int **)malloc(sizeof(int *)* size)) {
        for (intArray->max_size = 0; intArray->max_size < size; ++(intArray->max_size)) {
            if (!(intArray->elem[intArray->max_size] = (int *)malloc(sizeof(int)* line_size))) {
                exit(-1);
            }
        }
        intArray->size = 0;
        intArray->line_size = line_size;
    } else {
        exit(-1);
    }
}

void addOneToArray(IntArray *intArray, int *elem) {
    if (intArray->size >= intArray->max_size)   exit(-1);
    int i;
    for (i = 0; i < intArray->size; ++i) {
        if (!memcmp(intArray->elem[i], elem, intArray->line_size * sizeof(int))) {
            return;
        }
    }
    memcpy(intArray->elem[intArray->size], elem, intArray->line_size * sizeof(int));
    (intArray->size)++;
}

void freeIntArray(IntArray *intArray) {
    int i = intArray->size;
    for (; i < intArray->max_size; ++i)
        free(intArray->elem[i]);
}

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int getFact(int n) {
    int ans = 1;
    while (n > 1) {
        ans *= n;
        --n;
    }
    return ans;
}

void DFS(int *nums, int numsSize, int *used, int cur, int *route, IntArray *intArray) {
    if (cur == numsSize) {
        addOneToArray(intArray, route);
    }
    int i, last = nums[0] - 1;
    for (i = 0; i < numsSize; ++i) {
        if (!used[i] && nums[i] != last) {
            used[i] = 1;
            route[cur] = nums[i];
            last = nums[i];
            DFS(nums, numsSize, used, cur + 1, route, intArray);
            used[i] = 0;
        }
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize) {
    if (!numsSize || !nums) { 
        *returnSize = 0;
        return NULL; 
    }
    *returnSize = getFact(numsSize);
    IntArray intArray;
    initIntArray(&intArray, *returnSize, numsSize);
    int *used = (int *)calloc(numsSize, sizeof(int));
    int *route = (int *)malloc(sizeof(int)* numsSize);
    qsort(nums, numsSize, sizeof(int), compare);
    //for (int i = 0; i < numsSize; ++i)
    //    printf("%d\t", nums[i]);
    //printf("\n");
    DFS(nums, numsSize, used, 0, route, &intArray);
    *returnSize = intArray.size;
    freeIntArray(&intArray);
    return intArray.elem;
}

int main() {
    int nums[] = { -1, 2, -1, 2, 1, -1, 2, 1 };
    int returnSize;
    int **ans = permuteUnique(nums, sizeof(nums) / sizeof(int), &returnSize);
    int i, j;
    for (i = 0; i < returnSize; ++i) {
        for (j = 0; j < sizeof(nums) / sizeof(int); ++j) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
