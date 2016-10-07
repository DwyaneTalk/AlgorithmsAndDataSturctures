/*   DwyaneTalk@gmail.com
*   by lutao
*   NYOJ90    : 整数划分
*             : http://acm.nyist.net/JudgeOnline/problem.php?pid=90
*             : http://www.cnblogs.com/DwyaneTalk/p/4617057.html
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//递归
int solution1(int n, int m) {
    if (n == 1 || m == 1)   return 1;
    else if (m == n)        return solution1(n, m - 1) + 1;
    else if (m < n)         return solution1(n - m, m) + solution1(n, m - 1);
    else                    return solution1(n, n);
}

//递推
int solution2(int n, int m) {
    int nums[11][11];
    for (int i = 1; i <= n; ++i)    nums[i][1] = 1;
    for (int j = 1; j <= m; ++j)    nums[1][j] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= m; ++j) {
            if (i == j) {
                nums[i][j] = nums[i][j - 1] + 1;
            } else if (i < j) {
                nums[i][j] = nums[i][i];
            } else {
                nums[i][j] = nums[i - j][j] + nums[i][j - 1];
            }
        }
    }
    return nums[n][m];
}

int solution(int n) {
    if (rand() % 2) return solution1(n, n);
    else            return solution2(n, n);
}

int main() {
    int M, n;
    scanf("%d", &M);
    while (M--) {
        scanf("%d", &n);
        printf("%d\n", solution(n));
    }
    //system("pause");
    return 0;
}
