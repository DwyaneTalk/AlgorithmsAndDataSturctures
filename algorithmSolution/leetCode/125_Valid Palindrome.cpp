/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode125  : Valid Palindrome
*                : https://leetcode.com/problems/valid-palindrome/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define IS_ALPHA(ch) (((ch) >= '0' && (ch) <= '9') || ((ch) >= 'A' && (ch) <= 'Z') || ((ch) >= 'a' && (ch) <= 'z'))
#define LOW_CASE(ch) (((ch) >= 'A' && (ch) <= 'Z') ? ((ch) + 'a' - 'A') : (ch))

bool isPalindrome(char* s) {
    char *lo = s, *hi = s + strlen(s) - 1;
    while (lo < hi) {
        while (lo < hi && !IS_ALPHA(*lo)) {
            ++lo;
        }
        while (lo < hi && !IS_ALPHA(*hi)) {
            --hi;
        }
        if (lo == hi) {
            return true;
        } else {
            if (LOW_CASE(*lo) == LOW_CASE(*hi)) {
                ++lo;
                --hi;
            } else {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char s[] = "a,.sa sa";
    int ans = isPalindrome(s);
    printf("ans : %d\n", ans);
    system("pause");
    return 0;
}
