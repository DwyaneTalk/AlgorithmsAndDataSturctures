/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: 3Sum Closest
 *					: https://leetcode.com/problems/3sum-closest/
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int numSize = nums.size();
		if(numSize < 3)	return 0;
		sort(nums.begin(), nums.end());
		int diffValue = INT_MAX, ans = 0;
		for(int i = 0; i < numSize - 2; ++i) {
			if(i > 0 && nums[i] == nums[i - 1])	continue;
			if(nums[i] + nums[i + 1] + nums[i + 2] - target > diffValue)	continue;
			if(nums[i] + nums[numSize - 2] + nums[numSize - 1] - target < -diffValue)	continue;
			int twoTarget = target - nums[i], lo = i + 1, hi = numSize - 1;
			while(lo < hi) {
				int sum = nums[lo] + nums[hi] - twoTarget;
				if(abs(sum) < diffValue) {
					diffValue = abs(sum);
					ans = sum + target;
					if(diffValue == 0)	return ans;
				}
				sum > 0 ? --hi : ++lo;
			}
		}
		return ans;
	}
};
