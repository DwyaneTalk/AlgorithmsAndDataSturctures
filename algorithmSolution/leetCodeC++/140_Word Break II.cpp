/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Word Break II
 *					: https://leetcode.com/problems/word-break-ii/
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
#include <hash_map>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
	unordered_map<string, vector<string>> subAns;

	void backTracking(string s, unordered_set<string>& wordDict) {
		if(s != "" && !subAns.count(s)) {
			if(wordDict.count(s))	subAns[s].push_back(s);
			int sSize = s.size();
			for(int i = 0; i < sSize; ++i) {
				string word = s.substr(0, i + 1);
				if(wordDict.find(word) != wordDict.end()) {
					string leftWord = s.substr(i + 1, sSize - i - 1);
					backTracking(leftWord, wordDict);
					for(int j = 0; j < subAns[leftWord].size(); ++j) {
						subAns[s].push_back(word + " " + subAns[leftWord][j]);
					}
				}
			}
		}
	}



	vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		backTracking(s, wordDict);
		return subAns[s];
	}
};