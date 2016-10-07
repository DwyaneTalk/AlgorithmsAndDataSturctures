/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Symmetric Tree
 *					: https://leetcode.com/problems/symmetric-tree/
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
	bool isSymmetric(TreeNode* p, TreeNode* q) {
		if(p == NULL && q == NULL)	return true;
		if(p && q)	return (p->val == q->val) && isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
		return false;
	}
	bool isSymmetric(TreeNode* root) {
		return root ? isSymmetric(root->left, root->right) : true;
	}
};