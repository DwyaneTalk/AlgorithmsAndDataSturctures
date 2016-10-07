/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Trapping Rain Water
 *					: https://leetcode.com/problems/trapping-rain-water/
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
	int trap_range(vector<int>& height, int lo, int hi) {
		if(hi - lo - 1 <= 0)	return 0;
		int maxH = height[lo], secMaxH = -1, maxI = lo, secMaxI = -1;
		for(int i = lo + 1; i <= hi; ++i) {
			if(height[i] > maxH) {
				secMaxH = maxH;
				secMaxI = maxI;
				maxH = height[i];
				maxI = i;
			} else if(height[i] >= secMaxH) {
				secMaxH = height[i];
				secMaxI = i;
			}
		}
		int minIdx = min(maxI, secMaxI);
		int maxIdx = max(maxI, secMaxI);
		int ansLo = trap_range(height, lo, minIdx);
		int ansHi = trap_range(height, maxIdx, hi);
		int ans = ansLo + ansHi + min(maxH, secMaxH) * (maxIdx - minIdx - 1);
		for(int i = minIdx + 1; i < maxIdx; ++i) {
			ans -= height[i];
		}
		return ans;
	}

	int trap_dp(vector<int>& height) {
		int lo = 0, hi = height.size() - 1;
		if(hi - lo - 1 <= 0)	return 0;
		int maxLH = height[lo++], maxRH = height[hi--], ans = 0;
		while (lo <= hi) {
			if(maxLH < maxRH) {
				if(maxLH < height[lo])	maxLH = height[lo];
				ans += maxLH - height[lo++];
			} else {
				if(maxRH < height[hi])	maxRH = height[hi];
				ans += maxRH - height[hi--];
			}
		}
		return ans;
	}

	int trap(vector<int>& height) {
		if(rand() % 2)	return trap_dp(height);
		else			return trap_range(height, 0, height.size() - 1);
	}
};