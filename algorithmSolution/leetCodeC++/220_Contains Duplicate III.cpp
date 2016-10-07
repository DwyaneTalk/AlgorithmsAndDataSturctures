/*   DwyaneTalk@gmail.co_m
 *   by lutao
 *   leetCodeC++	: Contains Duplicate III
 *					: https://leetcode.com/problems/contains-duplicate-iii/
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
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		int nSize = nums.size();
		set<int> hashSet;
		for(int i = 0; i < nSize; ++i) {
			if(i > k)	hashSet.erase(nums[i - k - 1]);
			auto pos = hashSet.lower_bound(nums[i] - t);
			if(pos != hashSet.end() && *pos - t <= nums[i])	return true;
			hashSet.insert(nums[i]);
		}
		return false;
	}
};