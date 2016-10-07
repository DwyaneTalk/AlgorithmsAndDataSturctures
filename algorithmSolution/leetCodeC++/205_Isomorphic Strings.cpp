/*   DwyaneTalk@gmail.co_m
 *   by lutao
 *   leetCodeC++	: Isomorphic Strings
 *					: https://leetcode.com/problems/isomorphic-strings/
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
#include <unordered_map>
#include <time.h>
using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		int sSize = s.size(), tSize = t.size();
		if(sSize != tSize)	return false;
		map<char, char>	charMap1, charMap2;
		for(int i = 0; i < sSize; ++i) {
			if(charMap1[s[i]]) {
				if(charMap1[s[i]] != t[i])	return false;
			} else {
				charMap1[s[i]] = t[i];
			}
			if(charMap2[t[i]]) {
				if(charMap2[t[i]] != s[i])	return false;
			} else {
				charMap2[t[i]] = s[i];
			}
		}
		return true;
	}
	bool isIsomorphic2(string s, string t) {
		int idx1[256] = {0}, idx2[256] = {0};
		int sSize = s.size(), tSize = t.size();
		if(sSize != tSize)	return false;
		for(int i = 0; i < sSize; ++i) {
			if(idx1[s[i]] != idx2[t[i]])	return false;
			idx1[s[i]] = idx2[t[i]] = i + 1;
		}
		return true;
	}
};