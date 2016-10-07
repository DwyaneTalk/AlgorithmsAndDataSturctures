/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: 4Sum
 *					: https://leetcode.com/problems/4sum/
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		int numSize = nums.size();
		if(numSize < 4)	return vector<vector<int>>();
		vector<vector<int>> ans;
		vector<int> ansItem;
		sort(nums.begin(), nums.end());
		for(int i = 0; i < numSize; ++i) {
			if(i > 0 && nums[i] == nums[i - 1])	continue;
			for(int j = i + 1; j <numSize; ++j) {
				if(j > i + 1 && nums[j] == nums[j - 1])	continue;
				int lo = j + 1, hi = numSize - 1, twoTarget = target - nums[i] - nums[j];
				while(lo < hi) {
					if(nums[lo] + nums[hi] < twoTarget) {
						++lo;
					} else if(nums[lo] + nums[hi] > twoTarget) {
						--hi;
					} else {
						ansItem.push_back(nums[i]);
						ansItem.push_back(nums[j]);
						ansItem.push_back(nums[lo++]);
						ansItem.push_back(nums[hi--]);
						ans.push_back(ansItem);
						ansItem.clear();
						while(lo < hi && nums[lo] == nums[lo - 1])	++lo;
						while(lo < hi && nums[hi] == nums[hi + 1])	--hi;
					}
				}
			}
		}
		return ans;
	}
};
