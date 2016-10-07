/*   DwyaneTalk@gmail.co_m
 *   by lutao
 *   leetCodeC++	: Combination Sum III
 *					: https://leetcode.com/problems/combination-sum-iii/
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
#include <unordered_set>
#include <unordered_map>
#include <time.h>
using namespace std;

class Solution {
private:
	vector<vector<int>>	ans;
public:
	void backTracking(vector<int>& path, int i, int k, int n) {
		if(k == 0 || n == 0 || i == 9) {
			if(k == 0 && n == 0)	ans.push_back(path);
		} else {
			if((9 - i - 1 >= k) && ((19 - k) * k >= n * 2))
				backTracking(path, i + 1, k, n);
			path.push_back(i + 1);
			backTracking(path, i + 1, k - 1, n - i - 1);
			path.pop_back();
		}
	}

	vector<vector<int>> combinationSum3(int k, int n) {
		vector<int> path;
		backTracking(path, 0, k, n);
		return ans;
	}
};