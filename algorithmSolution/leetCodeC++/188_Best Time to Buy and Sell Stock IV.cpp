/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Best Time to Buy and Sell Stock IV
 *					: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
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
	int maxProfit(int k, vector<int>& prices) {
		int priceSize = prices.size();
		if(priceSize < 2)	return 0;
		if((priceSize >> 1) <= k)	return fastMaxProfit(prices);
		if(rand() % 2) {
			vector<int> DP(priceSize + 1, 0);
			int tmp_max = INT_MIN, tmp_pre1 = 0, tmp_pre2 = 0;
			for(int i = 1; i <= k; ++i) {
				tmp_max = -prices[0];
				tmp_pre1 = DP[1];
				tmp_pre2 = DP[0];
				for(int j = 1; j < priceSize; ++j) {
					DP[j] = max(DP[j - 1], tmp_max + prices[j]);
					tmp_max = max(tmp_max, tmp_pre2 - prices[j]);
					tmp_pre2 = tmp_pre1;
					tmp_pre1 = DP[j + 1];
				}
			}
			return DP[priceSize - 1];
		} else {
			vector<vector<int>> DP(k + 1, vector<int>(priceSize, 0));
			int tmp_max = INT_MIN;
			for(int i = 1; i <= k; ++i) {
				tmp_max = -prices[0];
				for(int j = 1; j < priceSize; ++j) {
					DP[i][j] = max(DP[i][j - 1], prices[j] + tmp_max);
					tmp_max = max(tmp_max, DP[i - 1][j - 1] - prices[j]);
				}
			}
			return DP[k][priceSize - 1];
		}
	}

	int fastMaxProfit(vector<int>& prices) {
		int ans = 0, priceSize = prices.size();
		for(int i = 1; i < priceSize; ++i) {
			if(prices[i] > prices[i - 1])	ans += prices[i] - prices[i - 1];
		}
		return ans;
	}
};