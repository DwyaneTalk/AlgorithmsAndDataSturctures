/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Sort Colors 
*             : https://leetcode.com/problems/sort-colors/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void sortColors(int* nums, int numsSize) {
    int count[3] = { 0, 0, 0 };
    int i, j, k = 0;
    for (i = 0; i < numsSize; ++i)
        ++(count[nums[i]]);
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < count[i]; ++j) {
            nums[k++] = i;
        }
    }
}

int main() {
    int nums[] = { 1, 1, 0, 2, 1, 0, 1 };
    int numsSize = sizeof(nums) / sizeof(int);
    sortColors(nums, numsSize);
    for (int i = 0; i < numsSize; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}
