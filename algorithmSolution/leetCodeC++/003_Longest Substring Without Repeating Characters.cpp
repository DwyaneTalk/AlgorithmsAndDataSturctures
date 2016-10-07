/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Longest Substring Without Repeating Characters
 *					: https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if(rand() % 2)	return lengthOfLongestSubstring_DP(s);
		else			return lengthOfLongestSubstring_Dict(s);
	}
	int lengthOfLongestSubstring_DP(string s) {
		int strSize = s.size(), ansLen = 0, pStart = 0;
		for(int i = 0, j; i < strSize; ++i) {
			for(j  = pStart; j < i; ++j) {
				if(s[j] == s[i])	break;
			}
			if(j != i)	pStart = j + 1;
			ansLen = ansLen > (i - pStart + 1) ? ansLen : (i  - pStart + 1);
		}
		return ansLen;
	}
	int lengthOfLongestSubstring_Dict(string s) {
		int strSize = s.size(), ansLen = 0, pStart = 0;
		vector<int> dict(256, -1);
		for(int i = 0; i < strSize; ++i) {
			if(dict[s[i]] >= pStart)	pStart = dict[s[i]] + 1;
			dict[s[i]] = i;
			ansLen = ansLen > (i - pStart + 1) ? ansLen : (i - pStart + 1);
		}
		return ansLen;
	}
};