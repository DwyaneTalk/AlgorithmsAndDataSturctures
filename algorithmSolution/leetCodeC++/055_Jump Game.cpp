/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Jump Game
 *					: https://leetcode.com/problems/jump-game/
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

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int numSize = nums.size(), range = 0;
		for(int i = 0; i < numSize - 1 && i <= range; ++i) {
			range = max(range, i + nums[i]);
		}
		return range >= numSize - 1;
	}
};