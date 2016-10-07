/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Integer to Roman
 *					: https://leetcode.com/problems/integer-to-roman/
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		char* table[4][10] = {
			{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
			{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
			{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
			{"", "M", "MM", "MMM"}
		};
		string ans;
		if(num < 4000 && num > 0) {
			ans += table[3][num / 1000];
			ans += table[2][num / 100 % 10];
			ans += table[1][num / 10 % 10];
			ans += table[0][num % 10];
		}
		return ans;
	}
};