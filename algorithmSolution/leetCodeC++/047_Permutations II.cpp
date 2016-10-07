/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Permutations II
 *					: https://leetcode.com/problems/permutations-ii/
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;


class Solution {
public:
	void backTracking(vector<vector<int>>& finalAns, vector<int>& path, vector<int>& nums, vector<int>& visited) {
		if(path.size() == nums.size()) {
			finalAns.push_back(path);
		} else {
			int preVal = nums[0] - 1;
			for(int i = 0; i < nums.size(); ++i) {
				if(visited[i] == 0 && nums[i] != preVal) {
					preVal = nums[i];
					visited[i] = 1;
					path.push_back(nums[i]);
					backTracking(finalAns, path, nums, visited);
					path.pop_back();
					visited[i] = 0;
				}
			}
		}
	}

	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> finalAns;
		vector<int> path, visited(nums.size(), 0);
		sort(nums.begin(), nums.end());
		if(nums.empty() == false)	backTracking(finalAns, path, nums, visited);
		return finalAns;
	}
};