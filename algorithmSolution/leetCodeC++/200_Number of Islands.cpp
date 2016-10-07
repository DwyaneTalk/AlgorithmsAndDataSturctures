/*   DwyaneTalk@gmail.co_m
 *   by lutao
 *   leetCodeC++	: Number of Islands
 *					: https://leetcode.com/problems/number-of-islands/
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


class UN {
private:
	vector<int> nums;
	vector<int> rank;
	int			count;
public:
	UN(int count) {
		this->count = count;
		rank.resize(count, 1);
		nums.resize(count);
		for(int i = 0; i < count; ++i)	nums[i] = i;
	}
	int	Find(int e) {
		while(nums[e] != e) {
			nums[e] = nums[nums[e]];
			e = nums[e];
		}
		return e;
	}
	void Union(int a, int b) {
		int pa = Find(a);
		int pb = Find(b);
		if(rank[pa] < rank[pb])		nums[pa] = pb;
		else if(rank[pa] > rank[pb])nums[pb] = pa;
		else {
			nums[pa] = pb;
			++rank[pb];
			--count;
		}
	}
};

class Solution {
public:
	void numIslands_dfs(vector<vector<char>>& grid, char ch, int irow, int icol) {
		int nRow = grid.size(), nCol = (nRow > 0 ? grid[0].size() : 0);
		grid[irow][icol] = ch;
		if(irow + 1 <  nRow && grid[irow + 1][icol] == '1')	numIslands_dfs(grid, ch, irow + 1, icol);
		if(irow - 1 >= 0	&& grid[irow - 1][icol] == '1')	numIslands_dfs(grid, ch, irow - 1, icol);
		if(icol + 1 <  nCol && grid[irow][icol + 1] == '1')	numIslands_dfs(grid, ch, irow, icol + 1);
		if(icol - 1 >= 0	&& grid[irow][icol - 1] == '1')	numIslands_dfs(grid, ch, irow, icol - 1);
	}

	int numIslands(vector<vector<char>>& grid) {
		int nRow = grid.size(), nCol = (nRow > 0 ? grid[0].size() : 0), ans = 0;
		if(0) {
			for(int i = 0; i < nRow; ++i) {
				for(int j = 0; j < nCol; ++j) {
					if(grid[i][j] == '1')	numIslands_dfs(grid, (ans++) + 2 + '0', i, j);
				}
			}
		} else {
			UN un(nRow * nCol);
			for(int i = 0; i < nRow; ++i) {
				for(int j = 0; j < nCol; ++j) {
					if(grid[i][j] == '1') {
						if(i > 0 && grid[i - 1][j] == '1')	un.Union(i * nCol + j, (i - 1) * nCol + j);
						if(j > 0 && grid[i][j - 1] == '1')	un.Union(i * nCol + j, i * nCol + j - 1);
					}
				}
			}
			unordered_set<int>	hashSet;
			for(int i = 0; i < nRow; ++i) {
				for(int j = 0; j < nCol; ++j) {
					if(grid[i][j] == '1')	hashSet.insert(un.Find(i * nCol + j));
				}
			}
			ans = hashSet.size();
		}
		return ans;
	}
};