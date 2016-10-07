/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Binary Tree Preorder Traversal
 *					: https://leetcode.com/problems/binary-tree-preorder-traversal/
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
#include <hash_map>
#include <unordered_set>
#include <unordered_map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> preorderTraversal_v2(TreeNode* root) {
		stack<TreeNode*> nodeStack;
		vector<int>	traversalAns;
		TreeNode* currNode = root;
		while(!nodeStack.empty() || currNode) {
			if(currNode == NULL) {
				currNode = nodeStack.top();
				nodeStack.pop();
			}
			if(currNode) {
				traversalAns.push_back(currNode->val);
				if(currNode->right)	nodeStack.push(currNode->right);
				currNode = currNode->left;
			}
		}	
		return traversalAns;
	}
	vector<int> preorderTraversal_v1(TreeNode* root) {
		stack<TreeNode*> nodeStack;
		vector<int>	traversalAns;
		nodeStack.push(root);
		while(!nodeStack.empty()) {
			TreeNode* currNode = nodeStack.top();
			nodeStack.pop();
			if(currNode) {
				traversalAns.push_back(currNode->val);
				if(currNode->right)	nodeStack.push(currNode->right);
				if(currNode->left)	nodeStack.push(currNode->left);
			}
		}
		return traversalAns;
	}
	vector<int> preorderTraversal(TreeNode* root) {
		//return preorderTraversal_v1(root);
		return preorderTraversal_v2(root);
	}
};