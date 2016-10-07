/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Search a 2D Matrix
 *					: https://leetcode.com/problems/search-a-2d-matrix/
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
		int lo = 0, hi = m * n - 1, mid, irow, icol;
		while(lo <= hi) {
			mid = lo + ((hi - lo) >> 1);
			irow = mid / n;
			icol = mid % n;
			if(matrix[irow][icol] == target)		return true;
			else if(matrix[irow][icol] < target)	lo = mid + 1;
			else									hi = mid - 1;
		}
		return false;
    }
};