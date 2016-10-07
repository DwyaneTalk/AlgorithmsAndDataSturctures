/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Product of Array Except Self
 *					: https://leetcode.com/problems/product-of-array-except-self/
*/
#include <iostream>
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
	vector<int> productExceptSelf(vector<int>& nums) {
		int numSize = nums.size();
		vector<int> output(numSize);
		output[numSize - 1] = nums[numSize - 1];
		for(int i = numSize - 2; i >= 0; --i)	output[i] = output[i + 1] * nums[i];
		for(int i = 1; i < numSize; ++i)	nums[i] = nums[i - 1] * nums[i];
		output[0] = output[1];
		for(int i = 1; i < numSize - 1; ++i)	output[i] = nums[i - 1] * output[i + 1];
		output[numSize - 1] = nums[numSize - 2];
		return output;
	}
};