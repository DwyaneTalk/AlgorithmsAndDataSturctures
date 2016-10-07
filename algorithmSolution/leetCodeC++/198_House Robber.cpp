/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: House Robber
 *					: https://leetcode.com/problems/house-robber/
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
	int rob(vector<int>& nums) {
		int numSize = nums.size(), ans = 0, pre1 = 0, pre2 = 0;
		for(int i = 0; i < numSize; ++i) {
			ans = max(pre1, pre2 + nums[i]);
			pre2 = pre1;
			pre1 = ans;
		}
		return ans;
	}
};