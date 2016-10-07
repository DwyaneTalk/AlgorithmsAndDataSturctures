/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Rotate List
*             : https://leetcode.com/problems/rotate-list/
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

int getListSize(ListNode *head) {
    int ans = 0;
    while (head) {
        ans++;
        head = head->next;
    }
    return ans;
}



ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !k)    return head;
    ListNode *first = head, *second = head, *ans = head;
    int count = 0, size = getListSize(head);
    k = k % size;
    while (count < k) {
        second = second->next;
        ++count;
    }
    while (second->next) {
        second = second->next;
        first = first->next;
    }
    second->next = head;
    ans = first->next;
    first->next = NULL;
    return ans;
}


int main() {
    int a[] = { 1};
    int k = 2;
    ListNode *la = initList(a, sizeof(a) / sizeof(int));
    printfList(la);
    ListNode *lc = rotateRight(la, k);
    printfList(lc);
    system("pause");
    return 0;
}