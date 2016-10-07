/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Copy List with Random Pointer
 *					: https://leetcode.com/problems/copy-list-with-random-pointer/
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
using namespace std;
struct ListNode {
	int label;
	ListNode *next, *random;
	ListNode(int x) :  val(x), next(NULL), random(NULL) {}
};
typedef struct ListNode RandomListNode;

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if(!head)	return NULL;
		RandomListNode *newHead = new RandomListNode(head->label), *newPtr = newHead, *ptr = head;
		map<RandomListNode*, RandomListNode*> nodeMap;
		nodeMap[head] = newHead;
		newHead->random = head->random;
		while(ptr->next) {
			newPtr->next = new RandomListNode(ptr->next->label);
			newPtr->next->random = ptr->next->random;
			ptr = ptr->next;
			newPtr = newPtr->next;
			nodeMap[ptr] = newPtr;
		}
		newPtr = newHead;
		while(newPtr) {
			if(newPtr->random)	newPtr->random = nodeMap[newPtr->random];
			newPtr = newPtr->next;
		}
		return newHead;
	}
};