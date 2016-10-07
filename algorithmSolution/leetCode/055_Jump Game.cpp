/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Spiral Matrix
 *             : https://leetcode.com/problems/spiral-matrix/
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

bool canJump(int* nums, int numsSize) {
    int fir = nums[0], sec = 1;
    while (fir < numsSize - 1 && sec <= fir) {
        fir = MAX(fir, sec + nums[sec]);
        ++sec;
    }
    return fir >= numsSize - 1;
}

int main() {
    int nums[] = { 3, 2, 1, 0, 4 };
    int ans = canJump(nums, sizeof(nums) / sizeof(int));
    if (ans)
        printf("YES!\n");
    else
        printf("NO!\n");
    system("pause");
    return 0;
}
