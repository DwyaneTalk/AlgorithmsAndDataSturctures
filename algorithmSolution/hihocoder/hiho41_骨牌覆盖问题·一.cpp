/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : 骨牌覆盖问题·一
 *             : http://hihocoder.com/contest/hiho41/problem/1
*/

#include<stdio.h>
/*
递推关系：f(n) = f(n-1) + f(n-2)
*/

//  递推计算
int solution1(int n){
    int a = 1, b = 2, tmp;
    if (n <= 3) return n;
    while(n-- > 2) {
        tmp = a;
        a = b;
        b = (b + tmp) % 19999997;
    }
    return b;
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
        mat[0] = (mat_t[0] * mat_t[0] + mat_t[1] * mat_t[2]) % 19999997;
        mat[1] = (mat_t[0] * mat_t[1] + mat_t[1] * mat_t[3]) % 19999997;
        mat[2] = (mat_t[2] * mat_t[0] + mat_t[3] * mat_t[2]) % 19999997;
        mat[3] = (mat_t[2] * mat_t[1] + mat_t[3] * mat_t[3]) % 19999997;
        if(n & 1) {
            tmp1 = mat[0];
            mat[0] = (mat[0] + mat[1]) % 19999997;
            mat[1] = tmp1;
            tmp2 = mat[2];
            mat[2] = (mat[2] + mat[3] ) %19999997;
            mat[3] = tmp2;
        }
    }
}

int solution2(int n) {
    int a = 1, b = 2, tmp;
    long long mat[4];
    if (n <= 3) return n;
    matrixPow(mat, n-2);
    return (2 * mat[0] + mat[2]) % 19999997;
}

int main() {
    int n = 9823;
    int ans1 = solution1(n);
    printf("%d\n", ans1);
    int ans2 = solution2(n);
    printf("%d\n", ans2);
    return 0;
}
