/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Insertion Sort List
 *					: https://leetcode.com/problems/insertion-sort-list/
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
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :  val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		ListNode *Head = new ListNode(0), *currNode = head, *nextNode, *insertNode;
		while(currNode) {
			insertNode = Head;
			while(insertNode->next && insertNode->next->val < currNode->val)	insertNode = insertNode->next;
			if(insertNode->next) {
				nextNode = currNode->next;
				currNode->next = insertNode->next;
				insertNode->next = currNode;
			} else {
				nextNode = currNode->next;
				insertNode->next = currNode;
				currNode->next = NULL;
			}
			currNode = nextNode;
		}
		currNode = Head->next;
		delete Head;
		return currNode;
	}
};