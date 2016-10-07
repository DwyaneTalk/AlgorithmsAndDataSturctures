/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode268  : Missing Number
*                : https://leetcode.com/problems/missing-number/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


int missingNumber(int* nums, int numsSize) {
    int i, ans;
    if (rand() % 2) {
        ans = 0;
        for (i = 0; i < numsSize; ++i) {
            ans += nums[i];
        }
        ans = numsSize * (numsSize + 1) / 2 - ans;
    } else {
        ans = numsSize;
        for (i = 0; i < numsSize; ++i) {
            ans ^= nums[i];
            ans ^= i;
        }
    }
    return ans;
}

int main() {
    int nums[] = { 0, 1, 2 };
    int numsSize = sizeof(nums) / sizeof(int);
    int ans = missingNumber(nums, numsSize);
    printf("%d\n", ans);
    system("pause");
    return 0;
}
