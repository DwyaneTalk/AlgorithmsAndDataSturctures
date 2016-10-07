/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Rotate Array
 *					: https://leetcode.com/problems/rotate-array/
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
	void rotate(vector<int>& nums, int k) {
		int numSize = nums.size();
		k = k % numSize;
		if(numSize < 2 || k == 0)	return;
		int l1 = 0, h1 = numSize - k - 1, l2 = h1 + 1, h2 = numSize - 1, step = 0;
		while(l1 <= h1 || l2 <= h2) {
			if(l1 > h1)	h1 += step;
			else		l2 -= step;
			step = min(h1 - l1, h2 - l2) + 1;
			while(l1 <= h1 && l2 <= h2) {
				nums[l1] = nums[l1] ^ nums[l2];
				nums[l2] = nums[l1] ^ nums[l2];
				nums[l1] = nums[l1] ^ nums[l2];
				++l1;
				++l2;
			}
		}
	}
};