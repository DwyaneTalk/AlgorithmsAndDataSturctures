/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Set Matrix Zeroes
 *					: https://leetcode.com/problems/set-matrix-zeroes/
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
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = (m > 0 ? matrix[0].size() : 0);
		if(m <= 0 || n <= 0)	return ;
		vector<int> rows(m), cols(n);
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < n; ++j) {
				if(matrix[i][j] == 0) {
					rows[i] = 1;
					cols[j] = 1;
				}
			}
		}
		for(int i = 0; i < m; ++i) {
			if(rows[i] == 0)	continue;
			for(int j = 0; j < n; ++j)	matrix[i][j] = 0;
		}
		for(int j = 0; j < n; ++j) {
			if(cols[j] == 0)	continue;
			for(int i = 0; i < m; ++i)	matrix[i][j] = 0;
		}
	}
};