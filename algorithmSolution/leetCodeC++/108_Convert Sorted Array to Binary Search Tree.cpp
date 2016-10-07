/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Convert Sorted Array to Binary Search Tree
 *					: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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
	TreeNode* sortedArrayToBST(vector<int>& nums, int lo, int hi) {
		TreeNode* root = NULL;
		if(lo <= hi) {
			int mid = lo + ((hi - lo) >> 1);
			root = new TreeNode(nums[mid]);
			root->left  = sortedArrayToBST(nums, lo, mid - 1);
			root->right = sortedArrayToBST(nums, mid + 1, hi);
		}
		return root;
	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return sortedArrayToBST(nums, 0, nums.size() - 1);
	}
};