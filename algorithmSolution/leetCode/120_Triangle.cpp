/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode120  : Triangle
*                : https://leetcode.com/problems/triangle/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes) {
    if (!triangle || triangleRowSize < 1 || !triangleColSizes)  return 0;
    int* dp = (int*)malloc(sizeof(int)* triangleRowSize);
    dp[0] = triangle[0][0];
    int tmp1, tmp2, ans;
    for (int i = 1; i < triangleRowSize; ++i) {
        tmp1 = dp[0];
        dp[i] = dp[i - 1] + triangle[i][i];
        dp[0] = dp[0] + triangle[i][0];
        for (int j = 1; j < i; ++j) {
            tmp2 = MIN(tmp1, dp[j]) + triangle[i][j];
            tmp1 = dp[j];
            dp[j] = tmp2;
        }
    }
    ans = dp[0];
    for (int i = 1; i < triangleRowSize; ++i)
        ans = MIN(ans, dp[i]);
    return ans;
}

int main() {
    system("pause");
    return 0;
}
