/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Number of 1 Bits
 *             : https://leetcode.com/problems/number-of-1-bits/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef unsigned int uint32_t

int hammingWeight(uint32_t n) {
    int ans = 0;
    while(n) {
        if(n & 1)   ++ans;
        n = n >> 1;
    }
    return ans;
}

int main() {
    unsigned int n = 11;
    int ans = hammingWeight(n);
    printf("%d\n", ans);
    return 0;
}
