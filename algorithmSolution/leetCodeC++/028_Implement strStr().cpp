/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Implement strStr()
 *					: https://leetcode.com/problems/implement-strstr/
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


class Solution {
public:
	int strStr(string haystack, string needle) {
		int haySize = haystack.size(), neeSize = needle.size();
		for(int i = 0, j; i <= haySize - neeSize; ++i) {
			for(j = 0; j < neeSize; ++j) {
				if(haystack[i + j] != needle[j])	break;
			}
			if(j == neeSize)	return i;
		}
		return -1;
	}
};