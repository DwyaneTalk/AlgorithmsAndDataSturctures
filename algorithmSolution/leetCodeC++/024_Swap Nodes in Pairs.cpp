/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Swap Nodes in Pairs
 *					: https://leetcode.com/problems/swap-nodes-in-pairs/
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
	ListNode* swapPairs(ListNode* head) {
		if(head == NULL || head->next == NULL)	return head;
		ListNode *ansHead = head->next, *ptr1 = NULL, *ptr2 = NULL;
		head->next = ansHead->next;
		ansHead->next = head;
		ptr1 = head;
		ptr2 = head->next;
		while(ptr2 && ptr2->next) {
			ptr1->next = ptr2->next;
			ptr2->next = ptr2->next->next;
			ptr1->next->next = ptr2;
			ptr1 = ptr2;
			ptr2 = ptr2->next;
		}
		return ansHead;
	}
};