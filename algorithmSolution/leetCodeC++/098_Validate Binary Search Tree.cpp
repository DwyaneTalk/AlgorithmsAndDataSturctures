/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Validate Binary Search Tree
 *					: https://leetcode.com/problems/validate-binary-search-tree/
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
	bool isValidBST(TreeNode* root, int minVal, int maxVal) {
		if(!root)	return true;
		if(root->val == INT_MIN)	return minVal == INT_MIN && !root->left  && isValidBST(root->right, root->val + 1, maxVal);
		if(root->val == INT_MAX)	return maxVal == INT_MAX && !root->right && isValidBST(root->left,  minVal, root->val - 1);
		if(root->val >= minVal && root->val <= maxVal) {
			return isValidBST(root->left, minVal, root->val - 1) && isValidBST(root->right, root->val + 1, maxVal);
		}
		return false;
	}

	bool isValidBST(TreeNode* root) {
		return isValidBST(root, INT_MIN, INT_MAX);
	}
};