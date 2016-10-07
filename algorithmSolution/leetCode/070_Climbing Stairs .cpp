/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Climbing Stairs 
*             : https://leetcode.com/problems/climbing-stairs/
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/*
递推关系：f(n) = f(n-1) + f(n-2)
*/

//  递推计算
int solution1(int n) {
    if (n == 1)  return 1;
    if (n == 2)  return 2;
    int fn_1 = 2, fn_2 = 1, i = 3, ans;
    while (i <= n) {
        ans = fn_1 + fn_2;
        fn_2 = fn_1;
        fn_1 = ans;
        ++i;
    }
    return ans;
}

//  转换成矩阵相乘，用二分进行计算
//  [fn, fn-1] = [fn-1, fn-2][1, 1; 1 0]
void matrixPow(long long mat[], int n) {
    long long mat_t[4], tmp1, tmp2;
    if (n == 1) {
        mat[0] = 1;
        mat[1] = 1;
        mat[2] = 1;
        mat[3] = 0;
    } else {
        matrixPow(mat_t, n >> 1);
        mat[0] = (mat_t[0] * mat_t[0] + mat_t[1] * mat_t[2]);
        mat[1] = (mat_t[0] * mat_t[1] + mat_t[1] * mat_t[3]);
        mat[2] = (mat_t[2] * mat_t[0] + mat_t[3] * mat_t[2]);
        mat[3] = (mat_t[2] * mat_t[1] + mat_t[3] * mat_t[3]);
        if (n & 1) {
            tmp1 = mat[0];
            mat[0] = (mat[0] + mat[1]);
            mat[1] = tmp1;
            tmp2 = mat[2];
            mat[2] = (mat[2] + mat[3]);
            mat[3] = tmp2;
        }
    }
}

int solution2(int n) {
    int a = 1, b = 2, tmp;
    long long mat[4];
    if (n <= 3) return n;
    matrixPow(mat, n - 2);
    return (2 * mat[0] + mat[2]);
}

int climbStairs(int n) {
    //return solution1(n);
    return solution2(n);
}

int main() {
    int n = 5;
    int ans = climbStairs(n);
    printf("ans : %d\n", ans);
    system("pause");
    return 0;
}
