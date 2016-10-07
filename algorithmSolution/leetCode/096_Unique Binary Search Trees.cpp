/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode96   : Unique Binary Search Trees
*                : https://leetcode.com/problems/unique-binary-search-trees/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int numTrees(int n) {
    int ans, *num = (int*) malloc(sizeof(int) * (n + 1));
    num[0] = 1;
    for (int i = 1; i <= n; ++i) {
        num[i] = 0;
        for (int j = 1; j <= i; ++j) {
            num[i] += num[j - 1] * num[i - j];
        }
    }
    ans = num[n];
    free(num);
    return ans;
}

int main() {
    printf("%d\n", numTrees(2));
    system("pause");
    return 0;
}
