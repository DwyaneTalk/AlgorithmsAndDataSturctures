/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Evaluate Reverse Polish Notation
 *					: https://leetcode.com/problems/evaluate-reverse-polish-notation/
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
using namespace std;


class Solution {
public:
	int Str2Int(string& str) {
		int sSize = str.size(), intNum = 0, i = 0, sign = 1;
		if(str[0] == '+')	++i;
		else if(str[0] == '-') {
			++i;
			sign = -1;
		}
		for(; i < sSize; ++i)	intNum = intNum * 10 + str[i] - '0';
		return intNum * sign;
	}
	int evalRPN(vector<string>& tokens) {
		int digital1 = 0, digital2 = 0, tokenSize = tokens.size();
		stack<int> intStack;
		for(int i = 0; i < tokenSize; ++i) {
			if(tokens[i] == "+") {
				digital1 = intStack.top();
				intStack.pop();
				digital2 = intStack.top();
				intStack.pop();
				intStack.push(digital1 + digital2);
			} else if(tokens[i] == "-") {
				digital1 = intStack.top();
				intStack.pop();
				digital2 = intStack.top();
				intStack.pop();
				intStack.push(digital2 - digital1);
			} else if(tokens[i] == "*") {
				digital1 = intStack.top();
				intStack.pop();
				digital2 = intStack.top();
				intStack.pop();
				intStack.push(digital1 * digital2);
			} else if(tokens[i] == "/") {
				digital1 = intStack.top();
				intStack.pop();
				digital2 = intStack.top();
				intStack.pop();
				intStack.push(digital2 / digital1);
			} else {
				intStack.push(Str2Int(tokens[i]));
			}
		}
		return intStack.top();
	}
};