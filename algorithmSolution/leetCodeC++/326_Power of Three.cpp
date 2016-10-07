/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Power of Three
 *					: https://leetcode.com/problems/power-of-three/
*/
#include <iostream>
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

typedef unsigned int uint32_t;

class Solution {
public:
	bool isPowerOfThree(int n) {
		const static int maxPowerOfThree = pow(double(3), int(log10((double)INT_MAX) / log10(3.0f)));
		return n > 0 && n <= maxPowerOfThree && maxPowerOfThree % n == 0;
	}
};