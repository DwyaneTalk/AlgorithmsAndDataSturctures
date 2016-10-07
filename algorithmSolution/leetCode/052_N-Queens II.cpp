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
    if (curr == n) { // curr��¼��ǰҪ���ûʺ������
        ++(*ans);
    } else {
        int i = 0, b = 1, mask = m1 | m2 | m3;  //m1, m2, m3�ֱ��ʾ��ֱ��45�Ⱥ�135�� �����룬 mask��'1'��¼��ǰ�в��ܷ��ûʺ��λ��
        for (; i < n; ++i, b <<= 1) {    //i���0~n-1��ÿ�н���ѭ����b�е�'1'��ʾ��0��n-1λ��
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
