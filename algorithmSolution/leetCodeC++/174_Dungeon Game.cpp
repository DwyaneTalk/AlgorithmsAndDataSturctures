/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Dungeon Game
 *					: https://leetcode.com/problems/dungeon-game/
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
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		return calculateMinimumHP_BS(dungeon);
	}
	int calculateMinimumHP_dp(vector<vector<int>>& dungeon) {
		int m = dungeon.size(), n = (m > 0 ? dungeon[0].size() : 0);
		if(m <= 0 || n <= 0)	return 0;
		vector<vector<int>> minHP(m, vector<int>(n, 0));
		minHP[m - 1][n - 1] = max(1, 1 - dungeon[m - 1][n - 1]);
		for(int i = m - 2; i >= 0; --i)	minHP[i][n - 1] = max(1, minHP[i + 1][n - 1] - dungeon[i][n - 1]);
		for(int i = n - 2; i >= 0; --i)	minHP[m - 1][i] = max(1, minHP[m - 1][i + 1] - dungeon[m - 1][i]);
		for(int i = m - 2; i >= 0; --i) {
			for(int j = n - 2; j >= 0; --j) {
				minHP[i][j] = max(1, min(minHP[i + 1][j], minHP[i][j + 1]) - dungeon[i][j]);
			}
		}
		return minHP[0][0];
	}
	int calculateMinimumHP_BS(vector<vector<int>>& dungeon) {
		int m = dungeon.size(), n = (m > 0 ? dungeon[0].size() : 0);
		if(m <= 0 || n <= 0)	return 0;
		int lo = 0, hi = 1, mid, dead;
		for(int i = 0; i < n; ++i)	if(dungeon[0][i] < 0)	hi -= dungeon[0][i];
		for(int i = 1; i < m; ++i)	if(dungeon[i][n - 1] < 0)	hi -= dungeon[i][n - 1];
		vector<int> dp(n + 1);
		while(lo < hi - 1) {
			mid = lo + ((hi - lo) >> 1);
			dp[0] = mid;
			dead = false;
			for(int i = 1; i <= n; ++i) {
				dp[i] = dp[i - 1] + dungeon[0][i - 1];
				if(dp[i] < 1){
					dp[i] = INT_MIN;
				}
			}
			for(int i = 2; i <= m; ++i) {
				dp[1] = dp[1] + dungeon[i - 1][0];
				if(dp[1] < 1) {
					dp[i] = INT_MIN;
				}
				for(int j = 2; j <= n; ++j) {
					dp[j] = max(dp[j], dp[j - 1]) + dungeon[i - 1][j - 1];
					if(dp[j] < 1) {
						dp[j] = INT_MIN;
					}
				}
			}
			if(dp[n] <= 0) {
				lo = mid;
			} else {
				hi = mid;
			}
		}
		return hi;
	}
};