/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Remove Nth Node From End of List
 *					: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* ptr1 = head, *ptr2 = head;
		while(ptr1 && n-- > 0)	ptr1 = ptr1->next;
		if(n <= 0) {
			if(ptr1 == NULL) {
				head = head->next;
				delete ptr2;
			} else {
				while(ptr1->next) {
					ptr1 = ptr1->next;
					ptr2 = ptr2->next;
				}
				ptr1 = ptr2->next;
				ptr2->next = ptr1->next;
				delete ptr1;
			}
		}
		return head;
	}
};