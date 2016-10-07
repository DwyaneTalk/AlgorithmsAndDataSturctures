/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Remove Duplicates from Sorted List
*             : https://leetcode.com/problems/remove-duplicates-from-sorted-list/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

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
ListNode* deleteDuplicates(ListNode* head) {
    if (!head)  return NULL;
    ListNode *pre = head, *cur = head->next, *tmp;
    while (cur) {
        if (cur->val != pre->val) {
            pre = pre->next;
        } else {
            pre->next = cur->next;
            free(cur);
        }
        cur = pre->next;
    }
    return head;
}

int main() {
    int nums[] = { 1};
    ListNode *head = initList(nums, sizeof(nums) / sizeof(int));
    printfList(head);
    ListNode *ans = deleteDuplicates(head);
    printfList(ans);
    system("pause");
    return 0;
}
