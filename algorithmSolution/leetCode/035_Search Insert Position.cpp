/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Search Insert Position
*             : https://leetcode.com/problems/search-insert-position/
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int searchInsert(int* nums, int numsSize, int target) {
    int lo = 0, hi = numsSize - 1, mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (nums[mid] == target) {
            return mid;
         } else if(nums[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}

int main() {
    int nums[] = {1, 5, 10, 14, 17};
    int target = 10;
    int ans = searchInsert(nums, sizeof(nums) / sizeof(int), target);
    printf("%d\t%d\n", ans, nums[ans]);
    system("pause");
    return 0;
}
