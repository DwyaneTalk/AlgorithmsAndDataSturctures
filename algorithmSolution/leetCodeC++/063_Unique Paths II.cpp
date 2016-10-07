/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Unique Paths II
 *					: https://leetcode.com/problems/unique-paths-ii/
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
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size(), n = (m > 0 ? obstacleGrid[0].size() : 0);
		if(m <= 0 || n <= 0)	return 0;
		vector<int> dp(n, 0);
		dp[0] = (obstacleGrid[0][0] == 1 ? 0 : 1);
		for(int i = 1; i < n; ++i) {
			if(obstacleGrid[0][i] == 1)	dp[i] = 0;
			else						dp[i] = dp[i - 1];
		}
		for(int i = 1; i < m; ++i) {
			if(obstacleGrid[i][0] == 1)	dp[0] = 0;
			for(int j = 1; j < n; ++j) {
				if(obstacleGrid[i][j] == 1)	dp[j] = 0;
				else						dp[j] += dp[j - 1];
			}
		}
		return dp[n - 1];
	}
};