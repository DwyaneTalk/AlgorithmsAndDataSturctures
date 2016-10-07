/*   DwyaneTalk@gmail.co_m
 *   by lutao
 *   leetCodeC++	: Excel Sheet Column Number
 *					: https://leetcode.com/problems/excel-sheet-column-number/
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
	int titleToNumber(string s) {
		int sSize = s.size(), ans = 0;
		for(int i = 0; i < sSize; ++i) {
			ans = ans * 26 + s[i] - 'A' + 1;
		}
		return ans;
	}
};