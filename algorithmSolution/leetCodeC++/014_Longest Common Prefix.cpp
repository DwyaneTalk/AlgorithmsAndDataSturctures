/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Longest Common Prefix
 *					: https://leetcode.com/problems/longest-common-prefix/
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int minSize = INT_MAX, vecSize = strs.size();
		string ans;
		if(vecSize == 0)	return "";
		for(int i = 0; i < vecSize; ++i)	minSize = min(minSize, int(strs[i].size()));
		for(int i = 0, j; i < minSize; ++i) {
			char ch = strs[0][i];
			for(j = 1; j < vecSize; ++j) {
				if(strs[j][i] != ch)	break;
			}
			if(j == vecSize)	ans += ch;
			else	break;
		}
		return ans;
	}
};