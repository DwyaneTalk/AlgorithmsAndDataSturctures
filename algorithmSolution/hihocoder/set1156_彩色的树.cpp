/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : ��ɫ����
*             : http://hihocoder.com/contest/msbop2015round2a/problem/1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <map>
using namespace std;

void solution1();//��������С���ݿ��Թ���������TLE
void solution2();//Ԥ�������Ĵ洢�ṹ�������ݿ��Թ�

int main() {
    //solution1();
    solution2();
    return 0;
}

typedef struct {
    int next;   //��һ����
    int point;  //�ߵ�һ����
} Edge;


Edge edge[210000];  //����Ľ�㣬��ʾһ����
int node[110000];   //ÿ��node��Ӧ�ıߵ�����������
int num;
int color[110000];  // record the color of each node
int father[110000]; // record the fatner node of each node
map<int, int>nei_nums[110000];//record nums of the neighbor nodes in given color


void add_edge(int x, int y) {
    edge[++num] = Edge{ node[x], y };
    node[x] = num;
}

//�ݹ鹹�죬���޸���ת�����и���������¼ÿ�����ĸ��ڵ㣬�Լ�ÿ�������ӽڵ������ɫ����Ŀ��ֱ�Ӵ��ͼ���ں�����½����ɫʱ���״���
void dfs(int x) {   
    int count = 0, i = node[x];
    while (i && edge[i].point != father[x]) {
        count++;
        father[edge[i].point] = x;
        dfs(edge[i].point);
        i = edge[i].next;
    }
    nei_nums[x][0] = count;
}

void solution2() {// C++ʵ�֣�Ҫ�õ�map������ռ�̫���Լ�Cʵ��map�㲻����
    int T, n, x, y, q, op;
    int i = 0, j;
    int ans = 1;
    cin >> T;
    while (++i <= T) {
        cout << "Case #" << i << ":" << endl;
        cin >> n;
        ans = 1;
        num = 0;
        for (j = 1; j <= n; ++j) {
            color[j] = 0;
            nei_nums[j].clear();
            node[j] = 0;
        }
        for (j = 0; j < n - 1; j++) {
            cin >> x >> y;
            add_edge(x, y);
            add_edge(y, x);
        }
        dfs(1); //��1Ϊ��������
        cin >> q;
        for (j = 0; j < q; j++) {
            cin >> op;
            if (op == 1) {
                cout << ans << endl;
            } else {
                cin >> x >> y;
                if (father[x]) {
                    if (color[father[x]] == color[x]) ans++;
                    if (color[father[x]] == y) ans--;
                    nei_nums[father[x]][y]++;
                    nei_nums[father[x]][color[x]]--;
                }
                ans += nei_nums[x][color[x]];
                ans -= nei_nums[x][y];
                color[x] = y;
            }
        }
    }
}

void solution1() {
    int T, n, q, x, y, op;
    int edge[100000][2];
    int color[100000];
    int ans;
    scanf("%d", &T);
    int i = 0, j, k;
    while (++i <= T) {
        scanf("%d", &n);
        ans = 1;
        memset(color, 0, sizeof(int)* (n + 1));
        for (j = 0; j < n - 1; ++j) {
            scanf("%d%d", &edge[j][0], &edge[j][1]);
        }
        scanf("%d", &q);
        printf("Case #%d:\n", i);
        for (j = 0; j < q; ++j) {
            scanf("%d", &op);
            if (op == 1) {
                printf("%d\n", ans);
            } else {
                scanf("%d%d", &x, &y);
                if (color[x] != y) {
                    for (k = 0; k < n - 1; ++k) {
                        if (edge[k][0] == x) {
                            if (color[edge[k][1]] == y)
                                ans--;
                            else if (color[edge[k][1]] == color[x])
                                ans++;
                        } else if (edge[k][1] == x) {
                            if (color[edge[k][0]] == y)
                                ans--;
                            else if (color[edge[k][0]] == color[x])
                                ans++;
                        }
                    }
                    color[x] = y;
                }
            }
        }
    }
}