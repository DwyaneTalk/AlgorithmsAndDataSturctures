/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Construct Binary Tree from Preorder and Inorder Traversal
 *					: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int preLo, int preHi, int inLo, int inHi) {
		TreeNode* root = NULL;
		if(preLo <= preHi) {
			root = new TreeNode(preorder[preLo]);
			int lCnt = inLo;
			while(inorder[lCnt] != preorder[preLo])	++lCnt;
			root->left = buildTree(preorder, inorder, preLo + 1, preLo + (lCnt - inLo), inLo, lCnt - 1);
			root->right = buildTree(preorder, inorder, preLo + (lCnt - inLo) + 1, preHi, lCnt + 1, inHi);
		}
		return root;
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
	}
};