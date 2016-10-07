/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Unique Binary Search Trees II
 *					: https://leetcode.com/problems/unique-binary-search-trees-ii/
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
	vector<TreeNode*> generateTrees_divide_conquer(int lo, int hi) {
		if(lo > hi)	{
			return vector<TreeNode*> (1, NULL);
		} else {
			vector<TreeNode*> ansTree;
			for(int n = lo; n <= hi; ++n) {
				vector<TreeNode*> leftList	= generateTrees_divide_conquer(lo, n - 1);
				vector<TreeNode*> rightList	= generateTrees_divide_conquer(n + 1, hi);
				for(int i = 0; i < leftList.size(); ++i) {
					for(int j = 0; j < rightList.size(); ++j) {
						TreeNode* rootNode = new TreeNode(n);
						rootNode->left	= leftList[i];
						rootNode->right	= rightList[j];
						ansTree.push_back(rootNode);
					}
				}
			}
			return ansTree;
		}
	}

	TreeNode* cloneTree(TreeNode* root) {
		TreeNode* ansTree = NULL;
		if(root) {
			ansTree = new TreeNode(root->val);
			ansTree->left = cloneTree(root->left);
			ansTree->right = cloneTree(root->right);
		}
		return ansTree;
	}


	vector<TreeNode*> generateTrees(int n) {
		if(0) {
			if(n <= 0)	return vector<TreeNode*> ();
			else		return generateTrees_divide_conquer(1, n);
		} else {
			if(n <= 0)	return vector<TreeNode*> ();
			vector<TreeNode*>	ansTree(1, new TreeNode(1));
			for(int i = 2; i <= n; ++i) {
				int ansSize = ansTree.size();
				for(int j = 0; j < ansSize; ++j) {
					TreeNode* oldTree = ansTree[j];
					TreeNode* newNode = new TreeNode(i);
					while(oldTree) {
						TreeNode* childTree = oldTree->right;
						oldTree->right = newNode;
						oldTree->right->left = childTree;
						ansTree.push_back(cloneTree(ansTree[j]));
						oldTree->right = childTree;
						oldTree = childTree;
					}
					newNode->left = ansTree[j];
					ansTree[j] = newNode;
				}
			}
			return ansTree;
		}
	}
};