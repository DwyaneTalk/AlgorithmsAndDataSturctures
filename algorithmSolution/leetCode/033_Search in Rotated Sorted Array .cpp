/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Search in Rotated Sorted Array
*             : https://leetcode.com/problems/search-in-rotated-sorted-array/
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int binarySearch(int *nums, int lo, int hi, int target) {
    int mid;
    if (nums[lo] > target || nums[hi] < target) return -1;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (nums[mid] < target)
            lo = mid + 1;
        else if (nums[mid] > target)
            hi = mid - 1;
        else
            return mid;
    }
    return -1;
}

int search(int* nums, int numsSize, int target) {
    int mid, lo = 0, hi = numsSize - 1;
    while (lo <= hi) {
        if (nums[lo] < nums[hi])
            return binarySearch(nums, lo, hi, target);
        mid = (lo + hi) / 2;
        if (nums[lo] > target) {
            if (nums[mid] > nums[hi])
                lo = mid + 1;
            else {
                if (nums[mid] == target)
                    return mid;
                else if (nums[mid] > target)
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
        } else {
            if (nums[mid] < nums[lo])
                hi = mid - 1;
            else {
                if (nums[mid] == target)
                    return mid;
                else if (nums[mid] > target)
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
        }
    }
    return -1;
}

int main() {
    int nums[] = { 4, 2, 3 };
    int ans = search(nums, sizeof(nums) / sizeof(int), 5) ;
    printf("%d\n", ans);
    system("pause");
    return 0;
}
