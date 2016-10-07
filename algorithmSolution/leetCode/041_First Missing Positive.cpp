/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : First Missing Positive 
*             : https://leetcode.com/problems/first-missing-positive/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int firstMissingPositive(int* nums, int numsSize) {
    int i;
    for (i = 0; i < numsSize; ++i) {
        while (nums[i] > 0 && nums[i] <= numsSize  && nums[i] != (i + 1) && nums[i] != nums[nums[i] - 1]) {
            swap(nums + i, nums + nums[i] - 1);
        }
    }
    for (i = 0; i < numsSize; ++i) {
        if (nums[i] != i + 1)   break;
    }
    return (i + 1);
}

int main() {
    int nums[] = { 1, 1};
    int ans = firstMissingPositive(nums, sizeof(nums) / sizeof(int));
    printf("%d\n", ans);
    system("pause");
    return 0;
}
