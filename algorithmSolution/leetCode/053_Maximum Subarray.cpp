/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Maximum Subarray
 *             : https://leetcode.com/problems/maximum-subarray/
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxSubArray(int* nums, int numsSize) {
    int ans = INT_MIN, sum = 0, i;
    for (i = 0; i < numsSize; ++i) {
        sum = MAX(sum + nums[i], nums[i]);
        ans = MAX(ans, sum);
    }
    return ans;
}

int main() {
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int ans = maxSubArray(nums, sizeof(nums) / sizeof(int));
    printf("%d\n", ans);
    system("pause");
    return 0;
}
