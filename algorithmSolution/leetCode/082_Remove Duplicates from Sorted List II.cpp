/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Remove Duplicates from Sorted List II
*             : https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
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

ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next)  return head;
    if (head->val != head->next->val) {
        head->next = deleteDuplicates(head->next);
        return head;
    }
    int val = head->val;
    ListNode *ptr = head, *tmp;
    while (ptr && ptr->val == val) {
        tmp = ptr;
        ptr = ptr->next;
        free(tmp);
    }
    return deleteDuplicates(ptr);
}

int main() {
    int nums[] = { 1, 2, 2, 3, 4, 4, 5, 5 };
    ListNode *head = initList(nums, sizeof(nums) / sizeof(int));
    printfList(head);
    ListNode *ans = deleteDuplicates(head);
    printfList(ans);
    system("pause");
    return 0;
}