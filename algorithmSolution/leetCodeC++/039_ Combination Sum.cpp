/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Combination Sum
 *					: https://leetcode.com/problems/combination-sum/
*/
#include <iostream>
#include <algorithm>
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
	void backTracking(set<vector<int>>& finalAns, vector<int>& path, vector<int>& candidates, int idx, int target) {
		if(target == 0)	{
			finalAns.insert(path);
			return;
		}
		if(idx < candidates.size() && candidates[idx] <= target) {
			backTracking(finalAns, path, candidates, idx + 1, target);
			path.push_back(candidates[idx]);
			backTracking(finalAns, path, candidates, idx, target - candidates[idx]);
			path.pop_back();
		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		set<vector<int>> finalAns;
		vector<int> path;
		sort(candidates.begin(), candidates.end());
		backTracking(finalAns, path, candidates, 0, target);
		return vector<vector<int>>(finalAns.begin(), finalAns.end());
	}
};