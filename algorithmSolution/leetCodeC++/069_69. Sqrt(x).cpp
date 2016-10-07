/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Sqrt(x)
 *					: https://leetcode.com/problems/sqrtx/
*/
#include <iostream>
#include <algorithm>
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
	int mySqrt(int x) {
		if(x < 2)		return x >= 0 ? x : 0;
		int lo = 1, hi = x / 2, mid, tmpVal;
		while(lo <= hi) {
			mid = lo + ((hi - lo) >> 1);
			tmpVal = x / mid;
			if(tmpVal == mid)		return mid;
			else if(tmpVal > mid)	lo = mid + 1;
			else					hi = mid - 1;
		}
		return hi;
	}
};