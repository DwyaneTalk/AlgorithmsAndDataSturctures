/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Palindrome Linked List
 *					: https://leetcode.com/problems/palindrome-linked-list/
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
	ListNode* reverseList(ListNode* head) {
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

	bool isPalindrome(ListNode* head) {
		bool ans = true;
		if(head) {
			ListNode *slow = head, *fast = head->next, *list1 = head, *list2, *list3;
			int count = 1;
			while(fast && fast->next) {
				slow = slow->next;
				fast = fast->next->next;
				++count;
			}
			if(1) {
				if(!fast)	--count;
				ListNode* newHead = slow->next;
				ans = (count == 0 ? true : isPalindrome_recursively(head, newHead, count));
			} else {
				list3 = list2 = reverseList(slow->next);
				while(list2) {
					if(list1->val != list2->val) {
						ans = false;
						break;
					}
					list1 = list1->next;
					list2 = list2->next;
				}
				reverseList(list3);
			}
		}
		return ans;
	}

	bool isPalindrome_recursively(ListNode* list1, ListNode* &list2, int count) {
		bool ans = true;
		if(count == 1) {
			ans = list1->val == list2->val;	
			list2 = list2->next;
		} else {
			if(isPalindrome_recursively(list1->next, list2, count - 1))
					ans = list1->val == list2->val;
			else	ans = false;
			list2 = list2->next;
		}
		return ans;
	}
};