/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Simplify Path
 *					: https://leetcode.com/problems/simplify-path/
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
	string simplifyPath(string path) {
		stack<string> strStack;
		stringstream ss(path);
		string name, ans;
		while(getline(ss, name, '/')) {
			if(name == "" || name == ".")	continue;
			if(name == ".." && !strStack.empty())	strStack.pop();
			if(name != "..")	strStack.push(name);
		}
		while(!strStack.empty()) {
			name = strStack.top();
			strStack.pop();
			ans = "/" + name + ans;
		}
		return ans.empty() ? "/" : ans;
	}
};