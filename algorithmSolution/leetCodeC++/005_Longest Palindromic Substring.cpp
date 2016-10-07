/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Longest Palindromic Substring
 *					: https://leetcode.com/problems/longest-palindromic-substring/
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int strSize = s.size(), lo = 0, hi = 0, ansLo = 0, ansHi = 0;
		for(int i = 0; i < strSize * 2 - 1; ++i) {
			if(i % 2)	hi = (lo = i / 2) + 1;
			else		hi = lo = i / 2;
			if(min(lo, strSize - 1 - hi) * 2 + hi - lo <= ansHi - ansLo)	continue;
			while(lo >= 0 && hi < strSize) {
				if(s[lo] == s[hi]) {
					--lo;
					++hi;
				} else	break;
			}
			if(hi - lo - 1 > ansHi - ansLo + 1) {
				ansLo = lo + 1;
				ansHi = hi - 1;
			}
		}
		return s.substr(ansLo, ansHi - ansLo + 1);
	}

	string longestPalindrome_fast(string s) {
		int strSize = s.size(), lo = 0, hi = 0, ansLo = 0, ansSize = 0;
		for(int i = 0; i < strSize && strSize - i > ansSize >> 1; ) {
			lo = hi = i;
			while(hi + 1 < strSize && s[hi + 1] == s[hi])	++hi;
			i = hi + 1;
			while(lo > 0 && hi < strSize - 1 && s[lo - 1] == s[hi + 1]) {
				--lo;
				++hi;
			}
			if(hi - lo + 1 > ansSize) {
				ansLo	= lo;
				ansSize = hi - lo + 1;
			}
		}
		return s.substr(ansLo, ansSize);
	}

	bool isPalindrome(string& s, int lo, int size) {
		int hi = lo + size - 1;
		while (lo < hi) {
			if(s[lo++] != s[hi--])	return false;
		}
		return true;
	}

	string longestPalindrome_DP(string s) {
		int strSize = s.size(), ansLo = 0, ansSize = 0;
		for(int i = 0; i < strSize; ++i) {
			if(i - ansSize > 0 && isPalindrome(s, i - ansSize - 1, ansSize + 2)) {
				ansLo = i - ansSize - 1;
				ansSize += 2;
			} else if(isPalindrome(s, i - ansSize, ansSize + 1)) {
				ansLo = i - ansSize;
				ansSize += 1;
			}
		}
		return s.substr(ansLo, ansSize);
	}
};