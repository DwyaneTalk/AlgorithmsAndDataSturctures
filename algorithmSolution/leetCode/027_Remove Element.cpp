/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Remove Element
 *             : https://leetcode.com/problems/remove-element/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


int removeElement(int A[], int n, int elem) {
    if(n == 0) return 0;
    int lo = 0, hi = n - 1;
    while(lo <= hi) {
        if(A[lo] == elem)
            A[lo] = A[hi--];
        else
            lo++;
    }
    return lo;
}

int main() {
    int a[] = {2, 3, 3, 2};
    int ans = removeElement(a, sizeof(a) / sizeof(a[0]), 2);
    printf("%d\n", ans);
    for(int i = 0; i < ans; i++) {
        printf("%d\t", a[i]);
    }
    return 0;
}
