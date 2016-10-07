/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Flatten Binary Tree to Linked List
 *					: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
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
	TreeNode* flatten_child(TreeNode* root) {
		TreeNode* lastNode = root;
		if(root->left) {
			lastNode = flatten_child(root->left);
			lastNode->right = root->right;
			root->right = root->left;
			root->left	= NULL;
		}
		if(root->right)	lastNode = flatten_child(root->right);
		return lastNode;
	}

	void flatten(TreeNode* root) {
		if(root)	flatten_child(root);
	}
};