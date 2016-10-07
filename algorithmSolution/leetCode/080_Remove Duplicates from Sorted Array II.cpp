/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Remove Duplicates from Sorted Array II
*             : https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int removeDuplicates(int* nums, int numsSize) {
    if (!nums || numsSize < 3)  return numsSize;
    int i_new = 2, i_cur = 2, pre_val = nums[1], ppre_val = nums[0];
    for (; i_cur < numsSize; ++i_cur) {
        if (nums[i_cur] != pre_val || nums[i_cur] != ppre_val) {
            ppre_val = pre_val;
            pre_val = nums[i_cur];
            nums[i_new++] = nums[i_cur];
        } else {
            ppre_val = pre_val;
            pre_val = nums[i_cur];
        }
    }
    return i_new;
}


int main() {
    int nums[] = { 1, 2, 2, 2};
    printf("%d\n", removeDuplicates(nums, sizeof(nums) / sizeof(int)));
    system("pause");
    return 0;
}
