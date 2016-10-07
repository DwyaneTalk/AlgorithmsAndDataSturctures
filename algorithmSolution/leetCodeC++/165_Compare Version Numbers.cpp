/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Compare Version Numbers
 *					: https://leetcode.com/problems/compare-version-numbers/
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
#include <unordered_map>
using namespace std;

class Solution {
public:
	int compareVersion(string version1, string version2) {
		int size1 = version1.size(), size2 = version2.size();
		int idx1 = 0, idx2 = 0, v1 = 0, v2 = 0;
		while(idx1 < size1 || idx2 < size2) {
			v1 = v2 = 0;
			if(idx1 < size1) {
				if(version1[idx1] == '.')	idx1 = size1;
				while(idx1 < size1 && version1[idx1] != '.') {
					v1 = v1 * 10 + version1[idx1++] - '0';
				}
				if(idx1 < size1) ++idx1;
			}
			if(idx2 < size2) {
				if(version2[idx2] == '.')	idx2 = size2;
				while(idx2 < size2 && version2[idx2] != '.') {
					v2 = v2 * 10 + version2[idx2++] - '0';
				}
				if(idx2 < size2) ++idx2;
			}
			if(v1 < v2)	return -1;
			if(v1 > v2)	return 1;
		}
		return 0;
	}
};