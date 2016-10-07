/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Minimum Window Substring 
*             : https://leetcode.com/problems/minimum-window-substring/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

bool checkValid(int *count, int range) {
    int i;
    for (i = 0; i < range; ++i) {
        if (count[i] > 0)   return false;
    }
    return true;
}

char* minWindow(char* s, char* t) {
    if (!s || !t)   return NULL;
    int min = CHAR_MAX, max = CHAR_MIN;
    int count[128] = { 0 }, len = 0;
    while (t[len]) {
        if (t[len] > max) max = t[len];
        if (t[len] < min) min = t[len];
        ++count[t[len++]];
    }
    int range = max - min + 1;
    int minWindow = INT_MAX, pos = -1, lo = 0, hi = 0;
    while (s[hi]) {
        --count[s[hi]];
        while (hi - lo + 1 >= len && checkValid(&count[min], range)) {
            if (hi - lo + 1 < minWindow) {
                minWindow = hi - lo + 1;
                pos = lo;
            }
            ++count[s[lo++]];
        }
        ++hi;
    }
    if (pos == -1) {
        return "";
    } else {
        *(s + pos + minWindow) = '\0';
        return s + pos;
    }
}

int main() {
    char s[] = "ADOBECODEBANC";
    char t[] = "ABC";
    char *ans = minWindow(s, t);
    printf("%s\n", ans);
    system("pause");
    return 0;
}
