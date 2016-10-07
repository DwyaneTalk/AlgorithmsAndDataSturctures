/*   DwyaneTalk@gmail.com
*   by lutao
*   USACO2.3.4: 硬币找零·找钱方案数
*             : http://www.nocow.cn/index.php/USACO/money
*             : http://www.cnblogs.com/DwyaneTalk/p/4616249.html
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//递归调用 DP(n, t) = DP(n-1, t) + DP(n, t - Vn)
int solution1(int N, int T, int value[50]) {
    if (T < 0)  return 0;
    if (T == 0) return 1;
    if (N < 0)  return 0;
    return solution1(N - 1, T, value) + solution1(N, T - value[N - 1], value);
}

int solution2(int N, int T, int value[50]) {
    int **DP = (int **)malloc(sizeof(int *) * N);
    int ans_num;
    for (int i = 0; i < N; ++i) {
        DP[i] = (int *)malloc(sizeof(int)* (T + 1));
        DP[i][0] = 1;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 1; j <= T; ++j) {
            DP[i][j] = (i >= 1 ? DP[i - 1][j] : 0) + (j >= value[i] ? DP[i][j - value[i]] : 0);
        }
    }

    ans_num = DP[N - 1][T];
    for (int i = 0; i < N; ++i)
        free(DP[i]);
    free(DP);
    return ans_num;
}

int solution3(int N, int T, int value[50]) {
    int *DP_pre_line = (int *)malloc(sizeof(int)* (T + 1));
    int *DP_cur_line = (int *)malloc(sizeof(int)* (T + 1));
    int ans_num;
    DP_pre_line[0] = 1;
    DP_cur_line[0] = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 1; j <= T; ++j) {
            if (i == 0) DP_cur_line[j] = j >= value[i] ? DP_cur_line[j - value[i]] : 0;
            else        DP_cur_line[j] = DP_pre_line[j] + (j >= value[i] ? DP_cur_line[j - value[i]] : 0);
        }
        memcpy(DP_pre_line, DP_cur_line, sizeof(int)* (T + 1));
    }
    ans_num = DP_cur_line[T];
    free(DP_pre_line);
    free(DP_cur_line);
    return ans_num;
}

int solution(int N, int T, int value[50], int times) {
    times %= 3;
    if (times == 0)         return solution1(N, T, value);
    else if(times == 1)     return solution2(N, T, value);
    else                    return solution3(N, T, value);
}

int main() {
    int N, T;
    int value[50];
    int times = 0;
    //FILE* fin =  fopen("input.txt", "r");
    //fscanf(fin, "%d%d", &N, &T);
    scanf("%d%d", &N, &T);
    while (N || T) {
        times = 0;
        //for (int i = 0; i < N; ++i) fscanf(fin, "%d", value + i);
        for (int i = 0; i < N; ++i) scanf("%d", value + i);
        printf("solution%d: %d\n", times, solution(N, T, value, times++));
        printf("solution%d: %d\n", times, solution(N, T, value, times++));
        printf("solution%d: %d\n", times, solution(N, T, value, times++));
        //fscanf(fin, "%d%d", &N, &T);
        scanf("%d%d", &N, &T);
    }
    //system("pause");
    return 0;
}
