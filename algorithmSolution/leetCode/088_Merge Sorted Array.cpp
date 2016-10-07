/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Merge Sorted Array 
*             : https://leetcode.com/problems/merge-sorted-array/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void merge(int* nums1, int m, int* nums2, int n) {
    int ptr = m + n - 1, ptr_m = m - 1, ptr_n = n - 1;
    while (ptr_m >= 0 && ptr_n >= 0) {
        if (nums1[ptr_m] > nums2[ptr_n])
            nums1[ptr--] = nums1[ptr_m--];
        else
            nums1[ptr--] = nums2[ptr_n--];
    }
    while (ptr_n >= 0) {
        nums1[ptr--] = nums2[ptr_n--];
    }
}

int main() {
    int nums1[] = { 1, 2, 3, 3, 5, 7, 0, 0, 0, 0, 0, 0,0, 0};
    int nums2[] = { 2, 3, 6, 7, 8 };
    int m = 0, n = 0;
    merge(nums1, m, nums2, n);
    for (int i = 0; i < m + n; ++i)
        printf("%d ", nums1[i]);
    printf("\n");
    system("pause");
    return 0;
}
