/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : House Robber 
*             : https://leetcode.com/problems/house-robber/
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

int rob(int* nums, int numsSize) {
    if (!numsSize)  return 0;
    int *ans = (int *)malloc(sizeof(int)* numsSize);
    int i;
    ans[0] = nums[0];
    if (numsSize > 1) {
        ans[1] = MAX(nums[0], nums[1]);
        for (i = 2; i < numsSize; ++i) {
            ans[i] = MAX(ans[i - 1], ans[i - 2] + nums[i]);
        }
    }
    return ans[numsSize - 1];
}

int main() {
    int nums[] = { 4, 2, 3, 9};
    int ans = rob(nums, sizeof(nums) / sizeof(int));
    printf("%d\n", ans);
    system("pause");
    return 0;
}
