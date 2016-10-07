/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Swap Nodes in Pairs
*             : https://leetcode.com/problems/swap-nodes-in-pairs/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define ABS(x) ((x) > 0 ? (x) : (-(x)))

void subDivide(int dividend, int divisor, int *res) {
    if (dividend < divisor) {
        res[0] = 0;
        res[1] = dividend;
        return;
    }
    int half = dividend >> 1;
    int res1[2];
    subDivide(half, divisor, res1);
    if (dividend & 1) {
        if (((res1[1] << 1) + 1) >= divisor) {
            res[1] = (res1[1] << 1) + 1 - divisor;
            res[0] = (res1[0] << 1) + 1;
        } else {
            res[1] = (res1[1] << 1) + 1;
            res[0] = res1[0] << 1;
        }
    } else {
        if ((res1[1] << 1) >= divisor) {
            res[1] = (res1[1] << 1) - divisor;
            res[0] = (res1[0] << 1) + 1;
        } else {
            res[1] = res1[1] << 1;
            res[0] = res1[0] << 1;
        }
    }
}

int divide(int dividend, int divisor) {
    if (!divisor)
        return INT_MAX;
    if (divisor == INT_MIN)
        return divisor == INT_MIN ? 1 : 0;
    int a = dividend == INT_MIN ? INT_MAX : ABS(dividend), b = ABS(divisor);
    int ans = a, half;
    int res1[2], res2[2];
    if (b != 1) {
        half = a >> 1;
        subDivide(half, b, res1);
        subDivide(a - half, b, res2);
        if (dividend == INT_MIN)
            res1[1] = res1[1] + 1;
        if (res1[1] >= b - res2[1])
            ans = res1[0] + res2[0] + 1;
        else
            ans = res1[0] + res2[0];
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
            ans = -ans;
    } else {
        if (dividend == INT_MIN) {
            if (divisor == -1)
                ans = INT_MAX;
            else
                ans = INT_MIN;
        } else {
            if (divisor == -1)
                ans = -dividend;
            else
                ans = dividend;
        }
    }
    return ans;
}
int main() {
    int a = INT_MIN, b = -1109186033;
    int c = (-5) / (-3);
    int ans = divide(a, b);
    printf("%d\n", ans);
    system("pause");
    return 0;
}
