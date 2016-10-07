/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Longest Common Prefix
 *             : https://leetcode.com/problems/longest-common-prefix/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


char* longestCommonPrefix(char** strs, int strsSize) {
    int minLen = INT_MAX, len = 0, i = 0, j = 0, ptr = 0;
    char ch = '\0';
    char *ans = NULL;
    for(i = 0; i < strsSize; ++i) {
        if((len = strlen(strs[i])) < minLen)
            minLen = len;
    }
    if(strsSize == 0)   minLen = 0;
    ans = (char *) malloc((minLen + 1) * sizeof(char));
    for(i = 0; i < minLen; ++i) {
        ch = strs[0][i];
        for(j = 1; j < strsSize; ++j) {
            if(ch != strs[j][i])
                break;
        }
        if(j == strsSize) {
            ans[ptr++] = ch;
        } else {
            break;
        }
    }
    ans[ptr] = '\0';
    return ans;
}

int main() {
    char *strArr[3];
    strArr[0] = "";
    char *ans = longestCommonPrefix(strArr, 1);
    printf("%s\n", ans);
    return 0;
}
