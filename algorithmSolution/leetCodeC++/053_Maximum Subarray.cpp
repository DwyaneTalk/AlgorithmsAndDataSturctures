/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Maximum Subarray
 *					: https://leetcode.com/problems/maximum-subarray/
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
	int maxSubArray(vector<int>& nums) {
		return maxSubArray_Divide_Conquer(nums, 0, nums.size() - 1);
		int numSize = nums.size();
		int ans = numSize > 0 ? nums[0] : 0, pre_max = ans;
		for(int i = 1; i < numSize; ++i) {
			pre_max = pre_max > 0 ? pre_max + nums[i] : nums[i];
			ans = ans > pre_max ? ans : pre_max;
		}
		return ans;
	}


	int maxSubArray_Divide_Conquer(vector<int>& nums, int lo, int hi) {
		if(lo == hi)	return nums[lo];
		int mid = lo + ((hi - lo) >> 1);
		int max_lsub = maxSubArray_Divide_Conquer(nums, lo, mid);
		int max_rsub = maxSubArray_Divide_Conquer(nums, mid + 1, hi);
		int max_l = nums[mid], max_r = nums[mid + 1], tmp = 0;
		for(int i = mid, tmp = 0; i >= lo; --i) {
			tmp += nums[i];
			max_l = max_l > tmp ? max_l : tmp;
		}
		for(int i = mid + 1, tmp = 0; i <= hi; ++i) {
			tmp += nums[i];
			max_r = max_r > tmp ? max_r : tmp;
		}
		return max(max(max_lsub, max_rsub), max_l + max_r);
	}
};