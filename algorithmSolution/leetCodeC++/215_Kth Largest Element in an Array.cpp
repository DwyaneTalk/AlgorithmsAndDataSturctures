/*   DwyaneTalk@gmail.co_m
 *   by lutao
 *   leetCodeC++	: Kth Largest Element in an Array
 *					: https://leetcode.com/problems/kth-largest-element-in-an-array/
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
	int findKthLargest_heap(vector<int>& nums, int k) {
		int nSize = nums.size(), ans;
		for(int i = nSize / 2 - 1; i >0; --i) {
			int j = (i << 1) + 1, e = nums[i];
			while (j < nSize) {
				if(j + 1 < nSize && nums[j + 1] > nums[j])	++j;
				if(e < nums[j])	{
					nums[(j - 1) / 2] = nums[j];
					j = (j << 1) + 1;
				} else	break;
			}
			nums[(j - 1) / 2] = e;
		}
		while(k-- > 0) {
			int j = 1, e = nums[0];
			while(j < nSize) {
				if(j + 1 < nSize && nums[j + 1] > nums[j])	++j;
				if(e < nums[j]) {
					nums[(j - 1) / 2] = nums[j];
					j = (j << 1) + 1;
				} else break;
			}
			nums[(j - 1) / 2] = e;
			ans = nums[0];
			nSize--;
			nums[0]		= nums[nSize] ^ nums[0];
			nums[nSize] = nums[nSize] ^ nums[0];
			nums[0]		= nums[nSize] ^ nums[0];
		}
		return ans;
	}
	int findKthLargest_qsort(vector<int>& nums, int k) {
		int nSize = nums.size(), lo = 0, hi = nSize - 1;
		while(1) {
			int e = nums[lo], tlo = lo, thi = hi;
			while(lo < hi) {
				while(lo < hi && nums[hi] >= e)	--hi;
				nums[lo] = nums[hi];
				while(lo < hi && nums[lo] <= e)	++lo;
				nums[hi] = nums[lo];
			}
			nums[lo] = e;
			if(lo + k == nSize)	return e;
			if(lo + k < nSize)	{lo = lo + 1;	hi = thi;}
			else				{hi = lo - 1;	lo = tlo;}
		}
	}

	int findKthLargest(vector<int>& nums, int k) {
		//return findKthLargest_heap(nums, k);
		return findKthLargest_qsort(nums, k);
	}
};