/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Remove Nth Node From End of List
 *             : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
typedef struct ListNode ListNode;

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *ptr = head, *tmp;
    int num = 0, i = 1;
    while(ptr) {
        ptr = ptr->next;
        num++;
    }
    ptr = head;
    if(num == n) {
        head = head->next;
  //      free(ptr);
    } else {
        num = num - n;
        while(i++ < num){
            ptr = ptr->next;
        }
        tmp = ptr->next;
        ptr->next = tmp->next;
//        free(tmp);
    }
    return head;
}

ListNode *initList(int arr[], int num){
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

int main() {
    int a[] = {1, 2};
    ListNode *l = initList(a, 2);
    printfList(l);
    ListNode *new_l = removeNthFromEnd(l, 1);
    printfList(new_l);
    return 0;
}
