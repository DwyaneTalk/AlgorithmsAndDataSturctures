/*   DwyaneTalk@gmail.co_m
 *   by lutao
 *   leetCodeC++	: Minimum Size Subarray Sum
 *					: https://leetcode.com/problems/minimum-size-subarray-sum/
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
	int minSubArrayLen_dp(int s, vector<int>& nums) {
		int minLen = INT_MAX, nSize = nums.size();
		for(int i = 0; i < nSize; ++i) {
			int j = i, sum = 0;
			while(j >= 0 && sum < s) {
				sum += nums[j--];
			}
			if(sum >= s && i - j < minLen)	minLen = i - j;
		}
		return minLen == INT_MAX ? 0 : minLen;
	}
	int minSubArrayLen_2Pointer(int s, vector<int>& nums) {
		int slow = 0, fast = 0, nSize = nums.size(), sum = 0, minLen = INT_MAX;
		while(slow < nSize - 1 || fast < nSize ) {
			if(sum < s) {
				if(fast < nSize)	sum += nums[fast++];
				else	break;
			} else {
				if(fast - slow < minLen)	minLen = fast - slow;
				if(slow < nSize - 1)	sum -= nums[slow++];
				else	break;
			}
		}
		return minLen == INT_MAX ? 0 : minLen;
	}

	int minSubArrayLen(int s, vector<int>& nums) {
		//return minSubArrayLen_dp(s, nums);
		return minSubArrayLen_2Pointer(s, nums);
	}
};