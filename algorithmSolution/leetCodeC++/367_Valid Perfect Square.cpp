/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Valid Perfect Square
 *					: https://leetcode.com/problems/valid-perfect-square/
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
	bool isPerfectSquare(int num) {
		if(num < 0)	return false;
		if(num < 2)	return true;
		int lo = 0, hi = num, mid;
		while(lo < hi) {
			mid = lo + ((hi - lo) >> 1);
			if(num / mid < mid)	hi = mid;
			else				lo = mid + 1;
		}
		--hi;
		return (num % hi == 0 && num / hi == hi);
	}
};