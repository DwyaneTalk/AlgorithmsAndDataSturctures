/*   DwyaneTalk@gmail.co_m
 *   by lutao
 *   leetCodeC++	: Remove Linked List Elements
 *					: https://leetcode.com/problems/remove-linked-list-elements/
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
#include <unordered_map>
#include <time.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :  val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode *newHead = new ListNode(0), *ptr = newHead;
		newHead->next = head;
		while(ptr->next) {
			if(ptr->next->val == val) {
				ListNode* delNode = ptr->next;
				ptr->next = delNode->next;
				delete delNode;
			} else
				ptr = ptr->next;
		}
		ptr = newHead->next;
		delete newHead;
		return ptr;
	}
};