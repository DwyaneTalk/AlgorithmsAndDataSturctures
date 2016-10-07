/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Same Tree
 *					: https://leetcode.com/problems/same-tree/
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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if(p && q) {
			return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		} else if(p == NULL && q == NULL) {
			return true;
		}
		return false;
	}
};