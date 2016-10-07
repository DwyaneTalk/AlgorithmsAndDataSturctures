/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Spiral Matrix
 *					: https://leetcode.com/problems/spiral-matrix-ii/
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
	vector<vector<int>> generateMatrix(int n) {
		if(n <= 0)	return vector<vector<int>> ();
		vector<vector<int>> ansMatrix(n, vector<int>(n, 0));
		int total = n * n, count = 1, direction = 0, top = 0, bottom = n - 1, left = 0, right = n - 1;
		while(count <= total) {
			switch(direction) {
			case 0:
				for(int i = left; i <= right; ++i)	ansMatrix[top][i]	= count++;
				top++;
				break;
			case 1:
				for(int i = top; i <= bottom; ++i)	ansMatrix[i][right]	= count++;
				--right;
				break;
			case 2:
				for(int i = right; i >= left; --i)	ansMatrix[bottom][i]= count++;
				--bottom;
				break;
			case 3:
				for(int i = bottom; i >= top; --i)	ansMatrix[i][left]	= count++;
				++left;
				break;
			}
			direction = (direction + 1) % 4;
		}
		return ansMatrix;
	}
};