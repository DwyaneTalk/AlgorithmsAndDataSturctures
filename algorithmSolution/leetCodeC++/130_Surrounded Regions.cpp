/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Surrounded Regions
 *					: https://leetcode.com/problems/surrounded-regions/
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
#include <unordered_set>
using namespace std;

class UN {
private:
	vector<int> nums;
	vector<int> rank;
	int			count;
public:
	UN(int count) {
		this->count = count;
		nums.resize(count, 0);
		rank.resize(count, 1);
		for(int i = 0; i < count; ++i)	nums[i] = i;
	}

	int Find(int e) {
		while(e != nums[e]) {
			nums[e] = nums[nums[e]];
			e = nums[e];
		}
		return e;
	}

	void Union(int e1, int e2) {
		int p1 = Find(e1);
		int p2 = Find(e2);
		if(p1 != p2) {
			if(rank[p1] < rank[p2])			nums[p1] = p2;
			else if(rank[p1] > rank[p2])	nums[p2] = p1;
			else {
				nums[p1] = p2;
				rank[p2] += 1;
			}
			--count;
		}
	}
};

class Solution {
public:
	void solve_bfs(vector<vector<char>>& board, int irow, int icol) {
		int m = board.size(), n = (m > 0 ? board[0].size() : 0);
		if(board[irow][icol] == 'O') {
			queue<int> posQueue;
			posQueue.push(irow * n + icol);
			board[irow][icol] = 'A';
			while(!posQueue.empty()) {
				int pos = posQueue.front();
				posQueue.pop();
				int rowi = pos / n;
				int coli = pos % n;
				if(rowi > 0 && board[rowi - 1][coli] == 'O') {
					board[rowi - 1][coli] = 'A';
					posQueue.push((rowi - 1) * n + coli);
				}
				if(rowi < m - 1 && board[rowi + 1][coli] == 'O') {
					board[rowi + 1][coli] = 'A';
					posQueue.push((rowi + 1) * n + coli);
				}
				if(coli > 0 && board[rowi][coli - 1] == 'O') {
					board[rowi][coli - 1] = 'A';
					posQueue.push(rowi * n + coli - 1);
				}
				if(coli < n - 1 && board[rowi][coli + 1] == 'O') {
					board[rowi][coli + 1] = 'A';
					posQueue.push(rowi * n + coli + 1);
				}
			}
		}
	}
	void solve_search(vector<vector<char>>& board) {
		int m = board.size(), n = (m > 0 ? board[0].size() : 0);
		for(int i = 0; i < n; ++i) {
			solve_bfs(board, 0, i);
			solve_bfs(board, m - 1, i);
		}
		for(int i = 0; i < m; ++i) {
			solve_bfs(board, i, 0);
			solve_bfs(board, i, n - 1);
		}
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < n; ++j) {
				if(board[i][j] == 'A')		board[i][j] = 'O';
				else if(board[i][j] == 'O')	board[i][j]	= 'X';
			}
		}
	}

	void solve_union_find(vector<vector<char>>& board) {
		int m = board.size(), n = (m > 0 ? board[0].size() : 0);
		if(m > 0 && n > 0) {
			UN un(m * n + 1);
			for(int i = 0; i < n; ++i) {
				if(board[0][i] == 'O')	un.Union(i, m * n);
				if(board[m - 1][i] == 'O')	un.Union((m - 1) * n + i, m * n);
			}
			for(int i = 0; i < m; ++i) {
				if(board[i][0] == 'O')	un.Union(i * n, m * n);
				if(board[i][n - 1] == 'O')	un.Union(i * n + n - 1, m * n);
			}
			for(int i = 1; i < m - 1; ++i) {
				for(int j = 1; j < n - 1; ++j) {
					if(board[i][j] == 'O') {
						if(board[i - 1][j] == 'O')	un.Union(i * n + j, (i - 1) * n + j);
						if(board[i + 1][j] == 'O')	un.Union(i * n + j, (i + 1) * n + j);
						if(board[i][j - 1] == 'O')	un.Union(i * n + j, i * n + j - 1);
						if(board[i][j + 1] == 'O')	un.Union(i * n + j, i * n + j + 1);
					}
				}
			}
			int unionO = un.Find(m * n);
			for(int i = 0; i < m; ++i) {
				for(int j = 0; j < n; ++j) {
					if(un.Find(i * n + j) != unionO)	board[i][j] = 'X';
				}
			}
		}
	}

	void solve(vector<vector<char>>& board) {
		solve_union_find(board);
		solve_search(board);
	}
};