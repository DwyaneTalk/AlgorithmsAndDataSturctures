/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Subsets II
 *					: https://leetcode.com/problems/subsets-ii/
*/
#include <iostream>
#include <sstream>
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
	void backTracking(set<vector<int>>& ans, vector<int>& path, vector<int>& num, int idx) {
		int numSize = num.size();
		if(idx == numSize) {
			ans.insert(path);
		} else {
			backTracking(ans, path, num, idx + 1);
			path.push_back(num[idx]);
			backTracking(ans, path, num, idx + 1);
			path.pop_back();
		}
	}

	vector<vector<int>> subsetsWithDup_DP(vector<int>& nums) {
		vector<vector<int>> ans(1, vector<int>());
		int numSize = nums.size(), cnt = 0, ansSize = 0;
		for(int i = 0; i < numSize; i += cnt) {
			cnt = 1;
			while(i + cnt < numSize && nums[i + cnt] == nums[i])	++cnt;
			ansSize = ans.size();
			for(int j = 0; j < ansSize; ++j) {
				vector<int> tmp_ans = ans[j];
				for(int k = 0; k < cnt; ++k) {
					tmp_ans.push_back(nums[i]);
					ans.push_back(tmp_ans);
				}
			}
		}
		return ans;
	}
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		if(0) {
			set<vector<int>> ans;
			vector<int> path;
			backTracking(ans, path, nums, 0);
			return vector<vector<int>> (ans.begin(), ans.end());
		} else {
			return subsetsWithDup_DP(nums);
		}
	}
};