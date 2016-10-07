/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: First Bad Version
 *					: https://leetcode.com/problems/first-bad-version/
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;

bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		int lo = 1, hi = n, mid;
		while(lo <= hi) {
			//mid = lo + ((hi - lo) >> 1);
			mid = (long(lo) + hi) >> 1;
			if(isBadVersion(mid))	hi = mid - 1;
			else					lo = mid + 1;
		}
		return lo;
	}
};

bool isBadVersion(int version) {
	return version >= 1;
