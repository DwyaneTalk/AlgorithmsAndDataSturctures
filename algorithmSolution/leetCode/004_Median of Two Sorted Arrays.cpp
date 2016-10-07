/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCode : Median of Two Sorted Arrays
 *            : https://leetcode.com/problems/median-of-two-sorted-arrays/
*/

#include<stdio.h>

// 这是O(m+n)的复杂度
// 这里有O(log(min(m,n)))的复杂度 ：
// https://leetcode.com/discuss/15790/share-my-o-log-min-m-n-solution-with-explanation
double findMedianSortedArrays(int A[], int m, int B[], int n) {
    int C[m + n];
    int im=0, in=0, ic=0;
    while(im < m && in < n) {
        if (A[im] < B[in]) {
            C[ic++] = A[im++];
        }else{
            C[ic++] = B[in++];
        }
    }
    if(im < m) {
        while(im < m)   C[ic++] = A[im++];
    } else {
        while(in < n)   C[ic++] = B[in++];
    }

    if ((m + n) % 2) {
        return (double)C[(m + n) / 2];
    } else {
        return ((double)C[(m + n) / 2] + (double)C[(m + n) / 2 -1]) / 2 ;
    }
}

int main() {
    int A[] = {};
    int B[] = {1};
    double ans = findMedianSortedArrays(A, sizeof(A)/sizeof(int), B, sizeof(B)/sizeof(int));
    printf("ans=%lf\n", ans);
    return 0;
}

