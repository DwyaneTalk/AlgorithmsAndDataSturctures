/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Reverse Integer
 *					: https://leetcode.com/problems/reverse-integer/
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		int sign = (x >= 0 ? 1 : -1), ans = 0;
		if(x == INT_MIN || x == 0)	return 0;
		x = (x >= 0 ? x : -x);
		while(!(x % 10))	x = x / 10;
		while(x) {
			if(sign) {
				if(ans > (INT_MAX - x % 10) / 10)	return 0;
			}else {
				if(ans > -(INT_MIN + x % 10) / 10)	return 0;
			}
			ans = ans * 10 + (x % 10);
			x = x / 10;
		}
		ans *= sign;
		return ans;
	}

	int reverse_new(int x) {
		register int ans = 0;
		while(x) {
			int newAns = ans * 10 + x % 10;
			if(newAns / 10 != ans)	return 0;
			ans = newAns;
			x /= 10;
		}
		return ans;
	}
};