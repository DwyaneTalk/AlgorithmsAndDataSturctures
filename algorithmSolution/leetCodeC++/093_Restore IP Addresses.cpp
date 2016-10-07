/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Restore IP Addresses
 *					: https://leetcode.com/problems/restore-ip-addresses/
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
using namespace std;

class Solution {
public:
	void backTracking(vector<string>& ans, string s, string path, int nPath, int nS) {
		int sSize = s.size(), digital;
		if(nPath == 0 && nS == sSize) {
			ans.push_back(path);
		} else {
			if(sSize - nS >= nPath && sSize - nS <= nPath * 3) {
				path += '.';
				digital = s[nS] - '0';
				if(digital >= 0 && digital <= 9)	backTracking(ans, s, path + s.substr(nS, 1), nPath - 1, nS + 1);
				if(digital >= 1 && digital <= 9) {
					if(nS + 1 < sSize) {
						digital = digital * 10 + s[nS + 1] - '0';
						if(digital >= 10 && digital <= 99)		backTracking(ans, s, path + s.substr(nS, 2), nPath - 1, nS + 2);
					}
					if(nS + 2 < sSize) {
						digital = digital * 10 + s[nS + 2] - '0';
						if(digital >= 100 && digital <= 255)	backTracking(ans, s, path + s.substr(nS, 3), nPath - 1, nS + 3);
					}
				}
			}
		}
	}

	vector<string> restoreIpAddresses(string s) {
		vector<string> ans;
		int sSize = s.size(), digital;
		if(sSize >= 4 && sSize <= 12) {
			digital = s[0] - '0';
			if(digital >= 0 && digital <= 9) backTracking(ans, s, s.substr(0, 1), 3, 1);
			if(digital >= 1 && digital <= 9){
				digital = digital * 10 + s[1] - '0';
				if(digital >= 10 && digital <= 99)		backTracking(ans, s, s.substr(0, 2), 3, 2);
				digital = digital * 10 + s[2] - '0';
				if(digital >= 100 && digital <= 255)	backTracking(ans, s, s.substr(0, 3), 3, 3);
			}
		}
		return ans;
	}
};