/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : 骨牌覆盖问题·三
*             : http://hihocoder.com/contest/hiho43/problem/1
*/

// todo : 有关矩阵相乘的优化：1、考虑cache；2、矩阵分块；3、稀疏矩阵的存储和相乘
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 12357

//前ik列已经构造好，开始构造ik+1(和ik + 2)列
void buildTable(int *table, int k, int state_pre, int state_cur, int ik){
    if (ik < k) {
        //前一行ik列没有（0），竖放（当前行ik列变成1）
        buildTable(table, k, state_pre, state_cur + (1 << ik), ik + 1);
        //前一行ik列有（1），不放（当前行ik列为0）
        buildTable(table, k, state_pre + (1 << ik), state_cur, ik + 1);
        //前一行ik、ik+1列有（11），横放（当前行ik、ik+1列变成1）
        if (ik + 2 <= k) {
            buildTable(table, k, state_pre + (1 << ik) + (1 << (ik + 1)), state_cur + (1 << ik) + (1 << (ik + 1)), ik + 2);
        }
    } else {
        int mk = 1 << k;
        table[state_pre * mk + state_cur] = 1;
    }
}
void printTable(int *table, int k) {
    int i, j;
    int size = 1 << k;
    int mk = 1 << k;
    printf("print matrix : \n");
    for (i = 0; i < size; ++i) {
        for (j = 0; j < size; ++j) {
            printf("%d\t", table[i * mk  + j]);
        }
        printf("\n");
    }
    printf("\n");
}

void matrixPow(int *table, int *matrix, int k, int n) {
    int i, j, l, m;
    int mk = 1 << k;
    if (n == 1) {
        m = 1 << k;
        for (i = 0; i < m; ++i) {
            for (j = 0; j < m; ++j) {
                matrix[i * mk + j] = table[i * mk + j];
            }
        }
    } else {
        int *matrix_t = (int *)malloc(sizeof(int)* mk * mk);
        memset(matrix_t, 0, sizeof(int)* mk * mk);
        matrixPow(table, matrix_t, k, n >> 1);
        m = 1 << k;
        if (n & 1) {
            int *matrix_tt = (int *)malloc(sizeof(int)* mk * mk);
            memset(matrix_tt, 0, sizeof(int)* mk * mk);
            for (i = 0; i < m; ++i) {
                for (j = 0; j < m; ++j) {
                    for (l = 0; l < m; ++l) {
                        matrix_tt[i * mk + l] = (matrix_tt[i * mk + l] + (matrix_t[i * mk + j] * matrix_t[j * mk + l]) + MOD) % MOD;
                    }
                }
            }
            for (i = 0; i < m; ++i) {
                for (j = 0; j < m; ++j) {
                    for (l = 0; l < m; ++l) {
                        matrix[i * mk + l] = (matrix[i * mk + l] + (table[i * mk + j] * matrix_tt[j * mk + l]) + MOD) % MOD;
                    }
                }
            }
        } else {
            for (i = 0; i < m; ++i) {
                for (j = 0; j < m; ++j) {
                    for (l = 0; l < m; ++l) {
                        matrix[i * mk + l] = (matrix[i * mk + l] + (matrix_t[i * mk + j] * matrix_t[j * mk + l]) + MOD) % MOD;
                    }
                }
            }
        }
    }
    printf("n = %d:\n", n);
    printTable(matrix, k);
}

int solution(int *table, int k, int N){
    int mk = 1 << k;
    int *matrix = (int *)malloc(sizeof(int)* mk * mk);
    memset(matrix, 0, sizeof(int)* mk * mk);
    matrixPow(table, matrix, k, N);
//    printTable(matrix, k);
    return matrix[((1 << k) - 1) * mk + (1 << k) - 1];
}

int main() {
    int N = 62247088, k = 2;
    //    scanf("%d", &N);//k对应着列，N对应着行
    int mk = 1 << k;
    int *table = (int *)malloc(sizeof(int)* mk * mk);
    memset(table, 0, sizeof(int)* mk * mk);
    buildTable(table, k, 0, 0, 0);
  //  printTable(table, k);
    int ans = solution(table, k, N);
    free(table);
    printf("%d\n", ans);
    system("pause");
    return 0;
}
