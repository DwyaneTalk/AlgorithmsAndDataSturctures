/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Partition List
 *					: https://leetcode.com/problems/partition-list/
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
	ListNode* partition(ListNode* head, int x) {
		ListNode *list1 = new ListNode(0), *list2 = new ListNode(0);
		ListNode *l1 = list1, *l2 = list2, *ans;
		while(head) {
			if(head->val < x) {
				l1->next = head;
				l1 = head;
			} else {
				l2->next = head;
				l2 = head;
			}
			head = head->next;
		}
		if(l1)	l1->next = list2->next;
		if(l2)	l2->next = NULL;
		ans = list1->next;
		delete list1;
		delete list2;
		return ans;
	}
};