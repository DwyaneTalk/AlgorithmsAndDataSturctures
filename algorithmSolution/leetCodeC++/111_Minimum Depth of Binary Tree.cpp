/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Minimum Depth of Binary Tree
 *					: https://leetcode.com/problems/minimum-depth-of-binary-tree/
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
	int minDepth_DFS(TreeNode* root) {
		if(root->left == NULL && root->right == NULL)	return 1;
		int lMin = root->left  == NULL ? INT_MAX : minDepth_DFS(root->left);
		int rMin = root->right == NULL ? INT_MAX : minDepth_DFS(root->right);
		return min(lMin, rMin) + 1;
	}
	int minDepth_BFS(TreeNode* root) {
		int ans = 0;
		if(root) {
			queue<TreeNode*> nodeQueue;
			nodeQueue.push(root);
			int nextCnt = 1, curCnt = 0;
			while(!nodeQueue.empty()) {
				curCnt = nextCnt;
				nextCnt = 0;
				++ans;
				while(curCnt-- > 0) {
					TreeNode* popNode = nodeQueue.front();
					nodeQueue.pop();
					if(!popNode->left && !popNode->right)	return ans;
					if(popNode->left) {
						nodeQueue.push(popNode->left);
						++nextCnt;
					}
					if(popNode->right) {
						nodeQueue.push(popNode->right);
						++nextCnt;
					}
				}
			}
		}
		return ans;
	}

	int minDepth(TreeNode* root) {
		return root ? minDepth_DFS(root) : 0;
		return minDepth_BFS(root);
	}
};