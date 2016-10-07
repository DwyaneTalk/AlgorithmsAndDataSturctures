/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Valid Parentheses
 *					: https://leetcode.com/problems/valid-parentheses/
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
	bool isValid(string s) {
		stack<char> charStack;
		int sSize = s.size(), stackSize = 0;
		for(int i = 0; i < sSize; ++i) {
			stackSize = charStack.size();
			if(sSize - i < stackSize)	return false;
			if(s[i] == '{' || s[i] == '(' || s[i] == '[') {
				charStack.push(s[i]);
			} else {
				if(charStack.empty())	return false;
				char topChar = charStack.top();
				if((topChar == '{' && s[i] == '}') || (topChar == '[' && s[i] == ']') || (topChar == '(' && s[i] == ')')) {
					charStack.pop();
				} else {
					return false;
				}
			}
		}
		return charStack.empty();
	}
};