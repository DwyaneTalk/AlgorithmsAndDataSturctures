/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Palindrome Number
 *					: https://leetcode.com/problems/palindrome-number/
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int lo = 0, hi = height.size() - 1, ans = 0;
		while(lo < hi) {
			int curH	= min(height[lo], height[hi]);
			int curAns	= (hi - lo) * curH;
			ans = ans < curAns ? curAns : ans;
			while(height[lo] <= curH && lo < hi)	++lo;
			while(height[hi] <= curH && lo < hi)	--hi;
		}
		return ans;
	}
};