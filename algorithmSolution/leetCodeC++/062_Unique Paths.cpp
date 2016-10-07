/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Unique Paths
 *					: https://leetcode.com/problems/unique-paths/
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <hash_set>
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		if(m <= 0 || n <= 0)	return 0;
		vector<vector<int>> dp(m, vector<int>(n, 1));
		for(int i = 1; i < m; ++i) {
			for(int j = 1; j < n; ++j) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[m - 1][n - 1];
	}
	int uniquePaths2(int m, int n) {
		if(m <= 0 || n <= 0)	return 0;
		if(m < n) {
			m = m ^ n;
			n = m ^ n;
			m = m ^ n;
		}
		vector<int> dp(n, 1);
		for(int i = 1; i < m; ++i) {
			for(int j = 1; j < n; ++j) {
				dp[j] = dp[j] + dp[j - 1];
			}
		}
		return dp[n - 1];
	}
};