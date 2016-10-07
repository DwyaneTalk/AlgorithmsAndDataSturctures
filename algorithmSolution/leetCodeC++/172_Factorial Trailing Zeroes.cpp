/*   DwyaneTalk@gmail.co_m
 *   by lutao
 *   leetCodeC++	: Factorial Trailing Zeroes
 *					: https://leetcode.com/problems/factorial-trailing-zeroes/
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
	int trailingZeroes(int n) {
		int ans = 0;
		while(n) {
			n = n / 5;
			ans += n;
		}
		return ans;
	}
};