/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Search a 2D Matrix II
 *					: https://leetcode.com/problems/search-a-2d-matrix-ii/
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = (m > 0 ? matrix[0].size() : 0);
		if(m <= 0 || n <= 0)	return false;
		int loRow = 0, hiRow = m - 1;
		while(loRow <= hiRow) {
			if(matrix[loRow][0] <= target && matrix[loRow][n - 1] >= target)	break;
			++loRow;
		}
		while(hiRow >= loRow) {
			if(matrix[hiRow][0] <= target && matrix[hiRow][n - 1] >= target)	break;
			--hiRow;
		}
		for(; loRow <= hiRow; ++loRow) {
			int lo = 0, hi = n - 1, mid;
			while(lo <= hi) {
				mid = lo + ((hi - lo) >> 1);
				if(matrix[loRow][mid] == target)	return true;
				else if(matrix[loRow][mid] < target)lo = mid + 1;
				else								hi = mid - 1;
			}
		}
		return false;
    }
	bool searchMatrix2(vector<vector<int>>& matrix, int target) {
		int m = matrix.size(), n = (m > 0 ? matrix[0].size() : 0);
		if(m <= 0 || n <= 0)	return false;
		int i = 0, j = n - 1;
		while(i < m & j >= 0) {
			if(matrix[i][j] == target)	return true;
			else if(matrix[i][j] < target)	i++;
			else							j--;
		}
		return false;
	}
};