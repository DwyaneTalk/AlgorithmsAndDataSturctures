/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Single Number
 *             : https://leetcode.com/submissions/detail/27592328/
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int singleNumber(int* nums, int numsSize) {
    if(!nums || !numsSize) return -1;
    int i, ans = 0;
    for(i = 0; i < numsSize; ++i){
        ans = ans ^ nums[i];
    }
    return ans;
}

int main() {
    int nums[] = { 1, 1, 2};
    int ans = singleNumber(nums, sizeof(nums) / sizeof(int));
    printf("%d\n", ans);
    system("pause");
    return 0;
}
