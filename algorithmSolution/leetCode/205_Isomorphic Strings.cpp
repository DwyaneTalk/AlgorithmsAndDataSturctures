/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Isomorphic Strings
*             : https://leetcode.com/problems/isomorphic-strings/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

bool isIsomorphic(char* s, char* t) {
    char map[256];
    bool used[256];
    int len_s = strlen(s);
    int len_t = strlen(t);
    int i;
    if (len_s != len_t)  return false;
    memset(map, 0, sizeof(char)* 256);
    memset(used, 0, sizeof(char)* 256);
    for (i = 0; i < len_s; ++i) {
        if (!map[s[i]]) {
            if (used[t[i]]) return false;
            map[s[i]] = t[i];
            used[t[i]] = 1;
        } else {
            if (map[s[i]] != t[i])
                return false;
        }
    }
    return true;
}

int main() {
    char s[] = "abb";
    char t[] = "cdd";
    int ans = isIsomorphic(s, t);
    printf("%d\n", ans);
    if (ans)
        printf("YES!");
    else
        printf("No!");
    system("pause");
    return 0;
}
