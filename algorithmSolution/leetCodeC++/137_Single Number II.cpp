/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Single Number II
 *					: https://leetcode.com/problems/single-number-ii/
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
	int singleNumber(vector<int>& nums) {
		int numSize = nums.size(), sum1 = 0, sum2 = 0, newsum1;
		for(int i = 0; i < numSize; ++i) {
			newsum1 = (sum1 ^ sum2) & (sum1 ^ nums[i]);
			sum2 = ~sum1 & (sum2 ^ nums[i]);
			sum1 = newsum1;
		}
		return sum2;
	}
};