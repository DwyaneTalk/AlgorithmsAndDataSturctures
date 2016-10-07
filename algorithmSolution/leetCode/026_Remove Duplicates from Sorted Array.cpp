/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Remove Duplicates from Sorted Array
 *             : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int removeDuplicates(int A[], int n) {
    if(n == 0) return 0;
    int i_cur = 1, i_new = 1;
    int last_val = A[0];
    for(; i_cur < n; ++i_cur) {
        if(A[i_cur] != last_val) {
            last_val = A[i_cur];
            swap(&A[i_new++], &A[i_cur]);
        }
    }
    return i_new;
}

int main() {
    int a[] = {};
    int ans = removeDuplicates(a, sizeof(a) / sizeof(a[0]));
    printf("%d\n", ans);
    for(int i = 0; i < ans; i++) {
        printf("%d\t", a[i]);
    }
    return 0;
}
