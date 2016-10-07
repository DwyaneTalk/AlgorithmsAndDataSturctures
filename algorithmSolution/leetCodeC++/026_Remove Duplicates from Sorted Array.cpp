/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Remove Duplicates from Sorted Array
 *					: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
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
	int removeDuplicates(vector<int>& nums) {
		int ansIdx = 1, curIdx = 1, numSize = nums.size(), preVal;
		if(numSize <= 0)	return 0;
		preVal = nums[0];
		for(; curIdx < numSize; ++curIdx) {
			if(nums[curIdx] != preVal) {
				preVal = nums[curIdx];
				nums[ansIdx++]	= preVal;
			}
		}
		return ansIdx;
	}
};