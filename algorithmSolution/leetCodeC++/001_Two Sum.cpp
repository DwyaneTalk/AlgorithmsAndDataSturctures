/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Two Sum
 *					: https://leetcode.com/problems/two-sum/
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:

	vector<int> twoSum(vector<int>& nums, int target) {
		int size = nums.size();
		map<int, int> hashTable;
		map<int, int> ::iterator item;
		vector <int> ans;
		if(size < 2)	return vector<int>();
		for(int i = 0; i < size; ++i) {
			item = hashTable.find(target - nums[i]);
			if(item != hashTable.end()) {
				ans.push_back(item->second);
				ans.push_back(i);
				break;
			} else {
				hashTable[nums[i]] = i;
			}
		}
		return ans;
	}
};
