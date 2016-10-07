/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Valid Palindrome
 *					: https://leetcode.com/problems/valid-palindrome/
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

#define VALID(s)	(((s) <= '9' && (s) >= '0') || ((s) <= 'z' && (s) >= 'a') || ((s) <= 'Z' && (s) >= 'A'))

#define MATCH(a, b)	(((a) == (b)) || ((((a) >= 'a' && (a) <= 'z') || ((a) >= 'A' && (a) <= 'Z')) && (abs((a) - (b)) == 32)))

class Solution {
public:
	bool isPalindrome(string s) {
		int sSize = s.size(), lo = 0, hi = sSize - 1;
		while(lo < hi) {
			while(lo < hi && !VALID(s[lo]))	++lo;
			while(lo < hi && !VALID(s[hi]))	--hi;
			if(lo < hi && !MATCH(s[lo], s[hi]))	return false;
			++lo;
			--hi;
		}
		return true;
	}
};