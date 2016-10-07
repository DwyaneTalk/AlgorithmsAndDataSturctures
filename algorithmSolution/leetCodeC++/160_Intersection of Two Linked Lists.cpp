/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Intersection of Two Linked Lists
 *					: https://leetcode.com/problems/intersection-of-two-linked-lists/
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
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :  val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *getIntersectionNode_Sol1(ListNode *headA, ListNode *headB) {
		int sizeA = 0, sizeB = 0;
		ListNode *ptrA = headA, *ptrB = headB; 
		while(ptrA) {
			++sizeA;
			ptrA = ptrA->next;
		}
		while(ptrB) {
			++sizeB;
			ptrB = ptrB->next;
		}
		ptrA = headA;
		ptrB = headB;
		if(sizeA > sizeB) {
			while(sizeA-- > sizeB)	ptrA = ptrA->next;
		} else {
			while(sizeB-- > sizeA)	ptrB = ptrB->next;
		}
		while(ptrA && ptrA != ptrB) {
			ptrA = ptrA->next;
			ptrB = ptrB->next;
		}
		return ptrA;
	}
	ListNode *getIntersectionNode_Sol2(ListNode *headA, ListNode *headB) {
		ListNode *ptrA = headA, *ptrB = headB, *tmp = NULL;
		if(!ptrA || !ptrB)	return NULL;
		while(ptrA->next)	ptrA = ptrA->next;
		tmp = ptrA;
		ptrA->next = ptrB;
		ListNode *slow = headA, *fast = headA;
		while(fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if(slow == fast)	break;
		}
		if(!fast || !fast->next)	{
			tmp->next = NULL;
			return NULL;
		}
		int circleSize = 1;
		slow = slow->next;
		fast = fast->next->next;
		while(slow != fast) {
			slow = slow->next;
			fast = fast->next->next;
			++circleSize;
		}
		fast = headA;
		slow = headA;
		while(circleSize-- > 0) {
			fast = fast->next;
		}
		while(fast != slow) {
			fast = fast->next;
			slow = slow->next;
		}
		tmp->next = NULL;
		return fast;
	}
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		//return getIntersectionNode_Sol1(headA, headB);
		return getIntersectionNode_Sol2(headA, headB);
	}
};