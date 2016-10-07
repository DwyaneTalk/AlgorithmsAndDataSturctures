/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Next Permutation
 *					: https://leetcode.com/problems/next-permutation/
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
	void nextPermutation(vector<int>& nums) {
		int numSize = nums.size(), i = numSize - 1, j = numSize - 1;
		if(numSize < 2)	return;
		for(; i > 0; --i) {
			if(nums[i - 1] < nums[i])	break;
		}
		if(i != 0) {
			for(; j >= i; --j) {
				if(nums[j] > nums[i - 1])	break;
			}
			nums[i - 1] = nums[i - 1] ^ nums[j];
			nums[j]		= nums[i - 1] ^ nums[j];
			nums[i - 1] = nums[i - 1] ^ nums[j];
		}
		reverse(nums.begin() + i, nums.end());
	}
};