/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCode : Add Two Numbers
 *            : https://leetcode.com/problems/add-two-numbers/
*/

#include<iostream>
#include<stdio.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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

// 倒置链表，没有使用
ListNode *invertList(ListNode *l){
    ListNode *l1 = l, *l2 = l->next, *l3;
    while(l2) {
        l3 = l2->next;
        l2->next = l1;
        l1 = l2;
        l2 = l3;
    }
    l->next = NULL;
    return l1;
}

void printfList(ListNode *l) {
    ListNode *ll = l;
    while(ll) {
        printf("%d  ", ll->val);
        ll = ll->next;
    }
    printf("\n");
}

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *ans = new ListNode((l1->val + l2->val) % 10);
        ListNode *pl1 = l1->next, *pl2 = l2->next, *pl = ans;
        int carry = 0, sum;
        if((l1->val + l2->val) > 9)   carry = 1;
        while(pl1 && pl2) {
            sum = pl1->val + pl2->val + carry;
            pl->next = new ListNode(sum % 10);
            carry = (int)(sum > 9);
            pl = pl->next;
            pl1 = pl1->next;
            pl2 = pl2->next;
        }
        if (pl1 || pl2) {
            pl1 = pl1 ? pl1 : pl2;
            while(pl1) {
                sum = pl1->val + carry;
                pl->next = new ListNode(sum % 10);
                carry = int (sum > 9);
                pl1 = pl1->next;
                pl = pl->next;
            }
        }
        if (carry) {
            pl->next = new ListNode(1);
        }
        return ans;
    }
};

int main() {
    Solution *ans = new Solution;
    int arr1[] = {5};
    int arr2[] = {5};
    int num1 = 1;
    int num2 = 1;
    ListNode *l1 = initList(arr1, num1);
    ListNode *l2 = initList(arr2, num2);
    printfList(l1);
    printfList(l2);
    ListNode *node = ans->addTwoNumbers(l1, l2);
    printfList(node);
    return 0;
}
