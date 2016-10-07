/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: House Robber III
 *					: https://leetcode.com/submissions/detail/66212906/
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


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int rob_dfs(TreeNode* root, int &lans, int &rans) {
		if(!root)	{
			lans = rans = 0;
			return 0;
		}
		int llans, lrans, rlans, rrans;
		lans = rob_dfs(root->left, llans, lrans);
		rans = rob_dfs(root->right, rlans, rrans);
		return max(lans + rans, llans + lrans + rlans + rrans + root->val);
	}
	int rob(TreeNode* root) {
		int ans = 0, lans, rans;
		return rob_dfs(root, lans, rans);
	}
};