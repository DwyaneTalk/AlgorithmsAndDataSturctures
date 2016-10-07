/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Binary Tree Postorder Traversal
 *					: https://leetcode.com/problems/binary-tree-postorder-traversal/
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
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		stack<TreeNode*> nodeStack;
		vector<int>	traversalAns;
		unordered_set<TreeNode*> nodeSet;
		TreeNode* currNode = root;
		if(root)	nodeStack.push(root);
		while(!nodeStack.empty() || currNode) {
			if(currNode) {
				if(currNode->right)	nodeStack.push(currNode->right);
				if(currNode->left)	nodeStack.push(currNode->left);
				nodeSet.insert(currNode);
				currNode = currNode->left;
			} else {
				currNode = nodeStack.top();
				if(nodeSet.count(currNode) != 0) {
					nodeStack.pop();
					traversalAns.push_back(currNode->val);
					currNode = NULL;
				}
			}
		}
		return traversalAns;
	}
};