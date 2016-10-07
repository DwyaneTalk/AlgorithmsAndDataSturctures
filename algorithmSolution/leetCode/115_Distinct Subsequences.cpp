/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode115  : Distinct Subsequences
*                : https://leetcode.com/problems/distinct-subsequences/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>



int numDistinct(char* s, char* t) {
    if (!s || !t)   return 0;
    int sl = strlen(s);
    int tl = strlen(t);
    int **dp = (int**) malloc(sizeof(int*) * (sl + 1));
    for (int i = 0; i <= sl; ++i)   dp[i] = (int*)malloc(sizeof(int)* (tl + 1));
    memset(dp[0], 0, sizeof(int)* (tl + 1));
    for (int i = 0; i <= sl; ++i)   dp[i][0] = 1;
    for (int i = 1; i <= sl; ++i) {
        for (int j = 1; j <= tl; ++j) {
            dp[i][j] = dp[i - 1][j] + (s[i - 1] == t[j - 1] ? dp[i - 1][j - 1] : 0);
        }
    }
    return dp[sl][tl];
}

int main() {
    char s[] = "daacaedaceacabbaabdccdaaeaebacddadcaeaacadbceaecddecdeedcebcdacdaebccdeebcbdeaccabcecbeeaadbccbaeccbbdaeadecabbbedceaddcdeabbcdaeadcddedddcececbeeabcbecaeadddeddccbdbcdcbceabcacddbbcedebbcaccac";
    char t[] = "ceadbaa";
    int ans = numDistinct(s, t);
    printf("ans : %d\n", ans);
    system("pause");
    return 0;
}
