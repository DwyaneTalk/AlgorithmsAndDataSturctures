/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Find Minimum in Rotated Sorted Array
 *					: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
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
using namespace std;


class Solution {
public:
	int findMin(vector<int>& nums) {
		int numSize = nums.size(), lo = 0, hi = numSize - 1;
		while(lo < hi) {
			if(nums[lo] < nums[hi])	break;
			int mid = lo + ((hi - lo) >> 1);
			if(nums[mid] > nums[lo]) {
				lo = mid + 1;
			} else {
				hi = mid;
			}
		}
		return nums[lo];
	}
};