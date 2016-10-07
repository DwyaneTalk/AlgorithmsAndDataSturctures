/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Maximum Depth of Binary Tree
 *					: https://leetcode.com/problems/maximum-depth-of-binary-tree/
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
	int maxDepth_DFS(TreeNode* root) {
		if(!root)	return 0;
		return max(maxDepth_DFS(root->left), maxDepth_DFS(root->right)) + 1;
	}
	int maxDepth_BFS(TreeNode* root) {
		int ans = 0;
		if(root) {
			queue<TreeNode*> nodeQueue;
			nodeQueue.push(root);
			int nextLevelCnt = 1;
			while(!nodeQueue.empty()) {
				int curLevelCnt = nextLevelCnt;
				nextLevelCnt = 0;
				ans ++;
				while(curLevelCnt-- > 0) {
					TreeNode* curNode = nodeQueue.front();
					nodeQueue.pop();
					if(curNode->left) {
						nodeQueue.push(curNode->left);
						++nextLevelCnt;
					}
					if(curNode->right) {
						nodeQueue.push(curNode->right);
						++nextLevelCnt;
					}
				}
			}
		}
		return ans;
	}

	int maxDepth(TreeNode* root) {
		return maxDepth_DFS(root);
		return maxDepth_BFS(root);
	}
};