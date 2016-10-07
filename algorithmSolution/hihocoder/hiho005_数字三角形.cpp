/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : 数字三角形
*             : http://hihocoder.com/contest/hiho5/problem/1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct {
    int n;
    int prize[201][201];
    int val1[201];
    int val2[201];
} publicData;


void input(publicData *data) {
    int i, j;
    //FILE *fin = fopen("input.txt", "r");
    scanf("%d", &data->n);
    //fscanf(fin, "%d", &data->n);
    for (i = 1; i <= data->n; ++i) {
        for (j = 1; j <= i; ++j) {
            scanf("%d", &data->prize[i][j]);
            //fscanf(fin, "%d", &data->prize[i][j]);
        }
    }
}

// 递推式：
//      f(i,0) = f(i-1, 0) + prize(i, 0)
//      f(i,j) = MAX{f(i-1,j), f(i-1,j-1)} + prize(i,j)
//      f(i,i) = f(i-1,i-1) + prize(i,i)
//空间：2*N的数组，可以进一步优化为N的数组
int solution(publicData *data) {
    int i, j, ans = 0;
    data->val1[1] = data->prize[1][1];
    for (i = 2; i <= data->n; ++i) {
        if (i & 1) {    //奇数行：val2 -> val1
            data->val1[1] = data->val2[1] + data->prize[i][1];
            for (j = 2; j < i; ++j) {
                data->val1[j] = MAX(data->val2[j], data->val2[j - 1]) + data->prize[i][j];
            }
            data->val1[i] = data->val2[i - 1] + data->prize[i][i];
        } else {    //偶数航： val1 -> val2
            data->val2[1] = data->val1[1] + data->prize[i][1];
            for (j = 2; j < i; ++j) {
                data->val2[j] = MAX(data->val1[j], data->val1[j - 1]) + data->prize[i][j];
            }
            data->val2[i] = data->val1[i - 1] + data->prize[i][i];
        }
    }
    if (data->n & 1) {
        for (i = 1; i <= data->n; ++i) {
            ans = MAX(data->val1[i], ans);
        }
    } else {
        for (i = 1; i <= data->n; ++i) {
            ans = MAX(data->val2[i], ans);
        }
    }
    return ans;
}

int main() {
    publicData data;
    input(&data);
    int ans = solution(&data);
    printf("%d\n", ans);
    //system("pause");
    return 0;
}