/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Plus One 
*             : https://leetcode.com/problems/plus-one/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    if (!digits || digitsSize < 1)  return NULL;
    int *ans = (int *)malloc(sizeof(int)* (digitsSize + 1));
    int carry = 1, i;
    for (i = digitsSize - 1; i >= 0; --i) {
        ans[i + 1] = (digits[i] + carry) % 10;
        carry = digits[i] + carry >= 10;
    }
    if (carry) {
        ans[0] = 1;
        *returnSize = digitsSize + 1;
    } else {
        ans++;
        *returnSize = digitsSize;
    }
    return ans;
}

int main() {
    int digits[] = {9, 9};
    int returnSize;
    int *ans = plusOne(digits, sizeof(digits) / sizeof(int), &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}
