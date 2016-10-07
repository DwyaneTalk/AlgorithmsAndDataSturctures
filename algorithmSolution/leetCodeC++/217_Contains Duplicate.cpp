/*   DwyaneTalk@gmail.co_m
 *   by lutao
 *   leetCodeC++	: Contains Duplicate
 *					: https://leetcode.com/problems/contains-duplicate/
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
	bool containsDuplicate(vector<int>& nums) {
		int nSize = nums.size();
		unordered_set<int> hashSet(nSize);
		for(int i = 0; i < nSize; ++i) {
			if(hashSet.find(nums[i]) != hashSet.end())	return true;
			hashSet.insert(nums[i]);
		}
		return false;
	}
};