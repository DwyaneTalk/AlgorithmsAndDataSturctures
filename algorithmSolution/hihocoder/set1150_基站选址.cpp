/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : ��վѡַ
*             : http://hihocoder.com/contest/msbop2015qual/problem/3
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int ABS(int x, int y){
    return x > y ? x - y : y - x;
}

int T, M, N, A, B;
int posA[1000][2]; //�û�λ��
int posB[100][2];  //ͨѶ��˾λ��
int xMin, xMax, yMin, yMax;

long userCost(int x1, int y1, int x2, int y2) {
    long dx = x1 - x2;
    long dy = y1 - y2;
    return (dx * dx + dy * dy);
}

int companyCost(int x, int y) {
    int i, min_cost = INT_MAX, cost;
    for (i = 0; i < B; ++i) {
        cost = ABS(posB[i][0], x) + ABS(posB[i][1], y);
        if (cost < min_cost)
            min_cost = cost;
    }
    return min_cost;
}

// ���С���ݿ���ͨ�������Ǵ�����TLE
long solution() {
    int i, j, k;
    long min_cost = INT_MAX;
    long cost;
    for (i = xMin; i <= xMax; ++i) {
        for (j = yMin; j <= yMax; ++j) {
            cost = companyCost(i, j);
            if (cost >= min_cost)
                continue;
            for (k = 0; k < A; ++k) {
                cost += userCost(i, j, posA[k][0], posA[k][1]);
                if (cost >= min_cost)
                    break;
            }
            if (k == A) {
                min_cost = cost;
            }
        }
    }
    return min_cost;
}

// ������Ҳ����ͨ��������ԭ����ݼ�����ѧ��֤��
long solutin2() {
    long sum_x = 0, sum_y = 0;
    int ave_x, ave_y;
    int i, x, y, j;
    long min_cost = 2e63 - 1;
    long cost;
    int list[4][2] = {
        { 0, 0 },
        { 0, 1 },
        { 1, 0 },
        { 1, 1 }
    };
    for (i = 0; i < A; i++) {
        sum_x += posA[i][0];
        sum_y += posA[i][1];
    }
    // users�ļ�������Ϊ��ѵ㣨����֤���ԣ�
    ave_x = sum_x / A;
    ave_y = sum_y / A;
    for (i = 0; i < 4; i++) {   //��������������Χ��4�����㣬Ѱ�����Ž�
        x = ave_x + list[i][0];
        y = ave_y + list[i][1];
        cost = companyCost(x, y);
        if (cost >= min_cost)   continue;
        for (j = 0; j < A; j++) {
            cost += userCost(x, y, posA[j][0], posA[j][1]);
            if (cost >= min_cost)
                break;
        }
        if (j == A) {
            min_cost = cost;
        }
    }
    return min_cost;
}

int main() {
    long cost;
    int i, j = 0;
    scanf("%d", &T);
    while (j++ < T) {
        scanf("%d %d %d %d", &N, &M, &A, &B);
        xMin = N;   xMax = 1;
        yMin = M;   yMax = 1;
        for (i = 0; i < A; i++) {
            scanf("%d %d", &posA[i][0], &posA[i][1]);
            if (posA[i][0] < xMin)  xMin = posA[i][0];
            if (posA[i][0] > xMax)  xMax = posA[i][0];
            if (posA[i][1] < yMin)  yMin = posA[i][1];
            if (posA[i][1] > yMax)  yMax = posA[i][1];
        }
        for (i = 0; i < B; i++) {
            scanf("%d%d", &posB[i][0], &posB[i][1]);
            if (posB[i][0] < xMin)  xMin = posB[i][0];
            if (posB[i][0] > xMax)  xMax = posB[i][0];
            if (posB[i][1] < yMin)  yMin = posB[i][1];
            if (posB[i][1] > yMax)  yMax = posB[i][1];
        }
        //cost = solution();
        cost = solutin2();
        printf("Case #%d: %ld\n", j, cost);
    }
    system("pause");
    return 0;
}