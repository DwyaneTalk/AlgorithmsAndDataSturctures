/*   DwyaneTalk@gmail.co_m
 *   by lutao
 *   leetCodeC++	: Ugly Number II
 *					: https://leetcode.com/problems/ugly-number-ii/
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
#include <time.h>
using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> table(n, 0);
		int idx1 = 0, idx2 = 0, idx3 = 0;
		table[0] = 1;
		for(int i = 1; i < n; ++i) {
			table[i] = min(table[idx1] * 2, min(table[idx2] * 3, table[idx3] * 5));
			if(table[i] == table[idx1] * 2)	idx1++;
			if(table[i] == table[idx2] * 3)	idx2++;
			if(table[i] == table[idx3] * 5)	idx3++;
		}
		return table[n - 1];
	}
};