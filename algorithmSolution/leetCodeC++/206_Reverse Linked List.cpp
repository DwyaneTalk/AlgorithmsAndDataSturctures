/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Reverse Linked List
 *					: https://leetcode.com/problems/reverse-linked-list/
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
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* reverseList_iteratively(ListNode* head) {
		if(head == NULL || head->next == NULL)	return head;
		ListNode *prePtr = NULL, *curPtr = head, *nextPtr = head->next;
		while(curPtr) {
			nextPtr = curPtr->next;
			curPtr->next = prePtr;
			prePtr = curPtr;
			curPtr = nextPtr;
		}
		return prePtr;
	}

	ListNode* reverseList_recursively(ListNode* head, ListNode* tail) {
		if(head) {
			ListNode* newHead = head->next;
			head->next = tail;
			return reverseList_recursively(newHead, head);
		} else {
			return tail;
		}
	}

	ListNode* reverseList(ListNode* head) {
		//return reverseList_iteratively(head);
		return reverseList_recursively(head, NULL);
	}
};