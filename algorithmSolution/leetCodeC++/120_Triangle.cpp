/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Triangle
 *					: https://leetcode.com/problems/triangle/
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
	int minimumTotal(vector<vector<int>>& triangle) {
		int nRows = triangle.size(), ans = INT_MAX, pre_val1;
		vector<int> minPathSum(nRows, 0);
		for(int i = 0; i < nRows; ++i) {
			pre_val1 = minPathSum[0];
			minPathSum[0] += triangle[i][0];
			for(int j = 1; j < i; ++j) {
				pre_val1 = min(pre_val1, minPathSum[j]) + triangle[i][j];
				pre_val1 = minPathSum[j] ^ pre_val1;
				minPathSum[j] = minPathSum[j] ^ pre_val1;
				pre_val1 = minPathSum[j] ^ pre_val1;
			}
			minPathSum[i] = pre_val1 + triangle[i][i];
		}
		for(int i = 0; i < nRows; ++i)	ans = min(ans, minPathSum[i]);
		return ans;
	}
};