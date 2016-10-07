/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : 彩色的树
*             : http://hihocoder.com/contest/msbop2015round2a/problem/1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <map>
using namespace std;

void solution1();//简单搜索，小数据可以过，大数据TLE
void solution2();//预处理树的存储结构，大数据可以过

int main() {
    //solution1();
    solution2();
    return 0;
}

typedef struct {
    int next;   //下一个边
    int point;  //边的一个点
} Edge;


Edge edge[210000];  //链表的结点，表示一条边
int node[110000];   //每个node对应的边的链表首索引
int num;
int color[110000];  // record the color of each node
int father[110000]; // record the fatner node of each node
map<int, int>nei_nums[110000];//record nums of the neighbor nodes in given color


void add_edge(int x, int y) {
    edge[++num] = Edge{ node[x], y };
    node[x] = num;
}

//递归构造，将无根树转换成有根树，并记录每个结点的父节点，以及每个结点的子节点各个颜色的数目（直接存成图，在后序更新结点颜色时不易处理）
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

void solution2() {// C++实现（要用到map，否则空间太大，自己C实现map搞不定）
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
        dfs(1); //以1为根构造树
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