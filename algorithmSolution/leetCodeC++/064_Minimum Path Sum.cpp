/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Minimum Path Sum
 *					: https://leetcode.com/problems/minimum-path-sum/
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
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size(), n = (m > 0 ? grid[0].size() : 0);
		if(m <= 0 || n <= 0)	return 0;
		vector<int> dp(n, 0);
		dp[0] = grid[0][0];
		for(int i = 1; i < n; ++i) {
			dp[i] = dp[i - 1] + grid[0][i];
		}
		for(int i = 1; i < m; ++i) {
			dp[0] += grid[i][0];
			for(int j = 1; j < n; ++j) {
				dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
			}
		}
		return dp[n - 1];
	}
};