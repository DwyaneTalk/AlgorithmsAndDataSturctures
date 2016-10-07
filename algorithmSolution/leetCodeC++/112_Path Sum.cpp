/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Path Sum
 *					: https://leetcode.com/problems/path-sum/
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
	bool hasPathSum(TreeNode* root, int cur_sum, int sum) {
		if(root->left == NULL && root->right == NULL && cur_sum == sum)	return true;
		if(root->left != NULL && hasPathSum(root->left, cur_sum + root->left->val, sum))	return true;
		if(root->right != NULL && hasPathSum(root->right, cur_sum + root->right->val, sum))	return true;
		return false;
	}
	bool hasPathSum(TreeNode* root, int sum) {
		if(root == NULL)	return false;
		return hasPathSum(root, root->val, sum);
	}
};