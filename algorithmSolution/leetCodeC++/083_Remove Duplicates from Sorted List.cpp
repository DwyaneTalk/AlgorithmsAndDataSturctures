/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Remove Duplicates from Sorted List
 *					: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
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
	ListNode* deleteDuplicates(ListNode* head) {
		if(head) {
			ListNode *ptr = head, *tmp;
			while(ptr->next) {
				if(ptr->val != ptr->next->val) {
					ptr = ptr->next;
				} else {
					tmp = ptr->next;
					ptr->next = tmp->next;
					delete tmp;
				}
			}
		}
		return head;
	}
};