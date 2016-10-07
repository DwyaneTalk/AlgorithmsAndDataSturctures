/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Search for a Range
 *					: https://leetcode.com/problems/search-for-a-range/
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
	vector<int> searchRange(vector<int>& nums, int target) {
		int lo = 0, hi = nums.size() - 1, mid, newLo, newHi, newMid;
		while(lo <= hi) {
			mid = (lo + hi) >> 1;
			if(nums[mid] == target)	break;
			else if(nums[mid] < target)	lo = mid + 1;
			else	hi = mid - 1;
		}
		if(lo > hi)	return vector<int>(2, -1);
		vector<int> ans;
		newLo = lo;
		newHi = mid;
		while(newLo < newHi) {
			newMid = (newLo + newHi) >> 1;
			if(nums[newMid] == target)	newHi = newMid;
			else	newLo = newMid + 1;
		}
		ans.push_back(newHi);
		newLo = mid;
		newHi = hi;
		while(newLo < newHi) {
			newMid = (newLo + newHi + 1) >> 1;
			if(nums[newMid] == target)	newLo = newMid;
			else	newHi = newMid - 1;
		}
		ans.push_back(newLo);
		return ans;
	}
};