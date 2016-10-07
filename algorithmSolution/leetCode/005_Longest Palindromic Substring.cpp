/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCode : Longest Palindromic Substring
 *            : https://leetcode.com/problems/longest-palindromic-substring/
*/

#include<stdio.h>
// todo : Manacher method可以做到O(n)的时间复杂度
bool isPalindrome(char* s, int l, int r) {
    while(l < r) {
        if(s[l++] != s[r--])
            return false;
    }
    return true;
}

char* longestPalindrome(char* s) {
    int i = 1, max_l = 1, max_p = 0, left = 0;
    if(!s[0] || !s)    return s;
    while(s[i]) {
        if (i > max_l) {
            if(isPalindrome(s, i - max_l - 1, i)) {
                max_p = i - max_l - 1;
                max_l += 2;
            }
        }
        if(isPalindrome(s, i - max_l, i)) {
            max_p = i - max_l;
            max_l++;
        }
        i++;
    }
    s[max_p + max_l] = '\0';
    return s + max_p;
}

int main() {
    char s[] = "uuyyyu";
    printf("%s\n", s);
    char *ans = longestPalindrome(s);
    printf("%s\n", ans);
    return 0;
}
