/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Search Insert Position
 *					: https://leetcode.com/problems/search-insert-position/
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
	int searchInsert(vector<int>& nums, int target) {
		int lo = 0, hi = nums.size() - 1, mid;
		while(lo <= hi) {
			mid = lo + ((hi - lo) >> 1);
			if(nums[mid] == target)	return mid;
			else if(nums[mid] > target)	hi = mid - 1;
			else lo = mid + 1;
		}
		return lo;
	}
};