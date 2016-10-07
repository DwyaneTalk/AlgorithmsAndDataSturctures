/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : 骨牌覆盖问题·二
 *             : https://leetcode.com/problems/longest-common-prefix/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MOD 12357

void matrixPow(int mat[], int n) {
    int mat_t[4], tmp1, tmp2;
    if(n == 1) {
        mat[0] = 4;
        mat[1] = -1;
        mat[2] = 1;
        mat[3] = 0;
    } else {
        matrixPow(mat_t, n >> 1);
        mat[0] = (mat_t[0] * mat_t[0] + mat_t[1] * mat_t[2] + MOD) % MOD;
        mat[1] = (mat_t[0] * mat_t[1] + mat_t[1] * mat_t[3] + MOD) % MOD;
        mat[2] = (mat_t[2] * mat_t[0] + mat_t[3] * mat_t[2] + MOD) % MOD;
        mat[3] = (mat_t[2] * mat_t[1] + mat_t[3] * mat_t[3] + MOD) % MOD;
        if(n & 1) {
            tmp1 = mat[0];
            mat[0] = (4 * mat[0] + mat[1] + MOD) % MOD;
            mat[1] = -tmp1;
            tmp2 = mat[2];
            mat[2] = (4 * mat[2] + mat[3] + MOD) % MOD;
            mat[3] = -tmp2;
        }
    }
}

// 迭代1:当n为偶数时
// f[n] = 3 * f[n - 2] + 2 * f[n - 4] + ... + 2 * f[2] + 2;
// 由上可得 f[n] = 4 * f[n - 2] - f[n - 4]
// 初始 f[2] = 3; f[4] = 11;
int solution1(int n) {
    if(n & 1)   return 0;
    int t = n / 2;
    int a, b, ans;
    if(t == 1)
        return 3;
    else if(t == 2)
        return 11;
    else {
        a = 11;
        b = 3;
        t -= 2;
        while(t--) {
            ans = (4 * a - b + MOD) % MOD;
            b   = a;
            a   = ans;
        }
    }
    return ans;
}

// 根据: f[n] = 4 * f[n - 2] - f[n - 4]
// {f[n], f[n-1]} = {f[n-1], f[n-2]}*{4, 1; -1, 0}
// 二分法进行矩阵幂的计算
int solution2(int n) {
    if(n & 1)   return 0;
    int t = n / 2;
    int ans;
    int mat[4];
    if(t == 1)
        return 3;
    else if(t == 2)
        return 11;
    else {
        matrixPow(mat, t - 2);
        ans = (mat[0] * 11 + mat[1] * 3) % MOD;
    }
    while(ans < 0)
        ans = (ans + MOD) % MOD;
    return ans;
}

int main() {
    int n = 6;
//    scanf("%d", &n);
    for(n = 1; n < 100; n++) {
        int ans = solution1(n);
        printf("%d\t", ans);
        ans = solution2(n);
        printf("%d\n", ans);
    }
    return 0;
}
