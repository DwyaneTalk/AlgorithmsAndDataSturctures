/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : N-Queens II  
 *             : https://leetcode.com/problems/n-queens-ii/
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


void DFS(int curr, int m1, int m2, int m3, int n, int *ans) {
    if (curr == n) { // curr记录当前要放置皇后的行数
        ++(*ans);
    } else {
        int i = 0, b = 1, mask = m1 | m2 | m3;  //m1, m2, m3分别表示竖直、45度和135度 的掩码， mask中'1'记录当前行不能放置皇后的位置
        for (; i < n; ++i, b <<= 1) {    //i针对0~n-1的每列进行循环，b中的'1'表示第0到n-1位。
            if (!(mask & b)) {
                DFS(curr + 1, m1 | b, (m2 | b) >> 1, (m3 | b) << 1, n, ans);
            }
        }
    }
}

int totalNQueens(int n) {
    int ans = 0;
    if (n)
        DFS(0, 0, 0, 0, n, &ans);
    return ans;
}
int main() {
    int n = 4;
    int ans = totalNQueens(n);
    printf("%d\n", ans);
    system("pause");
    return 0;
}
