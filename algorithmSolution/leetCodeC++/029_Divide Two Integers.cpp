/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Implement strStr()
 *					: https://leetcode.com/problems/divide-two-integers/
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;


class Solution {
public:
	int divide(int dividend, int divisor) {
		int sign = 1, ans = 0;
		if(divisor == 0)	return INT_MAX;
		if(dividend == INT_MIN && divisor == -1)	return INT_MAX;
		if(dividend == INT_MIN && divisor ==  1)	return INT_MIN;
		if(dividend < 0) {
			if(divisor > 0)	sign = -1;
			else if(divisor == INT_MIN) {
				return dividend == INT_MIN ? 1 : 0;
			} else {
				divisor = -divisor;
			}
			if(dividend == INT_MIN) {
				dividend = -(dividend + divisor);
				ans = 1;
			} else {
				dividend = -dividend;
			}
		} else {
			if(divisor == INT_MIN)	return 0;
			if(divisor < 0){
				sign = -1;
				divisor = -divisor;
			}
		}
		int douVal, newVal, tmpAns = 1;;
		while(dividend >= divisor) {
			douVal = divisor;
			tmpAns = 1;
			while(douVal <= dividend) {
				newVal = douVal << 1;
				if(newVal < douVal)	break;
				douVal = newVal;
				tmpAns <<= 1;
			}
			if(douVal > dividend) {
				douVal >>= 1;
				tmpAns >>= 1;
			}
			dividend -= douVal;
			ans += tmpAns;
		}
		return sign * ans;
	}
};