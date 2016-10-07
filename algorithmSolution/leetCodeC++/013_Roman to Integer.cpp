/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Roman to Integer
 *					: https://leetcode.com/problems/roman-to-integer/
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		int table[26] = {0}, sSize = s.size(), ans = 0, preValue = 1001;
		table['I' - 'A'] = 1;
		table['V' - 'A'] = 5;
		table['X' - 'A'] = 10;
		table['L' - 'A'] = 50;
		table['C' - 'A'] = 100;
		table['D' - 'A'] = 500;
		table['M' - 'A'] = 1000;
		for(int i = 0; i < sSize; ++i) {
			int curValue = table[s[i] - 'A'];
			if(curValue > preValue) {
				ans += (curValue - (preValue << 1));
			} else {
				ans += curValue;
			}
			preValue = curValue;
		}
		return ans;
	}
};