/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Binary Tree Zigzag Level Order Traversal
 *					: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if(root) {
			queue<TreeNode*> nodeQueue;
			vector<int> levelAns;
			nodeQueue.push(root);
			int nextCnt = 1, curCnt = 0;
			bool flags = false;
			while(!nodeQueue.empty()) {
				curCnt = nextCnt;
				nextCnt = 0;
				levelAns.clear();
				while(curCnt-- > 0) {
					TreeNode* popNode = nodeQueue.front();
					nodeQueue.pop();
					if(popNode->left) {
						nodeQueue.push(popNode->left);
						++nextCnt;
					}
					if(popNode->right) {
						nodeQueue.push(popNode->right);
						++nextCnt;
					}
					levelAns.push_back(popNode->val);
				}
				if(flags)	reverse(levelAns.begin(), levelAns.end());
				flags = !flags;
				ans.push_back(levelAns);
			}
		}
		return ans;
	}
};