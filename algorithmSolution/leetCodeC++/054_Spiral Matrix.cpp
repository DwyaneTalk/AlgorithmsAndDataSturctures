/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Spiral Matrix
 *					: https://leetcode.com/problems/spiral-matrix/
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
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int direction = 0, top = 0, bottom = matrix.size() - 1, left = 0, right = (bottom >= 0 ? matrix[0].size() -1 : -1);
		if(bottom < 0 || right < 0)	return vector<int>();
		int size = (bottom + 1)  * (right + 1), count = 0;
		vector<int> ans(size);
		while(count < size) {
			switch(direction) {
			case 0:
				for(int i = left; i <= right; ++i)	ans[count++] = matrix[top][i];
				top++;
				break;
			case 1:
				for(int i = top; i <= bottom; ++i) ans[count++] = matrix[i][right];
				--right;
				break;
			case 2:
				for(int i = right; i >= left; --i) ans[count++] = matrix[bottom][i];
				--bottom;
				break;
			case 3:
				for(int i = bottom; i >= top; --i) ans[count++] = matrix[i][left];
				++left;
				break;
			}
			direction = (direction + 1) % 4;
		}
		return ans;
	}
};