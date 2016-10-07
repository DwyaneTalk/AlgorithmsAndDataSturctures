/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode92   : Reverse Linked List II 
*                : https://leetcode.com/problems/reverse-linked-list-ii/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <algorithm>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
typedef struct ListNode ListNode;

ListNode *initList(int arr[], int num) {
    if (num == 0)    return NULL;
    ListNode *l = new ListNode(arr[0]);
    ListNode *tmp = l;
    int i;
    for (i = 1; i < num; i++) {
        tmp->next = new ListNode(arr[i]);
        tmp = tmp->next;
    }
    return l;
}

void printfList(ListNode *l) {
    ListNode *ll = l;
    while (ll) {
        printf("%d  ", ll->val);
        ll = ll->next;
    }
    printf("\n");
}

int getListSize(ListNode *head) {
    int ans = 0;
    while (head) {
        ans++;
        head = head->next;
    }
    return ans;
}

ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (!head || m < 1 || m >= n)   return head;
    int iter = 2;
    ListNode *node_n, *node_head, *node_pre, *node_cur, *node_next;
    if (m == 1) {
        node_head = NULL;
        node_n = head;
    } else {
        node_head = head;
        while (iter < m) {
            node_head = node_head->next;
            ++iter;
        }
        node_n = node_head->next;
    }
    node_pre = node_n;
    node_cur = node_n->next;
    node_next = node_cur->next;
    iter = m + 1;
    while (iter++ < n) {
        node_cur->next = node_pre;
        node_pre = node_cur;
        node_cur = node_next;
        node_next = node_next->next;
    }
    node_cur->next = node_pre;
    node_n->next = node_next;
    if (node_head) {
        node_head->next = node_cur;
        return head;
    } else {
        return node_cur;
    }
}

int main() {
    int list[] = { 1, 2, 3, 4, 5, 6 };
    int num = sizeof(list) / sizeof(int);
    ListNode* head = initList(list, num);
    printfList(head);
    head = reverseBetween(head, 6, 6);
    printfList(head);
    system("pause");
    return 0;
}
