/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Balanced Binary Tree
 *					: https://leetcode.com/problems/balanced-binary-tree/
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
	bool isBalanced(TreeNode* root, int& height) {
		if(!root) {
			height = 0;
			return true;
		}
		int lHeight = 0, rHeight = 0;
		bool lflags = isBalanced(root->left,  lHeight);
		bool rflags = isBalanced(root->right, rHeight);
		height = max(lHeight, rHeight) + 1;
		return lflags && rflags && (abs(lHeight - rHeight) <= 1);
	}

	bool isBalanced(TreeNode* root) {
		int height = 0;
		return isBalanced(root, height);
	}
};