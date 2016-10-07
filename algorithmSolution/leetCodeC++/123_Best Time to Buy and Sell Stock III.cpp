/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Best Time to Buy and Sell Stock III
 *					: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
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
		int priceSize = prices.size(), price_tmp, ans = 0;
		if(priceSize < 2)	return 0;
		vector<int> profit_l(priceSize,0), profit_r(priceSize, 0);
		for(int i = 1, price_tmp = prices[0]; i < priceSize; ++i) {
			profit_l[i] = max(profit_l[i - 1], prices[i] - price_tmp);
			price_tmp = min(price_tmp, prices[i]);
		}
		for(int i = priceSize - 2, price_tmp = prices[priceSize - 1]; i >= 0; --i) {
			profit_r[i] = max(profit_r[i + 1], price_tmp - prices[i]);
			price_tmp = max(price_tmp, prices[i]);
		}
		for(int i = 0; i < priceSize; ++i) {
			ans = max(ans, profit_l[i] + profit_r[i]);
		}
		return ans;
	}
};