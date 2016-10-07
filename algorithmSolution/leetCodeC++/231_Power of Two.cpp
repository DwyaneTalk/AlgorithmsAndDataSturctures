/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Power of Two
 *					: https://leetcode.com/problems/power-of-two/
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
	bool isPowerOfTwo(int n) {
		return (n > 0) && ((n & (n - 1)) == 0);
	}
};