/*   DwyaneTalk@gmail.co_m
 *   by lutao
 *   leetCodeC++	: Top K Frequent Elements
 *					: https://leetcode.com/problems/top-k-frequent-elements/
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
	vector<int> topKFrequent(vector<int>& nums, int k) {
		map<int, int>	mapCount;
		vector<int>	ans;
		int nSize = nums.size();
		for(int i = 0; i < nSize; ++i)	mapCount[nums[i]] += 1;
		int nMap = mapCount.size(), i = 0;
		vector<int> map1(nMap), map2(nMap);
		for (map<int, int> ::iterator itr = mapCount.begin(); itr != mapCount.end(); ++itr)	{
			map1[i  ] = itr->first;
			map2[i++] = itr->second;
		}
		int lo = 0, hi = nMap - 1;
		while(1) {
			int e1 = map1[lo], e2 = map2[lo], tlo = lo, thi = hi;
			while(lo < hi) {
				while(lo < hi && map2[hi] >= e2)	--hi;
				map1[lo] = map1[hi];
				map2[lo] = map2[hi];
				while(lo < hi && map2[lo] <= e2)	++lo;
				map1[hi] = map1[lo];
				map2[hi] = map2[lo];
			}
			map1[lo] = e1;
			map2[lo] = e2;
			if(lo + k == nMap)	return vector<int>(&map1[lo], &map1[lo] + k);
			if(lo + k < nMap) { lo = lo + 1;	hi = thi;}
			else			  {	hi = lo - 1;	lo = tlo;}
		}
	}
};