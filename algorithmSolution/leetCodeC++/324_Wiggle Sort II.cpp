/*   DwyaneTalk@gmail.co_m
 *   by lutao
 *   leetCodeC++	: Wiggle Sort II
 *					: https://leetcode.com/problems/wiggle-sort-ii/
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
#define INDEX(n) (((n) * 2 + 1) % (nSize | 1))
	void wiggleSort(vector<int>& nums) {
		int nSize = nums.size();
		nth_element(nums.begin(), nums.begin() + nSize / 2, nums.end());
		int median = nums[nSize / 2];
		int lo = 0, hi = nSize - 1, idx = 0;
		while(idx <= hi) {
			if(nums[INDEX(idx)] > median) {
				if(idx != lo)	swap(nums[INDEX(idx)], nums[INDEX(lo)]);
				++lo;	++idx;
			} else if(nums[INDEX(idx)] < median) {
				swap(nums[INDEX(idx)], nums[INDEX(hi)]);
				--hi;
			} else {
				++idx;
			}
		}
	}
};