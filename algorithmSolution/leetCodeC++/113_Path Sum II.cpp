/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Path Sum II
 *					: https://leetcode.com/problems/path-sum-ii/
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
	void pathSum(TreeNode* root, int sum, vector<vector<int>>& ans, vector<int>& path, int cur_sum) {
		if(root->left == NULL && root->right == NULL && cur_sum == sum)	ans.push_back(path);
		if(root->left != NULL) {
			path.push_back(root->left->val);
			pathSum(root->left, sum, ans, path, cur_sum + root->left->val); 
			path.pop_back();
		}
		if(root->right != NULL) {
			path.push_back(root->right->val);
			pathSum(root->right, sum, ans, path, cur_sum + root->right->val);
			path.pop_back();
		}
	}

	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> ans;
		if(root != NULL) {
			vector<int> path(1, root->val);
			pathSum(root, sum, ans, path, root->val);
		}
		return ans;
	}
};