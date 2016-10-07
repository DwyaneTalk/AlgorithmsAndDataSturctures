/*   DwyaneTalk@gmail.co_m
 *   by lutao
 *   leetCodeC++	: Bitwise AND of Numbers Range
 *					: https://leetcode.com/problems/bitwise-and-of-numbers-range/
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
	int rangeBitwiseAnd(int m, int n) {
		int ans = 0, mask = 1 << 30;
		while (mask && !((m & mask) ^ (n & mask))) {
			if(m & mask)	ans |= mask;
			mask >>= 1;
		}
		return ans;
	}
};