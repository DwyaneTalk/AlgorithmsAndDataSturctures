/*   DwyaneTalk@gmail.co_m
 *   by lutao
 *   leetCodeC++	: Contains Duplicate II
 *					: https://leetcode.com/problems/contains-duplicate-ii/
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
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		int nSize = nums.size();
		map<int, int> hashMap;
		for(int i = 0; i < nSize; ++i) {
			if(hashMap.find(nums[i]) != hashMap.end() && i - hashMap[nums[i]] <= k)	return true;
			hashMap[nums[i]] = i;
		}
		return false;
	}
	bool containsNearbyDuplicate2(vector<int>& nums, int k) {
		int nSize = nums.size();
		unordered_set<int> hashSet;
		for(int i = 0; i < nSize; ++i) {
			if(i > k)	hashSet.erase(nums[i - k - 1]);
			if(hashSet.find(nums[i]) != hashSet.end())	return true;
			hashSet.insert(nums[i]);
		}
		return false;
	}
};