/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode268  : Excel Sheet Column Title
*                : https://leetcode.com/problems/excel-sheet-column-title/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char* convertToTitle(int n) {
    char* ans = (char*)malloc(sizeof(char)*10);
    memset(ans, 0, sizeof(char) * 10);
    int cnt = 0, num;
    while(n) {
        num = n % 26;
        n /= 26;
        if(!num) {
            num = 26;
            n -=1;
        }
        ans[cnt++] = 'A' + num - 1;
    }
    char tmp;
    for(num = 0, cnt--; num < cnt; ++num, --cnt) {
        tmp = ans[num];
        ans[num] = ans[cnt];
        ans[cnt] = tmp;
    }
    return ans;
}

int main() {
    char* ans = convertToTitle(26);
    printf("%s\n", ans);
    system("pause");
    return 0;
}
