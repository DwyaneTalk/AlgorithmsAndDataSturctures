/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : N-Queens
*             : https://leetcode.com/problems/n-queens/
*/


#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;

// 分支回溯，用数组存储路径、状态
// N-Queens II中采用了bitmap的方式存储
class Solution {
private:
    int *used0, *used1, *used2; //0，1，2分别记录当前路径上，竖直、主对角线和副对角线上已经存在的皇后
    int n, *route;
    vector<vector<string>>  ans;

public:
    void init(int n) {
        used0 = new int[n];// (int *)calloc(n, sizeof(int));
        used1 = new int[2 * n];// (int *)calloc(2 * n, sizeof(int));
        used2 = new int[2 * n];// (int *)calloc(2 * n, sizeof(int));
        memset(used0, 0, sizeof(int)* n);
        memset(used1, 0, sizeof(int)* n * 2);
        memset(used2, 0, sizeof(int)* n * 2);
        route = new int[n];// (int *)malloc(sizeof(int)* n);
        this->n = n;
    }
    
    ~Solution() {
        delete used0;
        delete used1;
        delete used2;
        delete route;
    }

    void finishOneSolution() {
        vector<string> solution;
        for (int i = 0; i < n; ++i) {
            string str(n, '.');
            str[route[i]] = 'Q';
            solution.push_back(str);
        }
        ans.push_back(solution);
    }

    void DFS(int curr) {
        if (curr == n) {
            finishOneSolution();
        } else {
            int i, i_1, i_2;
            for (i = 0; i < n; ++i) {   //i对列循环
                i_1 = i + curr;
                i_2 = n - 1 - i + curr;
                if (!used0[i] && !used1[i_1] && !used2[i_2]) {
                    route[curr] = i;
                    used0[i]    = 1;
                    used1[i_1]  = 1;
                    used2[i_2]  = 1;
                    DFS(curr + 1);
                    used0[i] = 0;
                    used1[i_1] = 0;
                    used2[i_2] = 0;
                }
            }
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        init(n);
        DFS(0);
        return ans;
    }
};

int main() {
    int n = 4;
    Solution solution;
    vector<vector<string>> ans;
    ans = solution.solveNQueens(n);
    vector<vector<string>>::iterator vvs;
    vector<string>::iterator vs;
    vector<string> one_ans;
    for (vvs = ans.begin(); vvs != ans.end(); ++vvs) {
        for (vs = vvs->begin(); vs != vvs->end(); ++vs) {
            cout << *vs << endl;
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
