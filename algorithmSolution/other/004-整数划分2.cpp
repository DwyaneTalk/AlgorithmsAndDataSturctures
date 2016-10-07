/*   DwyaneTalk@gmail.com
*   by lutao
*   NYOJ176   : 整数划分2
*             : http://acm.nyist.net/JudgeOnline/problem.php?pid=176
*             : http://www.cnblogs.com/DwyaneTalk/p/4617131.html
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//递归
int solution1(int m, int n) {
    if (n == 1)         return 1;
    if (m < n)          return 0;
    else if (m == n)    return 1;
    else {
        int sum = 0, left = m - n;
        for (int i = 1; i <= n && left >= i; ++i) {
            sum += solution1(left, i);
        }
        return sum;
    }
}

//递推
int solution2(int m, int n) {
    int nums[101][101] = {0};
    int sum, left;
    for (int i = 1; i <= m; ++i)    nums[i][1] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 2; j <= n && j <= i; ++j) {
            if (i < j)          nums[i][j] = 0;
            else if (i == j)    nums[i][j] = 1;
            else {
                sum = 0;
                left = i - j;
                for (int k = 1; k <= j && left >= k; ++k) {
                    sum += nums[left][k];
                }
                nums[i][j] = sum;
            }
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
    //system("pause");
    return 0;
}
