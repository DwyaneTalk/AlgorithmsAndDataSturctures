/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Number of 1 Bits
 *					: https://leetcode.com/problems/number-of-1-bits/
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

class Solution {
public:
	int hammingWeight(unsigned int n) {
		int ans = 0;
		while(n) {
			++ans;
			n &= (n - 1);
		}
		return ans;
	}
};