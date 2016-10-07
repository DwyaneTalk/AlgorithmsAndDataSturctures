/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Remove Linked List Elements
 *             : https://leetcode.com/problems/remove-linked-list-elements/
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
    if(num == 0)    return NULL;
    ListNode *l = new ListNode(arr[0]);
    ListNode *tmp = l;
    int i;
    for(i = 1; i < num; i++) {
        tmp->next = new ListNode(arr[i]);
        tmp = tmp->next;
    }
    return l;
}

void printfList(ListNode *l) {
    ListNode *ll = l;
    while(ll) {
        printf("%d  ", ll->val);
        ll = ll->next;
    }
    printf("\n");
}
ListNode* removeElements(ListNode* head, int val) {
    ListNode *ans = NULL, *ptr;
    if(head == NULL)    return ans;
    while(head && head->val == val) head = head->next;
    if(head) {
        ans = ptr = (ListNode *)malloc(sizeof(ListNode));
        ans->val = head->val;
        ans->next = NULL;
        head = head->next;
        while(head) {
            if(head->val != val) {
                ptr->next = (ListNode *)malloc(sizeof(ListNode));
                ptr = ptr->next;
                ptr->val = head->val;
                ptr->next = NULL;
            }
            head = head->next;
        }
    }
    return ans;
}

int main() {
    int a[] = {1, 1};
    ListNode *la = initList(a, sizeof(a) / sizeof(int));
    ListNode *lc = removeElements(la, 2);
    printfList(lc);
    return 0;
}
