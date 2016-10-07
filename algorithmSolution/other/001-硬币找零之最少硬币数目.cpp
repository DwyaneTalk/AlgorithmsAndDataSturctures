/*   DwyaneTalk@gmail.com
*   by lutao
*   NYOJ995   : 硬币找零·最少硬币数
*             : http://acm.nyist.net/JudgeOnline/problem.php?pid=995
*             : http://www.cnblogs.com/DwyaneTalk/p/4615562.html
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define     MIN(a, b)   ((a) > (b) ? (b) : (a))

int solution1(int N, int T, int value[50]) {
    int *coin_nums = (int *)malloc(sizeof(int)* (T + 1)); //coinNum[T]为目标函数
    int min_coin_num, tmp_coin_num;
    int ans_coin_nums;
    coin_nums[0] = 0;     //initial condition

    for (int ti = 1; ti <= T; ++ti) {      //依次计算coinNum[ti]
        min_coin_num = ti + 1;            //因为vi >= 1, 所以coin_num[i] <= ti，初始为ti + 1表示无法组合出ti

        for (int ni = 0; ni < N; ++ni) {

            if (value[ni] <= ti) {
                tmp_coin_num = coin_nums[ti - value[ni]] + 1;
                min_coin_num = MIN(min_coin_num, tmp_coin_num);
            }
        }

        coin_nums[ti] = min_coin_num;
        //printf("T:%d  nums:%d\n", ti, min_coin_num);
    }
    while (coin_nums[T] == T + 1)   --T;
    ans_coin_nums = coin_nums[T];
    free(coin_nums);
    return ans_coin_nums;
}

int solution2(int N, int T, int value[50]) {
    int *coin_nums = (int *)malloc(sizeof(int)* (T + 1)); //coinNum[T]为目标函数
    int tmp_coin_num, tmp_value;
    int ans_coin_nums;
    coin_nums[0] = 0;     //initial condition

    for (int ti = 1; ti <= T; ++ti)  coin_nums[ti] = ti + 1;
    for (int ti = 0; ti <= T; ++ti) {
        tmp_coin_num = coin_nums[ti] + 1;
        for (int ni = 0; ni < N; ++ni) {
            tmp_value = ti + value[ni];
            if (tmp_value <= T)
                coin_nums[tmp_value] = MIN(coin_nums[tmp_value], tmp_coin_num);
        }
        //printf("T:%d  nums:%d\n", ti, coin_nums[ti]);
    }

    while (coin_nums[T] == T + 1)   --T;
    ans_coin_nums = coin_nums[T];
    free(coin_nums);
    return ans_coin_nums;
}

int solution(int N, int T, int value[50]) {
    if (rand() % 2) return solution1(N, T, value);
    else    return solution2(N, T, value);
}

int main() {
    int N, T;
    int value[50];
    scanf("%d%d", &N, &T);
    while (N || T) {
        for (int i = 0; i < N; ++i) scanf("%d", value + i);
        printf("%d\n", solution(N, T, value));
        scanf("%d%d", &N, &T);
    }
    return 0;
}
