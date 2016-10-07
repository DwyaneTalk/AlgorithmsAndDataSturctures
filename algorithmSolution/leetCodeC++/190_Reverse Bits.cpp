/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Reverse Bits
 *					: https://leetcode.com/problems/reverse-bits/
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <hash_set>
using namespace std;

typedef unsigned int uint32_t;

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t ans = 0, i = 0;
		while(i++ < 32) {
			ans = ans << 1;
			ans = ans | (n & 1);
			n	= n	  >> 1;	
		}
		return ans;
	}
	uint32_t reverseBits2(uint32_t n) {
		n = (n << 16) | (n >> 16);
		n = ((n & 0X00ff00ff) << 8) | ((n & 0Xff00ff00) >> 8);
		n = ((n & 0X0f0f0f0f) << 4) | ((n & 0Xf0f0f0f0) >> 4);
		n = ((n & 0X33333333) << 2) | ((n & 0XCCCCCCCC) >> 2);
		n = ((n & 0X55555555) << 1) | ((n & 0XAAAAAAAA) >> 1);
		return n;
	}
};