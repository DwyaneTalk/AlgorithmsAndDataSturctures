/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Combinations
 *					: https://leetcode.com/problems/combinations/
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
	void backTracking(vector<vector<int>>& ans, vector<int>& path, int val, int n, int k) {
		int pathSize = path.size();
		if(pathSize == k) {
			ans.push_back(path);
		} else {
			path.push_back(val + 1);
			backTracking(ans, path, val + 1, n, k);
			path.pop_back();
			if(n - val + pathSize > k)	backTracking(ans, path, val + 1, n, k);
		}
	}
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> ans;
		vector<int> path;
		if(n < 1 || k < 1 || n < k)	return ans;
		backTracking(ans, path, 0, n, k);
		return ans;
	}
};