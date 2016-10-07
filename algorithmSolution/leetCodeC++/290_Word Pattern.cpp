/*   DwyaneTalk@gmail.co_m
 *   by lutao
 *   leetCodeC++	: Word Pattern
 *					: https://leetcode.com/problems/word-pattern/
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
	bool wordPattern(string pattern, string str) {
		stringstream sstr(str);
		string istr;
		int pSize = pattern.size(), is = 0;
		unordered_map<char, int>	pMap;
		unordered_map<string, int>sMap;	
		while(!sstr.eof() && is < pSize) {
			sstr >> istr;
			if(pMap[pattern[is]] != sMap[istr])	return false;
			pMap[pattern[is]] = sMap[istr] = is + 1;
			is++;
		}
		if(!sstr.eof() || is < pSize)	return false;
		return true;
	}
};