/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCode : ZigZag Conversion
 *            : https://leetcode.com/problems/zigzag-conversion/
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *convert(char *s, int nRows) {
    int len = strlen(s);
    int stride = 2 * nRows - 2;
    int i, j, pos = 0, w, tmp_len;
    char *ans = (char *)malloc((len + 1) * sizeof(char));
    if(nRows == 1) {
        memcpy(ans, s, len);
        ans[len] = '\0';
        return ans;
    }
    for (i = 0; i < nRows; i++) {
        if(i == 0 || i == nRows - 1) {
            for (j = i; j < len; j += stride) {
                ans[pos++] = s[j];
            }
        } else {
            w = (stride - i) - i;
            tmp_len = len - w;
            for (j = i; j < tmp_len; j += stride) {
                ans[pos++] = s[j];
                ans[pos++] = s[j + w];
            }
            if (j < len) {
                ans[pos++] = s[j];
            }
        }
    }
    ans[pos] = '\0';
    return ans;
}

int main() {
    char s[] = "A";
    char *ans = convert(s, 1);
    printf("%s\n", ans);
    return 0;
}
