/*   DwyaneTalk@gmail.com
*   by lutao
*   POJ1664/3014 : 整数划分3
*                : http://poj.org/problem?id=1664
*                : http://poj.org/problem?id=3014
*                : http://www.cnblogs.com/DwyaneTalk/p/4617206.html
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//递归
int solution1(int m, int n) {
    if (n == 1)         return 1;
    if (m < n)          return solution1(m, n-1);
    else if (m == n)    return solution1(m, n-1) + 1;
    else                return solution1(m, n - 1) + solution1(m - n, n);
}

//递推
int solution2(int m, int n) {
    int nums[11][11] = {0};
    for (int i = 1; i <= m; ++i)    nums[i][1] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 2; j <= n; ++j) {
            if (i < j)          nums[i][j] = nums[i][j - 1];
            else if (i == j)    nums[i][j] = nums[i][j - 1] + 1;
            else                nums[i][j] = nums[i][j - 1] + nums[i - j][j];
        }
    }
    return nums[m][n];
}

int solution(int m, int n) {
    if (rand() % 2) return solution1(m, n);
    else            return solution2(m, n);
}

int main() {
    int T, m, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &m, &n);
        printf("%d\n", solution(m, n));
    }
    system("pause");
    return 0;
}
