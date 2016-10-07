/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Best Time to Buy and Sell Stock with Cooldown
 *					: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
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
	int maxProfit(vector<int>& prices) {
		int priceSize = prices.size();
		if(priceSize < 2)	return 0; 
		if(rand() % 2) {
			vector<int> DP_s0(priceSize), DP_s1(priceSize), DP_s2(priceSize);
			DP_s0[0] = 0;
			DP_s1[0] = -prices[0];
			DP_s2[0] = 0;
			for(int i = 1; i < priceSize; ++i) {
				DP_s0[i] = max(DP_s0[i - 1], DP_s2[i - 1]);
				DP_s1[i] = max(DP_s0[i - 1] - prices[i], DP_s1[i - 1]);
				DP_s2[i] = DP_s1[i - 1] + prices[i];
			}
			return max(DP_s0[priceSize - 1], DP_s2[priceSize - 1]);
		} else {
			int s0 = 0, s1 = -prices[0], s2 = 0;
			for(int i = 1; i < priceSize; ++i) {
				int tmp = s2;
				s2 = s1 + prices[i];
				s1 = max(s0 - prices[i], s1);
				s0 = max(s0, tmp);
			}
			return max(s0, s2);
		}
	}
};