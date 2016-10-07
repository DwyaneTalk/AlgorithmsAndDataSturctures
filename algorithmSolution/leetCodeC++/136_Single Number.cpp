/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Single Number
 *					: https://leetcode.com/problems/single-number/
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
	int singleNumber(vector<int>& nums) {
		int ans = nums[0], size = nums.size();
		for(int i = 1; i < size; ++i)   ans ^= nums[i];
		return ans;
	}
};