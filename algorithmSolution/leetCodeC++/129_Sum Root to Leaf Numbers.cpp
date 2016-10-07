/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Sum Root to Leaf Numbers
 *					: https://leetcode.com/problems/sum-root-to-leaf-numbers/
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
	int sumBackTracking(TreeNode* root, int curSum) {
		if(root->left && root->right)	return sumBackTracking(root->left,  10 * curSum + root->val) + sumBackTracking(root->right, 10 * curSum + root->val);
		if(root->left)					return sumBackTracking(root->left,  10 * curSum + root->val);
		if(root->right)					return sumBackTracking(root->right, 10 * curSum + root->val);
		else							return 10 * curSum + root->val;
	}

	int sumNumbers(TreeNode* root) {
		if(root)	return sumBackTracking(root, 0);
		else		return 0;
	}
};