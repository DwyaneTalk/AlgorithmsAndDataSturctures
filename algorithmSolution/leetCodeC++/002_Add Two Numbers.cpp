/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Add Two Numbers
 *					: https://leetcode.com/problems/add-two-numbers/
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
 ListNode* initList(int array[], int arrSize) {
	 if(!array || !arrSize)	return NULL;
	 ListNode* ans = new ListNode(array[0]), *ptr = ans;
	 for(int i = 1; i < arrSize; ++i) {
		ptr->next = new ListNode(array[i]);
		ptr = ptr->next;
	 }
	 return ans;
 }

 void showList(ListNode* list) {
	 cout << "list: ";
	 while(list) {
		cout << list->val << " ";
		list = list->next;
	 }
	 cout << endl;
 }

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1)	return l2;
		if(!l2)	return l1;
		int sum = l1->val + l2->val;
		int carryBit = sum >= 10;
		ListNode* ans = new ListNode(sum % 10), *ptr = ans;
		l1 = l1->next;
		l2 = l2->next;
		while(l1 && l2) {
			sum = l1->val + l2->val + carryBit;
			carryBit = sum >= 10;
			ptr->next = new ListNode(sum % 10);
			ptr = ptr->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		while(l1) {
			sum = l1->val + carryBit;
			carryBit = sum >= 10;
			ptr->next = new ListNode(sum % 10);
			ptr = ptr->next;
			l1 = l1->next;
		}
		while(l2) {
			sum = l2->val + carryBit;
			carryBit = sum >= 10;
			ptr->next = new ListNode(sum % 10);
			ptr = ptr->next;
			l2 = l2->next;
		}
		if(carryBit) {
			ptr->next = new ListNode(1);
		}
		return ans;
    }
};
