/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Reverse Linked List II
 *					: https://leetcode.com/problems/reverse-linked-list-ii/
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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if(m < n) {
			ListNode* headNode = new ListNode(0), *preTail = headNode;
			headNode->next = head;
			int count = 1;
			while(count++ < m)	preTail = preTail->next;
			ListNode *curNode = preTail->next, *nextNode = curNode->next, *tmpNode;
			while(nextNode && count++ <= n) {
				tmpNode = nextNode->next;
				nextNode->next = curNode;
				curNode = nextNode;
				nextNode = tmpNode;
			}
			preTail->next->next = nextNode;
			preTail->next = curNode;
			head = headNode->next;
			delete headNode;
		}
		return head;
	}
};