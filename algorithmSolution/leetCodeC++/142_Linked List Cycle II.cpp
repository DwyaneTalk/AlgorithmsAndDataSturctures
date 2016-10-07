/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Linked List Cycle II
 *					: https://leetcode.com/problems/linked-list-cycle-ii/
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
	ListNode *detectCycle(ListNode *head) {
		ListNode *startNode = NULL, *ptr1 = head, *ptr2 = head;
		int loop  = 0, count = 0;
		while(ptr2 && ptr2->next) {
			ptr1 = ptr1->next;
			ptr2 = ptr2->next->next;
			if(loop == 1)	++count;
			if(ptr1 == ptr2) {
				++loop;
				if(loop == 2)	break;
			}
		}
		if(count > 0) {
			ptr2 = ptr1 = head;
			while(count-- > 0)	ptr2 = ptr2->next;
			while(ptr1 != ptr2) {
				ptr1 = ptr1->next;
				ptr2 = ptr2->next;
			}
			startNode = ptr1;
		}
		return startNode;
	}
};