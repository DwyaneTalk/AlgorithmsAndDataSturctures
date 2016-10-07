/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Group Anagrams
 *					: https://leetcode.com/problems/anagrams/
*/
#include <iostream>
#include <algorithm>
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
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		int strNum = strs.size();
		vector<vector<string>> ans;
		map<string, int> strMap;
		map<string, int>::iterator findIter;
		string tmpStr;
		for(int i = 0; i < strNum; ++i) {
			tmpStr = strs[i];
			sort(tmpStr.begin(), tmpStr.end());
			findIter = strMap.find(tmpStr);
			if(findIter != strMap.end()) {
				ans[findIter->second].push_back(strs[i]);
			} else {
				ans.push_back(vector<string>(1, strs[i]));
				strMap[tmpStr] = ans.size() - 1;
			}
		}
		return ans;
	}
};