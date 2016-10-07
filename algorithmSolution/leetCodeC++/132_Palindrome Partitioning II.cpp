/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Palindrome Partitioning II
 *					: https://leetcode.com/problems/palindrome-partitioning-ii/
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
#include <unordered_set>
using namespace std;


class Solution {
public:
	int minCut_dp(string s) {
		int sSize = s.size();
		if(!sSize)	return 0;
		vector<vector<bool>> isPalin(sSize + 1, vector<bool>(sSize + 1, false));
		vector<int> minCuts(sSize + 1, 0);
		for(int i = 1; i <= sSize; ++i) {
			minCuts[i] = i;
			for(int j = i; j >= 1; --j) {
				if(s[j - 1] == s[i - 1]) {
					if(j > i - 2 || isPalin[j][i - 2]) {
						isPalin[j - 1][i - 1] = true;
						minCuts[i] = min(minCuts[i], minCuts[j - 1] + 1);
					}
				}
			}
		}
		return minCuts[sSize] - 1;
	}
	int minCut_Manancher(string s) {
		int sSize = s.size();
		if(!sSize)	return 0;
		vector<int> minCuts(sSize + 1);
		for(int i = 0; i <= sSize; ++i)	minCuts[i] = i - 1;
		for(int i = 0; i < sSize; ++i) {
			for(int j = 0; i - j >=0 && i + j < sSize && s[i - j] == s[i + j]; ++j) {
				minCuts[i + j + 1] = min(minCuts[i + j + 1], minCuts[i - j] + 1);
			}
			for(int j = 0; i - j >=0 && i + j + 1 < sSize && s[i - j] == s[i + j + 1]; ++j) {
				minCuts[i + j + 2] = min(minCuts[i + j + 2], minCuts[i - j] + 1);
			}
		}
		return minCuts[sSize];
	}
	int minCut(string s) {
		return minCut_dp(s);
		return minCut_Manancher(s);
	}
};