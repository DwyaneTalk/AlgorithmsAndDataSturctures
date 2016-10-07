/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCode : Regular Expression Matching
 *            : https://leetcode.com/problems/regular-expression-matching/
*/

#include<stdio.h>
#include<string.h>

bool isCharMatch(char *s, char *p){
    return (*s == *p) || (*p == '.' && *s != '\0');
}

// reverse
//bool isMatch(char* s, char* p) {
//    if(*p == '\0')  return *s == '\0';
//
//    if(*(p + 1) == '*') {
//        if(isMatch(s, p + 2)) return true;  //tip: partial p covering the entire s is a accepted
//        while(isCharMatch(s, p)){
//            if(isMatch(++s, p + 2))
//                return true;
//        }
//        return false;
//    } else {
//        if(!isCharMatch(s, p))  return false;
//        return isMatch(s + 1, p + 1);
//    }
//}

// DP with lookup-table
bool isMatch(char *s, char *p) {
    int sLen = strlen(s);
    int pLen = strlen(p);
    int dp[pLen + 1][sLen + 1];
    int i, j, ti, tj;
    bool f;

    for(i = 0; i < sLen; i++)   dp[pLen][i] = false;
    dp[pLen][sLen] = true;

    for(j = pLen - 1; j >= 0; j--) {
        for(i = sLen; i >= 0; i--) {
            ti = i;
            tj = j;
            if(p[tj + 1] == '*') {
                f = false;
                if(dp[tj + 2][ti])
                    f = true;
                else {
                    while(isCharMatch(&s[ti], &p[tj])){
                        if(dp[tj + 2][++ti])
                            f = true;
                    }
                }
            } else {
                if(isCharMatch(&s[ti], &p[tj]))
                    f = dp[tj + 1][ti + 1];
                else
                    f = false;
            }
            dp[j][i] = f;
        }
    }
//    for(i = 0; i <= sLen; i++) {
//        for(j = 0; j <= pLen; j++)
//            printf("%d\t", dp[j][i]);
//        printf("\n");
//    }
    return dp[0][0];
}

int main() {
    char s[] = "aab";
    char p[] = "c*a*b";
    bool ans = isMatch(s, p);
    printf("%d\n", ans);
    return 0;
}













