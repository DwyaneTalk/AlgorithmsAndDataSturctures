/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Palindrome Partitioning
 *					: https://leetcode.com/problems/palindrome-partitioning/
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
#include <unordered_set>
using namespace std;

class Solution {
public:
	void backTracking(vector<vector<string>>& ans, vector<vector<bool>>& pMap, vector<string>& path, string s, int idx) {
		int sSize = s.size();
		if(idx == sSize) {
			ans.push_back(path);
		} else {
			for(int i = idx; i < sSize; ++i) {
				if(pMap[idx][i]) {
					path.push_back(s.substr(idx, i - idx + 1));
					backTracking(ans, pMap, path, s, i + 1);
					path.pop_back();
				}
			}
		}
	}

	vector<vector<string>> partition(string s) {
		int sSize = s.size();
		vector<vector<string>> ans;
		if(sSize > 0) {
			vector<vector<bool>> pMap(sSize, vector<bool>(sSize, false));
			for(int i = 0; i < sSize; ++i)		pMap[i][i]		= true;
			for(int l = 1; l < sSize; ++l) {
				for(int i = 0; i < sSize - l; ++i) {
					pMap[i][i + l] = (s[i] == s[i + l]) && (l >= 2 ? pMap[i + 1][i + l - 1] : true);
				}
			}
			vector<string> path;
			backTracking(ans, pMap, path, s, 0);
		}
		return ans;
	}
};