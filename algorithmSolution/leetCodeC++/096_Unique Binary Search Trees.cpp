/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Unique Binary Search Trees
 *					: https://leetcode.com/problems/unique-binary-search-trees/
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

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int numTrees(int n) {
		vector<int> DP(n + 1);
		DP[0] = DP[1] = 1;
		for(int i = 2; i <=n; ++i) {
			int lo = 0, hi = i - 1;
			while(lo < hi)	DP[i] += DP[lo++] * DP[hi--] * 2;
			if(lo == hi)	DP[i] += DP[lo] * DP[hi];
		}
		return DP[n];
	}
};