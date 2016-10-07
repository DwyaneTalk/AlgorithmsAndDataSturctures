/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Merge Two Sorted Lists
 *             : https://leetcode.com/problems/merge-two-sorted-lists/
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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *ans = NULL;
    ListNode *p1 = l1, *p2 = l2, *ptr;
    if(!l1) return l2;
    if(!l2) return l1;
    if(p1->val < p2->val) {
        ans = ptr = p1;
        p1 = p1->next;
    } else{
        ans = ptr = p2;
        p2 = p2->next;
    }
    while(p1 && p2) {
        if(p1->val < p2->val) {
            ptr->next = p1;
            ptr = p1;
            p1 = p1->next;
        } else {
            ptr->next = p2;
            ptr = p2;
            p2 = p2->next;
        }
    }
    if(p1)  ptr->next = p1;
    else    ptr->next = p2;
    return ans;
}

int main() {
    int a[] = {1, 5};
    int b[] = {1, 3, 7};
    ListNode *la = initList(a, sizeof(a) / sizeof(int));
    ListNode *lb = initList(b, sizeof(b) / sizeof(int));
    printfList(la);
    printfList(lb);
    ListNode *lc = mergeTwoLists(la, lb);
    printfList(lc);
    return 0;
}
