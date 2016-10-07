/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Linked List Cycle
 *					: https://leetcode.com/problems/linked-list-cycle/
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
	bool hasCycle_hash(ListNode *head) {
		set<ListNode*> nodeHash;
		while(head) {
			if(nodeHash.find(head) == nodeHash.end()) {
				nodeHash.insert(head);
			} else {
				return true;
			}
			head = head->next;
		}
		return false;
	}
	bool hasCycle_twoPointer(ListNode* head) {
		ListNode *slow = head, *fast = head;
		while(fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if(slow == fast)	return true;
		}
		return false;
	}

	bool hasCycle(ListNode *head) {
		//return hasCycle_hash(head);
		return hasCycle_twoPointer(head);
	}
};