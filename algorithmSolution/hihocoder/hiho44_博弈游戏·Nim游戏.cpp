/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : 博弈游戏·Nim游戏
*             : http://hihocoder.com/contest/hiho44/problem/1
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int solution(int N, int A[101]) {
    int pos = 0, i;
    for (i = 0; i < N; ++i) {
        pos = pos ^ A[i];
    }
    if (pos)    return 1;//N-position
    else        return 0;//P-position
}

int main() {
    int N, A[101], i, ans;
    scanf_s("%d", &N);
    for (i = 0; i < N; ++i) {
        scanf_s("%d", &A[i]);
    }
    ans = solution(N, A);
    if (ans)    printf("%s\n", "Alice");
    else        printf("%s\n", "Bob");
    system("pause");
    return 0;
}
