/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode87  : Scramble String
*                : https://leetcode.com/problems/scramble-string/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

bool isSubScramble(char* s1, char* s2, int len) {
    if (!memcmp(s1, s2, len))   return true;
    int count[26] = { 0 };
    for (int i = 0; i < len; ++i) {
        ++count[*(s1 + i) - 'a'];
        --count[*(s2 + i) - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
        if (count[i])   return false;
    }
    for (int k = 1; k < len; ++k) {
        if (isSubScramble(s1, s2, k) && isSubScramble(s1 + k, s2 + k, len - k)) return true;
        if (isSubScramble(s1, s2 + len - k, k) && isSubScramble(s1 + k, s2, len - k)) return true;
    }
    return false;
}

bool isScramble(char* s1, char* s2) {
    if (!s1 || !s2) return false;
    int len1 = strlen(s1), len2 = strlen(s2);
    if (len1 != len2)   return false;
    return isSubScramble(s1, s2, len1);
}

int main() {
    char s1[] = "greae";
    char s2[] = "rgtae";
    bool ans = isScramble(s1, s2);
    if (ans)    printf("Yes\n");
    else        printf("No\n");
    //printf("%d\n", ans);
    system("pause");
    return 0;
}
