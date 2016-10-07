/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Combination Sum II
 *					: https://leetcode.com/problems/combination-sum-ii/
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
	void backTracking(set<vector<int>>& finalAns, vector<int>& path, vector<int>& candidates, int idx, int target, vector<int>& sum) {
		if(target == 0)	{
			finalAns.insert(path);
			return;
		}
		if(idx < candidates.size() && candidates[idx] <= target && sum[idx] >= target) {
			backTracking(finalAns, path, candidates, idx + 1, target, sum);
			path.push_back(candidates[idx]);
			backTracking(finalAns, path, candidates, idx + 1, target - candidates[idx], sum);
			path.pop_back();
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		int size = candidates.size();
		set<vector<int>> finalAns;
		vector<int> path, sum(size, 0);
		sort(candidates.begin(), candidates.end());
		sum[size - 1] = candidates[size - 1];
		for(int i = size - 2; i >= 0; --i)	sum[i] = sum[i + 1] + candidates[i];
		backTracking(finalAns, path, candidates, 0, target, sum);
		return vector<vector<int>>(finalAns.begin(), finalAns.end());
	}
};