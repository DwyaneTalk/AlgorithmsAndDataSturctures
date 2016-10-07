/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Reverse String
 *					: https://leetcode.com/problems/reverse-string/
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	string reverseString(string s) {
		int i = 0, j = s.size() - 1;
		while(i < j)	swap(s[i++], s[j--]);
		return s;
	}
};