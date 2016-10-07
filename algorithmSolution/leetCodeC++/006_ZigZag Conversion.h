/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: ZigZag Conversion
 *					: https://leetcode.com/problems/zigzag-conversion/
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		int strSize = s.size(), T = 2 * numRows - 2, i = 0, j = 0, irow = 0;
		string ans = s;
		if(numRows <= 1)	return ans;
		for(i = 0; i < strSize; ans[j++] = s[i], i += T);
		for(irow = 1; irow < numRows - 1; ++irow) {
			for(i = irow; i < strSize; i += T) {
				ans[j++] = s[i];
				if(i - irow + T - irow < strSize)	ans[j++] = s[i - irow + T - irow];
			}
		}
		for(i = numRows - 1; i < strSize; ans[j++] = s[i], i += T);
		return ans;
	}
};