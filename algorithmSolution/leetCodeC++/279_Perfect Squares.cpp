/*   DwyaneTalk@gmail.co_m
 *   by lutao
 *   leetCodeC++	: Perfect Squares
 *					: https://leetcode.com/problems/perfect-squares/
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
	vector<int> table;
	void numSquares_dp(int n) {
		for(int i = 1; i <= n; ++i) {
			int currSqrt = sqrt(double(i));
			if(currSqrt * currSqrt == i) table[i] = 1;
			for(int j = 1; j * j + i <= n; ++j) {
				if(table[i] + 1 < table[j * j + i])	table[j * j + i] = table[i] + 1;
			}
		}
	}
	void numSquares_bfs(int n) {
		if(table[n] == INT_MAX) {
			int currSqrt = sqrt(double(n));
			if(currSqrt * currSqrt == n)	table[n] = 1;
			else {
				for(int i = 1; n - i * i >= 1; ++i) {
					int currVal = n - i * i;
					if(table[currVal] == INT_MAX)	numSquares_bfs(currVal);
					if(table[currVal] + 1 < table[n])	table[n] = table[currVal] + 1;
				}
			}
		}
	}

 	int numSquares(int n) {
		table.resize(n + 1, INT_MAX);
		//numSquares_dp(n);
		numSquares_bfs(n);
		return table[n];
	}
};