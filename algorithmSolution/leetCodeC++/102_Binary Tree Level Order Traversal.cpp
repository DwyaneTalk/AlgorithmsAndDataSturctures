/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Binary Tree Level Order Traversal
 *					: https://leetcode.com/problems/binary-tree-level-order-traversal/
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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if(root) {
			queue<TreeNode*> treeNodeQueue;
			vector<int> levelAns;
			int nextLevelCnt = 1;
			treeNodeQueue.push(root);
			while(!treeNodeQueue.empty()) {
				int curLevelCnt = nextLevelCnt;
				nextLevelCnt = 0;
				levelAns.clear();
				while (curLevelCnt-- > 0) {
					TreeNode* curNode = treeNodeQueue.front();
					treeNodeQueue.pop();
					levelAns.push_back(curNode->val);
					if(curNode->left)	{
						treeNodeQueue.push(curNode->left);
						++nextLevelCnt;
					}
					if(curNode->right)	{
						treeNodeQueue.push(curNode->right);
						++nextLevelCnt;
					}
				}
				ans.push_back(levelAns);
			}
		}
		return ans;
	}
};