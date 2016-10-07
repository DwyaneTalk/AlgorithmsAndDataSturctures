/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Sqrt(x)
*             : https://leetcode.com/problems/sqrtx/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int mySqrt(int x) {
    if (x < 0) {
        return -1;
    }
    long long lo = 0, hi = x, mid, s1, s2;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        s1 = mid * mid;
        s2 = (mid + 1) * (mid + 1);
        if (x >= s1 && x < s1)  return mid;
        if (x < s1) hi = mid - 1;
        else        lo = mid + 1;
    }
    return lo;
}

int main() {
    int x = 2;
    int ans = mySqrt(x);
    printf("%d\n", ans);
    system("pause");
    return 0;
}
