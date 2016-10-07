/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Convert Sorted List to Binary Search Tree
 *					: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
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

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	TreeNode* sortedListToBST(ListNode* &head, int listSize) {
		TreeNode* root = NULL;
		if(listSize != 0) {
			root = new TreeNode(0);
			root->left	= sortedListToBST(head, listSize / 2);
			root->val	= head->val;
			head		= head->next;
			root->right = sortedListToBST(head, listSize - 1 - listSize / 2);
		}
		return root;
	}
	TreeNode* sortedListToBST(ListNode* head) {
		int listSize = 0;
		ListNode* node = head;
		while(node) {
			listSize++;
			node = node->next;
		}
		return sortedListToBST(head, listSize);
	}
};