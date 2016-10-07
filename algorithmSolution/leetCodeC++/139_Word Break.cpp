/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Word Break
 *					: https://leetcode.com/problems/word-break/
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
using namespace std;

class Solution {
public:
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		int sSize = s.size(), dictSize = wordDict.size(), count = 0;
		vector<bool> subAns(sSize + 1, false);
		vector<int> wordSize(wordDict.size());
		subAns[0] = true;
		for(unordered_set<string>::iterator itr = wordDict.begin(); itr != wordDict.end(); ++itr) {
			wordSize[count++] = itr->size();
		}
		for(int i = 0; i < sSize; ++i) {
			if(subAns[i] == false)	continue;
			count = 0;
			for(unordered_set<string>::iterator itr = wordDict.begin(); itr != wordDict.end(); ++itr, ++count) {
				if(s.substr(i, wordSize[count]) == *itr) {
					subAns[i + wordSize[count]] = true;
				}
			}
		}
		return subAns[sSize];
	}
};