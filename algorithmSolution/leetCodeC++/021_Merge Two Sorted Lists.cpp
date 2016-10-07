/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Merge Two Sorted Lists
 *					: https://leetcode.com/problems/merge-two-sorted-lists/
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if(!l1)	return l2;
		if(!l2)	return l1;
		ListNode* ans = NULL, *ptr = NULL;
		if(l1->val < l2->val) {
			ans = l1;
			l1 = l1->next;
		} else {
			ans = l2;
			l2 = l2->next;
		}
		ptr = ans;
		while(l1 && l2) {
			if(l1->val < l2->val) {
				ptr->next = l1;
				ptr = l1;
				l1 = l1->next;
			} else {
				ptr->next = l2;
				ptr = l2;
				l2 = l2->next;
			}
		}
		if(l1)	ptr->next = l1;
		else	ptr->next = l2;
		return ans;
	}
};