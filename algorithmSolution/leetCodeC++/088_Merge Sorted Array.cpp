/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Merge Sorted Array
 *					: https://leetcode.com/problems/merge-sorted-array/
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
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int mn = (m--) + (n--) - 1;
		while(m >= 0 && n >= 0) {
			if(nums1[m] > nums2[n])	nums1[mn--] = nums1[m--];
			else					nums1[mn--] = nums2[n--];
		}
		while(n >= 0)	nums1[mn--] = nums2[n--];
	}
};