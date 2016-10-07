/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Permutations 
 *             : https://leetcode.com/problems/permutations/
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
    memcpy(intArray->elem[intArray->size], elem, intArray->line_size * sizeof(int));
    (intArray->size)++;
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
    int i;
    for (i = 0; i < numsSize; ++i) {
        if (!used[i]) {
            used[i] = 1;
            route[cur] = nums[i];
            DFS(nums, numsSize, used, cur + 1, route, intArray);
            used[i] = 0;
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize) {
    if (!numsSize || !nums) { 
        *returnSize = 0;
        return NULL; 
    }
    *returnSize = getFact(numsSize);
    IntArray intArray;
    initIntArray(&intArray, *returnSize, numsSize);
    int *used = (int *)calloc(numsSize, sizeof(int));
    int *route = (int *)malloc(sizeof(int)* numsSize);
    DFS(nums, numsSize, used, 0, route, &intArray);
    return intArray.elem;
}

int main() {
    int nums[] = { 1, 1};
    int returnSize;
    int **ans = permute(nums, sizeof(nums) / sizeof(int), &returnSize);
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
