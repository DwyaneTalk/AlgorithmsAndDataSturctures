/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Decode Ways
 *					: https://leetcode.com/problems/decode-ways/
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

class Solution {
public:
	int numDecodings(string s) {
		int sSize = s.size(), ans_1 = 0, ans_2 = 1, ans = 0;
		if(sSize < 1)	return 0;
		int num_1 = s[0] - '0', num_2;
		if(num_1 >= 1 && num_1 <= 9)	ans_1 = 1;
		for(int i = 1; i < sSize; ++i) {
			num_1 = s[i] - '0';
			num_2 = (s[i - 1] - '0') * 10 + num_1;
			if(num_1 <= 9  && num_1 >= 1)	ans += ans_1;
			if(num_2 <= 26 && num_2 >= 1 && s[i - 1] != '0')	ans += ans_2;
			ans_2 = ans_1;
			ans_1 = ans;
			ans = 0;
		}
		return ans_1;
	}
};