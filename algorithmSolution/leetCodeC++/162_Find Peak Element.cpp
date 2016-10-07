/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Find Peak Element
 *					: https://leetcode.com/problems/find-peak-element/
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
using namespace std;


class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int numSize = nums.size(), lo = 0, hi = numSize - 1;
		while(lo < hi) {
			int mid = lo + ((hi - lo) >> 1);
			if(nums[mid] < nums[mid + 1])	lo = mid + 1;
			else							hi = mid;
		}
		return lo;
	}
};