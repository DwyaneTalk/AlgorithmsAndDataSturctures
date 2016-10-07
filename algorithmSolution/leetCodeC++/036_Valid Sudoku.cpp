/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Valid Sudoku
 *					: https://leetcode.com/problems/valid-sudoku/
*/
#include <iostream>
#include <algorithm>
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
	bool isValidSudoku(vector<vector<char>>& board) {
		vector<int> row(9, 0), col(9, 0), blk(9, 0);
		for(int i = 0; i < 9; ++i) {
			for(int j = 0; j < 9; ++j) {
				if(board[i][j] != '.') {
					int bitMap = 1 << (board[i][j] - '0');
					if((row[i] & bitMap) || (col[j] & bitMap) || (blk[i / 3 * 3 + j / 3] & bitMap))	return false;
					row[i] |= bitMap;
					col[j] |= bitMap;
					blk[i / 3 * 3 + j  /3] |= bitMap;
				}
			}
		}
		return true;
	}
};