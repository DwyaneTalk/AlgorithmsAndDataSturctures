/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Swap Nodes in Pairs
*             : https://leetcode.com/problems/swap-nodes-in-pairs/
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

ListNode* swapPairs(ListNode* head) {
    ListNode *ans = head;
    ListNode *p1, *p2, *ptr;
    if (head && head->next) {
        ans = head->next;
        p1 = head;
        p2 = head->next;
        p1->next = p2->next;
        p2->next = p1;
        while (p1->next) {
            ptr = p1;
            p1 = p1->next;
            p2 = p1->next;
            if (p2) {
                ptr->next = p2;
                p1->next = p2->next;
                p2->next = p1;
            } 
        }
     }
    return ans;
}

int main() {
    int a[] = {1 };
    ListNode *la = initList(a, sizeof(a) / sizeof(a[0]));
    ListNode *ans = swapPairs(la);
    printfList(ans);
    system("pause");
    return 0;
}
