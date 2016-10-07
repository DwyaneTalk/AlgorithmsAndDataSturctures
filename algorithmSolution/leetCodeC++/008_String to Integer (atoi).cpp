/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: String to Integer (atoi)
 *					: https://leetcode.com/problems/string-to-integer-atoi/
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int sign = 1, ans = 0, strSize = str.size(), i = 0;
		while(i < strSize && str[i] == ' ') ++i;
		if(i == strSize)	return 0;
		if(str[i] == '-' || str[i] == '+') {
			sign = (str[i] == '-' ? -1 : 1);
			++i;
		}	
		while(i < strSize) {
			if(str[i] < '0' || str[i] > '9')	break;
			int newAns = ans * 10 + (str[i] - '0') * sign;
			if(newAns / 10 != ans)	return sign > 0 ? INT_MAX : INT_MIN;
			ans = newAns;
			++i;
		}
		return ans;
	}
};