/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Next Permutation
*             : https://leetcode.com/problems/next-permutation/
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


void nextPermutation(int num[], int n) {
    if (n < 2)  return;
    int lo, hi = n - 1, i = n -1, swp_val;
    while (hi > 0 && num[hi] <= num[hi - 1])     hi--;
    if (hi) {
        while (num[i] <= num[hi - 1])    i--;
        swp_val = num[i];
        num[i] = num[hi - 1];
        num[hi - 1] = swp_val;
    }
    lo = hi;
    hi = n - 1;
    while (lo < hi) {
        swp_val = num[lo];
        num[lo] = num[hi];
        num[hi] = swp_val;
        lo++;
        hi--;
    }
}

int main() {
    int num[] = {1};
    int n = sizeof(num) / sizeof(int);
    int i = 0, j;
    while (i++ < 30) {
        for (j = 0; j < n; j++) {
            printf("%d\t", num[j]);
        }
        printf("\n");
        nextPermutation(num, n);
    }
    system("pause");
    return 0;
}
