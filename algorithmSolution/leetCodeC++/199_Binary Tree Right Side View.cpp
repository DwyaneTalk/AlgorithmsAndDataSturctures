/*   DwyaneTalk@gmail.co_m
 *   by lutao
 *   leetCodeC++	: Binary Tree Right Side View
 *					: https://leetcode.com/problems/binary-tree-right-side-view/
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

class Solution {
private:
	vector<int> ans;
public:
	void rightSideView_bfs(TreeNode* root) {
		queue<TreeNode*>	nodeQueue;
		if(root)	nodeQueue.push(root);
		int currCount = 0, nextCount = 1;
		while(!nodeQueue.empty()) {
			currCount = nextCount;
			nextCount = 0;
			while(currCount-- > 0) {
				TreeNode* currNode = nodeQueue.front();
				nodeQueue.pop();
				if(currCount == 0)	ans.push_back(currNode->val);
				if(currNode->left) {
					nodeQueue.push(currNode->left);
					++nextCount;
				}
				if(currNode->right) {
					nodeQueue.push(currNode->right);
					++nextCount;
				}
			}
		}
	}
	void rightSideView_dfs(TreeNode* root, int depth) {
		if(root) {
			if(depth > ans.size())	ans.push_back(root->val);
			rightSideView_dfs(root->right, depth + 1);
			rightSideView_dfs(root->left, depth + 1);
		}
	}

	vector<int> rightSideView(TreeNode* root) {
		rightSideView_bfs(root);
		rightSideView_dfs(root, 1);
		return ans;
	}
};