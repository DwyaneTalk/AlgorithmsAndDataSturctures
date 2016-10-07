/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Generate Parentheses
 *					: https://leetcode.com/problems/generate-parentheses/
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <map>
using namespace std;


class Solution {
public:
	void backTracing(vector<string>& finalAns, string path, int left, int right) {
		if(left == 0 && right == 0) {
			finalAns.push_back(path);
		} else {
			if(left > 0)	backTracing(finalAns, path + '(', left - 1, right + 1);
			if(right > 0)	backTracing(finalAns, path + ')', left, right - 1);
		}
	}

	vector<string> generateParenthesis(int n) {
		vector<string> finalAns;
		string path = "";
		backTracing(finalAns, path, n, 0);
		return finalAns;
	}
};
