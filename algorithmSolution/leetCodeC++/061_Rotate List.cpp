/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Length of Last Word
 *					: https://leetcode.com/problems/rotate-list/
*/
#include <iostream>
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
	ListNode* rotateRight(ListNode* head, int k) {
		ListNode *ptr1 = head, *ptr2 = head, *ans = NULL;
		if(head == NULL || k == 0)	return head;
		int size = 1;
		while(ptr1->next) {
			ptr1 = ptr1->next;
			++size;
		}
		k = k % size;
		ptr1 = head;
		while(k-- > 0) {
			ptr1 = ptr1->next;
		}
		while(ptr1->next) {
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		ptr1->next = head;
		ans = ptr2->next;
		ptr2->next = NULL;
		return ans;
	}
};