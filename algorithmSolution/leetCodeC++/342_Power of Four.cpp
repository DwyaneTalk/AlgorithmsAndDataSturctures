/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Power of Four
 *					: https://leetcode.com/problems/power-of-four/
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
	bool isPowerOfFour(int num) {
		//return (num > 0) && ((num & (num - 1)) == 0) && ((num & 0X55555555) != 0);
		return (num > 0) && ((num & (num - 1)) == 0) && (((num - 1) % 3) == 0);
	}
};