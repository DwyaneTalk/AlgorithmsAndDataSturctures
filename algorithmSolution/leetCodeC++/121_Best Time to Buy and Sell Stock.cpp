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
		int priceSize = prices.size();
		if(0) {
			vector<int> nums(priceSize - 1, 0);
			for(int i = 0; i < priceSize - 1; ++i) {
				nums[i] = prices[i + 1] - prices[i];
			}
			return maxSubArray(nums);
		} else {
			int ans = 0, cur_min = prices[0];
			for (int i = 1; i < priceSize; ++i) {
				ans = max(ans, prices[i] - cur_min);
				cur_min = min(cur_min, prices[i]);
			}
			return ans;
		}
	}
	int maxSubArray(vector<int>& nums) {
		int numSize = nums.size();
		int ans = 0, pre_max = -1;
		for(int i = 0; i < numSize; ++i) {
			pre_max = pre_max > 0 ? pre_max + nums[i] : nums[i];
			ans = ans > pre_max ? ans : pre_max;
		}
		return ans;
	}
};