/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Reorder List
 *					: https://leetcode.com/problems/reorder-list/
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
#include <hash_map>
#include <unordered_set>
#include <unordered_map>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :  val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reorderList(ListNode* &head, int count) {
		ListNode* preHead = head;
		if(count == 1) {
			head = head->next;
			preHead->next = NULL;
		} else if(count == 2) {
			head = head->next->next;
			preHead->next->next = NULL;
		} else {
			head = head->next;
			ListNode* nextHead = reorderList(head, count - 2);
			preHead->next = head;
			head = head->next;
			preHead->next->next = nextHead;
		}
		return preHead;
	}

	void reorderList(ListNode* head) {
		int count = 0;
		ListNode *ptr = head, *newHead = head;
		while(ptr) {
			++count;
			ptr = ptr->next;
		}
		if(count > 0)	reorderList(newHead, count);
	}
};