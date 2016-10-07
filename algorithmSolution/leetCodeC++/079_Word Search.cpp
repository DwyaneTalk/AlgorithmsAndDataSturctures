/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Word Search
 *					: https://leetcode.com/problems/word-search/
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
	bool backTracking(vector<vector<char>>& board, string word, int idx, int i, int j, vector<vector<bool>>& visited) {
		if(board[i][j] == word[idx++] && visited[i][j] == false) {
			if(idx == word.size())	return true;
			visited[i][j] = true;
			if(i > 0 && backTracking(board, word, idx, i - 1, j, visited))	return true;
			if(i < board.size() - 1 && backTracking(board, word, idx, i + 1, j, visited))	return true;
			if(j > 0 && backTracking(board, word, idx, i, j - 1, visited))	return true;
			if(j < board[0].size() - 1 && backTracking(board, word, idx, i, j + 1, visited))	return true;
			visited[i][j] = false;
		}
		return false;
	}

	bool exist(vector<vector<char>>& board, string word) {
		int m = board.size(), n = (m > 0 ? board[0].size() : 0), wordSize = word.size();
		if(m <= 0 || n <= 0 || wordSize <= 0)	return false;
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < n; ++j) {
				if(backTracking(board, word, 0, i, j, visited))	return true;
			}
		}
		return false;
	}
};