/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Search for a Range
*             : https://leetcode.com/problems/search-for-a-range/
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *ans = (int *)malloc(sizeof(int) * 2);
    int lo = 0, hi = numsSize - 1, mid;
    int n_lo, n_hi, n_mid;
    ans[0] = -1;
    ans[1] = -1;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (nums[mid] == target) {
            n_lo = lo;
            n_hi = mid;
            while (n_lo <= n_hi) {
                n_mid = (n_lo + n_hi) / 2;
                if (nums[n_mid] == target && (n_mid == lo || nums[n_mid - 1] < target)) {
                    ans[0] = n_mid;
                    break;
                } else if (nums[n_mid] < target){
                    n_lo = n_mid + 1;
                } else {
                    n_hi = n_mid - 1;
                }
            }
            n_lo = mid;
            n_hi = hi;
            while (n_lo <= n_hi) {
                n_mid = (n_lo + n_hi) / 2;
                if (nums[n_mid] == target && (n_mid == hi || nums[n_mid + 1] > target)) {
                    ans[1] = n_mid;
                    break;
                } else if (nums[n_mid] > target) {
                    n_hi = n_mid - 1;
                } else {
                    n_lo = n_mid + 1;
                }
            }
            break;
        } else if (nums[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    *returnSize = 2;
    return ans;
}

int main() {
    int nums[] = { 1 };
    int target = 0, returnSize;
    int *ans = searchRange(nums, sizeof(nums) / sizeof(int), target, &returnSize);
    printf("%d\t%d\n", ans[0], ans[1]);
    system("pause");
    return 0;
}
