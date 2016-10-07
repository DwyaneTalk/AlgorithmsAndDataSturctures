/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Length of Last Word
 *					: https://leetcode.com/problems/length-of-last-word/
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
	int lengthOfLastWord(string s) {
		int sSize = s.size(), ans = 0, i = sSize - 1;
		while(i >= 0 && s[i] == ' ')	--i;
		ans = i;
		while(i >= 0 && s[i] != ' ')	--i;
		return ans - i;
	}
};