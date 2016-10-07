/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Remove Invalid Parentheses
 *					: https://leetcode.com/problems/remove-invalid-parentheses/
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
	void backTracking_DFS(set<string>& finalAns, string path, string& s, int idx, int nL, int nR, int nToMatch) {
		if(idx == s.size()) {
			if(nL == 0 && nR ==0 && nToMatch == 0)
				finalAns.insert(path);
		} else if(s[idx] != '(' && s[idx] != ')') {
			backTracking_DFS(finalAns, path + s[idx], s, idx + 1, nL, nR, nToMatch);
		} else if(s[idx] == '('){
			if(nL > 0)	backTracking_DFS(finalAns, path, s, idx + 1, nL - 1, nR, nToMatch);
			backTracking_DFS(finalAns, path + '(', s, idx + 1, nL, nR, nToMatch + 1);
		} else {
			if(nR > 0)	backTracking_DFS(finalAns, path, s, idx + 1, nL, nR - 1, nToMatch);
			if(nToMatch > 0)	backTracking_DFS(finalAns, path + ')', s, idx + 1, nL, nR, nToMatch - 1);
		}
	}

	vector<string> removeInvalidParentheses(string s) {
		int sSize = s.size(), nL = 0, nR = 0;
		set<string> finalAns;
		string path = "";
		for(int i = 0; i < sSize; ++i) {
			if(s[i] == '(')	++nL;
			else if(s[i] == ')') {
				if(nL > 0)	--nL;
				else		++nR;
			}
		}
		backTracking_DFS(finalAns, path, s, 0, nL, nR, 0);
		return vector<string>(finalAns.begin(), finalAns.end());
	}
};