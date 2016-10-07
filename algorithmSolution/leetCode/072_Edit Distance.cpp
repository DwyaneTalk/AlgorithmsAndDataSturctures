/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Edit Distance
*             : https://leetcode.com/problems/edit-distance/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minDistance(char* word1, char* word2) {
    if (!word1 || !word2)   return 0;
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    if (!len1)  return len2;
    if (!len2)  return len1;
    int *ans = (int *)malloc(sizeof(int) * (len2 + 1));
    int i, j, pre, cur;
    for (i = 0; i <= len2; ++i)     ans[i] = i;
    for (i = 1; i <= len1; ++i) {
        pre = ans[0];
        ans[0] = i;// j = 0
        for (j = 1; j <= len2; ++j) {
            cur = ans[j];
            if (*(word1 + i - 1) == *(word2 + j - 1)) {
                ans[j] = pre;
            } else {
                ans[j] = MIN(MIN(ans[j], ans[j - 1]), pre) + 1;
            }
            pre = cur;
        }
    }
    return ans[len2];
}

int main() {
    char word1[] = "tesatq";
    char word2[] = "tsta";
    int ans = minDistance(word1, word2);
    printf("%d\n", ans);
    system("pause");
    return 0;
}
