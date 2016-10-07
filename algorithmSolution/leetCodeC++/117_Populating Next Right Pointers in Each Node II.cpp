/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Populating Next Right Pointers in Each Node
 *					: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
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


struct TreeLinkNode {
	int val;
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void connect_levelTraversal(TreeLinkNode *root) {
		if(root) {
			queue<TreeLinkNode*> nodeQueue;
			nodeQueue.push(root);
			int nextCnt = 1, curCnt = 0;
			while(!nodeQueue.empty()) {
				curCnt = nextCnt;
				nextCnt = 0;
				TreeLinkNode* node = nodeQueue.front();
				nodeQueue.pop();
				while(curCnt-- > 0) {
					if(curCnt != 0)		{
						node->next = nodeQueue.front();
						nodeQueue.pop();
					}
					if(node->left) {
						nodeQueue.push(node->left);
						++nextCnt;
					}
					if(node->right) {
						nodeQueue.push(node->right);
						++nextCnt;
					}
					node = node->next;
				}
			}
		}
	}
	
	void connect(TreeLinkNode *root) {
		TreeLinkNode* child = NULL, *ptr = root, *tmp;
		while (root) {
			child = root;
			while(child) {
				if(child->left) {
					if(child->right)	child->left->next = child->right;
					else {
						tmp = child->next;
						while(tmp && !tmp->left && !tmp->right)	tmp = tmp->next;
						if(tmp)	child->left->next = tmp->left ? tmp->left : tmp->right;
						else	child->left->next = NULL;
						child = tmp;
						continue;
					}
				} 
				if(child->right){
					tmp = child->next;
					while(tmp && !tmp->left && !tmp->right)	tmp = tmp->next;
					if(tmp)	child->right->next = tmp->left ? tmp->left : tmp->right;
					else	child->right->next = NULL;
					child = tmp;
					continue;
				}
				child = child->next;
			}
			while(root && !root->left && !root->right)	root = root->next;
			if(root)	root = root->left ? root->left : root->right;
		}
	}
};