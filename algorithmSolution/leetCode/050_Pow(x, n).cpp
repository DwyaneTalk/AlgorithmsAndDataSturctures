/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Pow(x, n)   
 *             : https://leetcode.com/problems/powx-n/
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

double myPositivePow(double x, int n) {
    if (n == 1) return x;
    double half_ans = myPositivePow(x, n / 2);
    if (n & 1) {
        return half_ans * half_ans * x;
    } else {
        return half_ans * half_ans;
    }
}

double myPow(double x, int n) {
    if (n == 0) return 1;
    if (n > 0)
        return myPositivePow(x, n);
    if (n < 0) {
        if (n == INT_MIN) {
            return 1 / (myPositivePow(x, INT_MAX) * x);
        } else {
            return 1 / myPositivePow(x, -n);
        }
    }
}

int main() {
    double x = 8.88023;
    int n = 3;
    double ans = myPow(x, n);
    printf("%lf\n", ans);
    system("pause");
    return 0;
}
