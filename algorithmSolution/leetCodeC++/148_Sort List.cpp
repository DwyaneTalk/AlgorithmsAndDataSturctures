/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Sort List
 *					: https://leetcode.com/problems/sort-list/
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
#include <unordered_set>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :  val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeList(ListNode* head1, ListNode* head2) {
		ListNode *newHead = new ListNode(0), *currNode = newHead;
		while(head1 && head2) {
			if(head1->val < head2->val) {
				currNode->next = head1;
				head1 = head1->next;
			} else {
				currNode->next = head2;
				head2 = head2->next;
			}
			currNode = currNode->next;
		}
		if(head1)	currNode->next = head1;
		else		currNode->next = head2;
		currNode = newHead->next;
		delete newHead;
		return currNode;
	}

	ListNode* sortList(ListNode* &head, int num) {
		if(num == 1) {
			ListNode* newHead = head;
			head = head->next;
			newHead->next = NULL;
			return newHead;
		} else {
			ListNode* lHead = sortList(head, num / 2);
			ListNode* rHead = sortList(head, num - num / 2);
			return mergeList(lHead, rHead);
		}
	}


	ListNode* sortList(ListNode* head) {
		int count = 0;
		ListNode* ptr = head;
		while(ptr) {
			ptr = ptr->next;
			++count;
		}
		if(count)	return sortList(head, count);
		else		return NULL;
	}
};