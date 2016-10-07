/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Reverse Linked List 
*             : https://leetcode.com/problems/reverse-linked-list/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
typedef struct ListNode ListNode;

ListNode *initList(int arr[], int num){
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

//非递归实现
ListNode* reverseListNoRecursive(ListNode* head) {
    if (!head || !head->next)   return head;
    ListNode *pre = NULL, *cur = head, *next = head->next;
    while (next) {
        cur->next = pre;
        pre = cur;
        cur = next;
        next = next->next;
    }
    cur->next = pre;
    return cur;
}

ListNode* reverseList(ListNode* head) {
    return reverseListNoRecursive(head);
    // 递归的实现
    if (!head || !head->next)
        return head;
    ListNode *ans = reverseList(head->next);
    ListNode *ptr = ans;
    while (ptr->next)   ptr = ptr->next;
    ptr->next = head;
    head->next = NULL;
    return ans;
}

int main() {
    int a[] = { 1, 2, 3, 4, 5};
    ListNode *la = initList(a, sizeof(a) / sizeof(int));
    printfList(la);
    ListNode *ans = reverseList(la);
    printfList(ans);
    system("pause");
    return 0;
}
