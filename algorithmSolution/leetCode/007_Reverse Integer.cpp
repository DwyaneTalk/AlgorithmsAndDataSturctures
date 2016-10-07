/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCode : Reverse Integer
 *            : https://leetcode.com/problems/reverse-integer/
*/

#include<stdio.h>
#include<limits.h>

int reverse(int x) {
    long long ans = 0;
    int tmp_x = x > 0 ? x : (-x);
    if (x == INT_MIN)   return 0;
    while(tmp_x) {
        ans = ans * 10 + tmp_x % 10;
        tmp_x = tmp_x / 10;
    }
    if (ans > INT_MAX)  ans = 0;
    if (x < 0)  ans = - ans;
    return (int)(ans);
}

int main() {
    int in = -2147483648;
    int ans = reverse(in);
    printf("%d\n", ans);
    return 0;
}
