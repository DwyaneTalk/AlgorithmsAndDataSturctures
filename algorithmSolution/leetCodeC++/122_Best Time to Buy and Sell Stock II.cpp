/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Best Time to Buy and Sell Stock
 *					: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
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
		int priceSize = prices.size(), ans = 0;
		for (int i = 1; i < priceSize; ++i) {
			ans += (prices[i] > prices[i - 1] ? prices[i] - prices[i - 1] : 0);
		}
		return ans;
	}
};