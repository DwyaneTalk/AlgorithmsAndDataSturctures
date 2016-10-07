/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Remove Element
 *					: https://leetcode.com/problems/remove-element/
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;


class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int lo = 0, hi = nums.size() - 1;
		while(lo <= hi) {
			while(lo <= hi && nums[lo] != val)	++lo;
			while(lo <= hi && nums[hi] == val)	--hi;
			if(lo <= hi)	{
				nums[lo] = nums[hi] ^ nums[lo];
				nums[hi] = nums[hi] ^ nums[lo];
				nums[lo] = nums[hi] ^ nums[lo];
				++lo;	--hi;
			}
		}
		return lo;
	}
};
