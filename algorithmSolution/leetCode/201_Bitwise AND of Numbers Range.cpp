/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Bitwise AND of Numbers Range
*             : https://leetcode.com/problems/bitwise-and-of-numbers-range/
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int solution(int m, int n) {
    int i = 0;
    while (m != n) {
        m >>= 1;
        n >>= 1;
        i++;
    }
    return m << i;
}

int rangeBitwiseAnd(int m, int n) {
    return solution(m, n);
    int ans = 0;
    int bits[31] = { 0 };
    int k, val_1, val_2, mod_m, mod_n;
    for (k = 0; k < 31; k++) {
        val_1 = 1 << k;         // 2^k
        val_2 = val_1 << 1;     // 2^(k+1)
        if (m < val_1)
            break;
        mod_m = m % val_2;
        mod_n = n % val_2;
        if (n - m + 1 <= val_1 && mod_m >= val_1 && mod_n >= mod_m) {
            bits[k] = 1;
        }
    }
    for (k = 0; k < 31; k++) {
        if (bits[k]) {
            ans = ans | (1 << k);
        }
    }
    return ans;
}

int main() {
    int m = 0, n = 7;
    int ans = rangeBitwiseAnd(m, n);
    printf("%d\n", ans);
    system("pause");
    return 0;
}
