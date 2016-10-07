/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Sort Colors
 *					: https://leetcode.com/problems/sort-colors/
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
	void sortColors(vector<int>& nums) {
		int numSize = nums.size(), lo = 0, hi = numSize - 1;
		while(lo < hi) {
			while(lo < hi && nums[lo] == 0)	++lo;
			while(lo < hi && nums[hi] != 0) --hi;
			if(lo < hi) {
				nums[lo] = nums[lo] ^ nums[hi];
				nums[hi] = nums[lo] ^ nums[hi];
				nums[lo] = nums[lo] ^ nums[hi];
				++lo;
				--hi;
			}
		}
		lo = 0;
		hi = numSize - 1;
		while(lo < hi) {
			while(lo < hi && nums[lo] != 2)	++lo;
			while(lo < hi && nums[hi] == 2) --hi;
			if(lo < hi) {
				nums[lo] = nums[lo] ^ nums[hi];
				nums[hi] = nums[lo] ^ nums[hi];
				nums[lo] = nums[lo] ^ nums[hi];
				++lo;
				--hi;
			}
		}
	}
};