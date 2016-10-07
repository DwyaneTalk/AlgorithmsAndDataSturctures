/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Single Number III
 *					: https://leetcode.com/problems/single-number-iii/
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
#include <hash_map>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int sum = 0, numSize = nums.size(), nBit = 1, presum;
		for(int i = 0; i < numSize; ++i)	sum = sum ^ nums[i];
		while((sum & nBit) == 0)	nBit = nBit << 1;
		presum = sum;
		for(int i = 0; i < numSize; ++i) {
			if(nums[i] & nBit) {
				sum = sum ^ nums[i];
			}
		}
		vector<int> ans;
		ans.push_back(sum);
		ans.push_back(sum ^ presum);
		return ans;
	}
};