/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Maximum Product Subarray
 *					: https://leetcode.com/problems/maximum-product-subarray/
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
	int maxProduct(vector<int>& nums) {
		int numSize = nums.size(), minPre = nums[0], maxPre = nums[0], ansProduct = nums[0];
		for(int i = 1; i < numSize; ++i) {
			int minCur = min(min(minPre * nums[i], maxPre * nums[i]), nums[i]);
			int maxCur = max(max(minPre * nums[i], maxPre * nums[i]), nums[i]);
			ansProduct = max(ansProduct, maxCur);
			minPre = minCur;
			maxPre = maxCur;
		}
		return ansProduct;
	}
};