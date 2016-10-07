/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Reverse Nodes in k-Group
 *					: https://leetcode.com/problems/reverse-nodes-in-k-group/
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
	ListNode* reverseKNode(ListNode* head, ListNode*& preHead, int k) {
		if(head == NULL || head->next == NULL)	{
			if(preHead)	preHead->next = (head == NULL ? NULL : head);
			return head;
		}
		ListNode* tmpPtr = NULL, *ptr1 = head, *ptr2 = head->next;
		int count = 1;
		while(ptr2 && count < k) {
			tmpPtr = ptr2->next;
			ptr2->next = ptr1;
			ptr1 = ptr2;
			ptr2 = tmpPtr;
			++count;
		}
		if(count == k) {
			if(preHead)	preHead->next = ptr1;
			preHead = ptr2;
			return ptr1;
		} else {
			head->next = NULL;
			head = ptr1;
			ptr2 = ptr1->next;
			while(ptr2) {
				tmpPtr = ptr2->next;
				ptr2->next = ptr1;
				ptr1 = ptr2;
				ptr2 = tmpPtr;
			}
			if(preHead)	preHead->next = ptr1;
			head->next = NULL;
			return ptr1;
		}
	}
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode *ansHead = NULL, *groupHead = head, *preTail = NULL, *newHead = NULL, *tmpPtr = NULL;
		ansHead = newHead = reverseKNode(groupHead, preTail, k);
		while(newHead != groupHead) {
			tmpPtr    = preTail;
			preTail   = groupHead;
			groupHead = tmpPtr;
			newHead = reverseKNode(groupHead, preTail, k);
		}
		return ansHead;
	}
};
