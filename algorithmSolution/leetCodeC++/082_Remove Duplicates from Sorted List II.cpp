/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Remove Duplicates from Sorted List II
 *					: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
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
		ListNode *H = new ListNode(0), *ans, *pre = H, *ptr = head, *tmp1, *tmp2;
		int cnt = 0;
		H->next = head;
		while(ptr || cnt > 1) {
			if(ptr && ptr->val == pre->next->val) ++cnt;
			else {
				if(cnt > 1) {
					tmp1 = pre->next;
					while(tmp1 != ptr) {
						tmp2 = tmp1;
						tmp1 = tmp1->next;
						delete tmp2;
					}
					pre->next = ptr;
				} else {
					pre = pre->next;
				}
				cnt = 1;
			}
			if(ptr)	ptr = ptr->next;
		}
		ans = H->next;
		delete H;
		return ans;
	}
};