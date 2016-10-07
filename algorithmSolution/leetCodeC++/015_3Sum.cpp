/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: 3Sum
 *					: https://leetcode.com/problems/3sum/
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int size = nums.size();
		if(size < 3)	return vector<vector<int>>();
		vector<vector<int>> ans;
		vector<int> ansItem;
		sort(nums.begin(), nums.end());
		for(int i = 0; i < size; ++i) {
			if(i > 0 && nums[i] == nums[i - 1])	continue;
			int lo = i + 1, hi = size - 1;
			static int sum = 0;
			while(lo < hi) {
				sum = nums[i] + nums[lo] + nums[hi];
				if(sum == 0) {
					ansItem.push_back(nums[i]);
					ansItem.push_back(nums[lo]);
					ansItem.push_back(nums[hi]);
					ans.push_back(ansItem);
					ansItem.clear();
					++lo;
					--hi;
					while(lo < hi && nums[lo] == nums[lo - 1])	++lo;
					while(lo < hi && nums[hi] == nums[hi + 1])	--hi;
				} else if(sum < 0) {
					++lo;
				} else {
					--hi;
				}
			}	
		}
		return ans;
	}
};
