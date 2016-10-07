/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode89   : Gray Code
*                : https://leetcode.com/problems/gray-code/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int *grayCodeConstruct(int n, int* returnSize) {
    *returnSize = 1 << n;
    int size = 1;
    int *ans = (int*) malloc(sizeof(int)* (*returnSize));
    ans[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = size - 1; j >= 0; --j) {
            ans[size++] = ans[j] ^ (1 << i);
        }
    }
    return ans;
}

int binaryToGray(int binary) {
    return binary ^ (binary >> 1);
}

int grayToBinary(int gray) {
    int binary = gray;
    for (gray >>= 1; gray; gray >>= 1) {
        binary = binary ^ gray;
    }
    return binary;
}

int *grayCodeConvert(int n, int* returnSize) {
    *returnSize = 1 << n;
    int* ans = (int *)malloc(sizeof(int)* (*returnSize));
    for (int i = 0; i < (*returnSize); ++i) {
        ans[i] = binaryToGray(i);
        //printf("%d  :  %d\n", i, grayToBinary(ans[i]));
    }
    //printf("\n");
    return ans;
}

int* grayCode(int n, int* returnSize) {
    if (rand() % 2)
        return grayCodeConstruct(n, returnSize);
    else
        return grayCodeConvert(n, returnSize);
}
int main() {
    int n = 3, returnSize, *ans;
    ans = grayCode(n, &returnSize);
    for (int i = 0; i < returnSize; ++i)
        printf("%d \n", ans[i]);
    printf("\n");
    system("pause");
    return 0;
}
