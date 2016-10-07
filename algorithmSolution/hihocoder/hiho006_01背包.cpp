/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : 01背包
*             : http://hihocoder.com/contest/hiho6/problem/1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct {
    int n;
    int m;
    int value[500];
    int need[500];
    int ans[100001];
} publicData;


void input(publicData *data) {
    int i;
    //FILE *fin = fopen("input.txt", "r");
    scanf("%d%d", &data->n, &data->m);
    //fscanf(fin, "%d%d", &data->n, &data->m);
    for (i = 0; i < data->n; ++i) {
        scanf("%d%d", &data->need[i], &data->value[i]);
        //fscanf(fin, "%d%d", &data->need[i], &data->value[i]);
    }
}

//  递推关系式：
//  j >= need(i)时： f(i,j) = MAX{f(i-1, j), f(i-1, j-need(i)) + value(i)}
//  j <  need(i)时： f(i,j) = f(i-1, j)
int solution(publicData *data) {
    int i, j;
    for (i = 0; i <= data->m; ++i)
        data->ans[i] = 0;
    for (i = 0; i < data->n; ++i) {
        for (j = data->m; j >= data->need[i]; --j) {
            data->ans[j] = MAX(data->ans[j], data->ans[j - data->need[i]] + data->value[i]);
        }
    }
    return data->ans[data->m];
}

int main() {
    publicData data;
    input(&data);
    int ans = solution(&data);
    printf("%d\n", ans);
    //system("pause");
    return 0;
}