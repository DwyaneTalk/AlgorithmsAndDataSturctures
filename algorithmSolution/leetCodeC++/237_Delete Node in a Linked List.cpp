/*   DwyaneTalk@gmail.co_m
 *   by lutao
 *   leetCodeC++	: Delete Node in a Linked List
 *					: https://leetcode.com/problems/delete-node-in-a-linked-list/
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
#include <time.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :  val(x), next(NULL) {}
};

class Solution {
public:
	void deleteNode(ListNode* node) {
		if(node && node->next) {
			ListNode* ptr = node->next;
			node->val = ptr->val;
			node->next = ptr->next;
			delete ptr;
		}
	}
};