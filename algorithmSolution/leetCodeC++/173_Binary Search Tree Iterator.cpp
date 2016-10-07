/*   DwyaneTalk@gmail.co_m
 *   by lutao
 *   leetCodeC++	: Binary Search Tree Iterator
 *					: https://leetcode.com/problems/binary-search-tree-iterator/
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

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
	stack<TreeNode*> treeStack;
public:
	BSTIterator(TreeNode *root) {
		pushStack(root);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !treeStack.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode* node = treeStack.top();
		treeStack.pop();
		pushStack(node->right);
		return node->val;
	}

	void pushStack(TreeNode* root) {
		while(root) {
			treeStack.push(root);
			root = root->left;
		}
	}
};
