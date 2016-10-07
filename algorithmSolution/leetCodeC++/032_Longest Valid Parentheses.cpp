/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Longest Valid Parentheses
 *					: https://leetcode.com/problems/longest-valid-parentheses/
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
	int longestValidParentheses(string s) {
		int sSize = s.size(), ans = 0;
		vector<int> maxSize(sSize + 1);
		maxSize[0] = maxSize[1] = 0;
		for(int i = 1; i < sSize; ++i) {
			if(s[i] == '(')	maxSize[i + 1] = 0;
			else {
				if(i >= 1 + maxSize[i] && s[i - 1 - maxSize[i]] == '(') {
					maxSize[i + 1] = maxSize[i] + 2 + maxSize[i - maxSize[i] - 1];
				} else {
					maxSize[i + 1] = 0;
				}
			}
		}
		for(int i = 0; i <= sSize; ++i)	ans = max(ans, maxSize[i]);
		return ans;
	}
	int longestValidParentheses_stack(string s) {
		int sSize = s.size(), ans = 0;
		stack<int> idxStack;
		idxStack.push(-1);
		for(int i = 0; i < sSize; ++i) {
			if(s[i] == '(' || idxStack.top() == -1 || s[idxStack.top()] != '(')	idxStack.push(i);
			else {
				idxStack.pop();
				ans = max(ans, i - idxStack.top());
			}
		}
		return ans;
	}
};