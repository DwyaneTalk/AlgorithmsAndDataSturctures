/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : ²©ŞÄÓÎÏ·¡¤NimÓÎÏ·¡¤¶ş   
 *             : http://hihocoder.com/contest/hiho45/problem/1
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int solution(char *s) {
    int i, len = strlen(s), ans = 0;
    for (i = 0; i < len; ++i) {
        if (s[i] == 'H') {
            ans = ans ^ (i + 1);
        }
    }
    return ans;
}

int main() {
    int N;
    char *s;
    scanf("%d", &N);
    s = (char *)malloc(sizeof(char)* (N + 1));
    scanf("%s", s);
    int ans = solution(s);
    if (ans)
        printf("Alice\n");
    else
        printf("Bob\n");
    system("pause");
    return 0;
}
