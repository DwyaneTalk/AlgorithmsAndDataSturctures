/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Search in Rotated Sorted Array II
*             : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

bool binarySreach(int* nums, int lo, int hi, int target) {
    int mid;
    while (lo <= hi) {
        mid = (lo + hi) >> 1;
        if (nums[mid] == target)    return true;
        if (nums[mid] > target)     hi = mid - 1;
        else                        lo = mid + 1;
    }
    return false;
}

bool search(int* nums, int numsSize, int target) {
    int lo = 0, hi = numsSize - 1, mid = (lo + hi) >> 1;
    if (!nums || !numsSize) return false;
    if (numsSize == 1)  return nums[0] == target;
    while (mid >0 && mid < numsSize && lo <= hi) {
        if ((nums[mid] <= nums[0] && nums[mid - 1] > nums[0]) || (nums[mid] < nums[0] && nums[mid - 1] >= nums[0])) break;
        if ((nums[mid] <= nums[0] && nums[mid - 1] <= nums[mid]) && !(nums[mid] >= nums[mid - 1] && nums[mid - 1] >= nums[0])) {
            hi = mid - 1;
            mid = (lo + hi) >> 1;
        } else if ((nums[mid] >= nums[mid - 1] && nums[mid - 1] >= nums[0]) && !(nums[mid] <= nums[0] && nums[mid - 1] <= nums[mid])) {
            lo = mid + 1;
            mid = (lo + hi) >> 1;
        } else {
            return search(nums, mid, target) || search(nums + mid, numsSize - mid, target);
        }
    }
    if (!mid && numsSize > 1 && nums[1] <= nums[0]) mid = 1;
    return binarySreach(nums, 0, mid - 1, target) || binarySreach(nums, mid, numsSize - 1, target);
}

int main() {
    int nums[] = {2, 2, 2, 3, 1};
    int numsSize = sizeof(nums) / sizeof(int);
    int target = 1;
    bool ans = search(nums, numsSize, target);
    if (ans)    printf("Yes!\n");
    else        printf("No!!\n");
    system("pause");
    return 0;
}
