/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Subsets
 *					: https://leetcode.com/problems/subsets/
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
	vector<vector<int>> subsets(vector<int>& nums) {
		int numSize = nums.size();
		vector<vector<int>> ans;
		ans.push_back(vector<int>());
		for(int i = 0; i < numSize; ++i) {
			int ansSize = ans.size();
			for(int j = 0; j < ansSize; ++j) {
				ans[j].push_back(nums[i]);
				ans.push_back(ans[j]);
				ans[j].pop_back();
			}
		}
		return ans;
	}
};