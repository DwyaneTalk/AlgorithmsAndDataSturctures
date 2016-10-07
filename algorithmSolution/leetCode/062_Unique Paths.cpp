/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Unique Paths
*             : https://leetcode.com/problems/unique-paths/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

long multiply(int start, int end) {
    long ans = 1;
    while (start <= end) {
        ans *= start++;
    }
    return ans;
}

//  排列组合 ans = (n - 1 + m - 1)! / ((m - 1)! * (n - 1)!)
int solution1(int m, int n) {
    --m;
    --n;
    if (m > n) {
        return multiply(m + 1, m + n) / multiply(1, n);
    } else {
        return multiply(n + 1, m + n) / multiply(1, m);
    }
}

//  DP一下
int solution2(int m, int n){
    int lookup[100][100];
    int i, j;
    for (i = 0; i < m; ++i) {
        lookup[i][0] = 1;
    }
    for (j = 0; j < n; ++j) {
        lookup[0][j] = 1;
    }

    for (i = 1; i < m; ++i) {
        for (j = 1; j < n; ++j) {
            lookup[i][j] = lookup[i - 1][j] + lookup[i][j - 1];
        }
    }
    return lookup[m - 1][n - 1];
}

int uniquePaths(int m, int n) {
    return solution1(m, n);
    return solution2(m, n);
}

int main() {
    int m = 34, n =24;
    int ans1 = solution1(m, n);
    int ans2 = solution2(m, n);
    printf("%d\t%d\n", ans1, ans2);
    system("pause");
    return 0;
}