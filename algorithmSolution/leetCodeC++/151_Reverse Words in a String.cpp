/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Reverse Words in a String
 *					: https://leetcode.com/problems/reverse-words-in-a-string/
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
using namespace std;


class Solution {
public:
	void reverseWords(string &s) {
		int sSize = s.size(), head = -1, idx = 0, i;
		for(i = 0; i < sSize; ++i) {
			if(s[i] == ' ') {
				if(head >= 0)	{
					memcpy(&s[idx], &s[head], sizeof(char) * (i - head + 1));
					reverse(&s[idx], &s[idx + i - head]);
					idx += i - head + 1;
					head = -1;
				}
			} else {
				if(head < 0)	head = i;
			}
		}
		if(head >= 0) {
			memcpy(&s[idx], &s[head], sizeof(char) * (i - head));
			reverse(&s[idx], &s[idx + i - head - 1] + 1);
			idx += i - head;
		} else {
			--idx;
		}
		if(idx <= 0)	s = "";
		else {
			s = s.substr(0, idx);
			reverse(s.begin(), s.end());
		}
	}
};