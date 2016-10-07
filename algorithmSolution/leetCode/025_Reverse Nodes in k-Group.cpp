/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Reverse Nodes in k-Group
 *             : https://leetcode.com/problems/reverse-nodes-in-k-group/
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

void reverseKNode(ListNode *head, ListNode *rear){
    ListNode *next, *ptr;
    next = head->next;
    while(head != rear) {
        ptr = next->next;
        next->next = head;
        head = next;
        next = ptr;
    }
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *phead = head, *prear;
    ListNode *ptr_pre = NULL, *ptr_next;
    ListNode *ans = NULL;
    int i = 0;
    while(1) {
        prear = phead;
        for(i = 0; i < k - 1 && prear; ++i) {
            prear = prear->next;
        }
        if(prear) {
            if(!ans)    ans = prear;
            ptr_next = prear->next;
            reverseKNode(phead, prear);
            if(ptr_pre)
                ptr_pre->next = prear;
            ptr_pre = phead;
            phead = ptr_next;
            if(!phead) {
                ptr_pre->next = NULL;
                break;
            }
        } else{
            if(!ans)
                ans = phead;
            else
                ptr_pre->next = phead;
            break;
        }
    }
    return ans;
}

int main() {
    int a[] = {1, 2, 3, 4};
    ListNode *la = initList(a, sizeof(a) / sizeof(int));
    ListNode *ans= reverseKGroup(la, 2);
    printfList(ans);
    return 0;
}
