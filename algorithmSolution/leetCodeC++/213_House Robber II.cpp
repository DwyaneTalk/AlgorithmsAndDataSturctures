/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Trapping Rain Water
 *					: https://leetcode.com/problems/house-robber-ii/
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
	int rob(vector<int>& nums) {
		int numSize = nums.size();
		if(numSize == 1)	return nums[0];
		return max(rob_range(nums, 0, numSize - 2), rob_range(nums, 1, numSize - 1));
	}

	int rob_range(vector<int>& num, int lo, int hi) {
		int ans = 0, pre1 = 0, pre2 = 0;
		for(; lo <= hi; ++lo) {
			ans = max(pre1, pre2 + num[lo]);
			pre2 = pre1;
			pre1 = ans;
		}
		return ans;
	}
};