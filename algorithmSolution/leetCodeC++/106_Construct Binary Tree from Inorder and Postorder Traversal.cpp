/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Construct Binary Tree from Inorder and Postorder Traversal
 *					: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int inLo, int inHi, int postLo, int postHi) {
		TreeNode* root = NULL;
		if(inLo <= inHi) {
			root = new TreeNode(postorder[postHi]);
			int lCnt = inLo;
			while(inorder[lCnt] != postorder[postHi])	++lCnt;
			root->left = buildTree(inorder, postorder, inLo, lCnt - 1, postLo, postLo + (lCnt - inLo - 1));
			root->right = buildTree(inorder, postorder, lCnt + 1, inHi, postLo + (lCnt - inLo), postHi - 1);
		}
		return root;
	}

	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
	}
};