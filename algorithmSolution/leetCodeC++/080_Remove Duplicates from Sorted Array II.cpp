/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Remove Duplicates from Sorted Array II
 *					: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
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
#include <hash_set>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int numSize = nums.size(), ptr1 = 1, ptr2 = 0, idx = 0;
		int k = 2;
		while(++ptr2 < numSize) {
			if(nums[ptr2] != nums[idx] || ptr1 - idx < k) {
				if(nums[ptr2] != nums[idx])	idx = ptr1;
				nums[ptr1++] = nums[ptr2];
			}
		}
		return numSize > 0 ? ptr1 : 0;
	}
};