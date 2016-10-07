/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCode : Palindrome Number
 *            : https://leetcode.com/problems/palindrome-number/
*/

#include<stdio.h>


bool isPalindrome(int x) {
    if (x < 0) return false;
    long x1 = x, x2 = 0;
    while(x) {
        x2 =x2 * 10 + x % 10;
        x = x / 10;
    }
    return (x1 == x2);
}

int main() {
    int ans = isPalindrome(0);
    printf("%d\n", ans);
    return 0;
}
