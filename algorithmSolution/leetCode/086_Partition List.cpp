/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Search in Rotated Sorted Array II 
*             : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
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

ListNode* partition(ListNode* head, int x) {
    ListNode *s_ptr = NULL, *g_ptr = NULL, *s_head = NULL, *g_head = NULL, *ptr = head;
    while (ptr) {
        if (ptr->val < x) {
            if (!s_head) {
                s_head = s_ptr = ptr;
            } else {
                s_ptr->next = ptr;
                s_ptr = ptr;
            }
        } else {
            if (!g_head) {
                g_head = g_ptr = ptr;
            } else {
                g_ptr->next = ptr;
                g_ptr = ptr;
            }
        }
        ptr = ptr->next;
    }
    if (g_ptr)
        g_ptr->next = NULL;
    if (s_head) {
        s_ptr->next = g_head;
        return s_head;
    } else {
        return g_head;
    }
}

int main() {
    int nums[] = { 1, 4, 3, 2, 5, 2};
    int target = 0;
    ListNode *head = initList(nums, sizeof(nums) / sizeof(int));
    printfList(head);
    ListNode *ans = partition(head, target);
    printfList(ans);
    system("pause");
    return 0;
}
