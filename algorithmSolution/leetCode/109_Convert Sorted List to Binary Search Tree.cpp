/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode109  : Convert Sorted List to Binary Search Tree
*                : https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct ListNode {
    int val;
    ListNode *next;
};
typedef struct ListNode ListNode;

ListNode *initList(int arr[], int num) {
    if (num == 0)    return NULL;
    ListNode *l = (ListNode*)malloc(sizeof(ListNode));
    l->val = arr[0];
    l->next = NULL;
    ListNode *tmp = l;
    int i;
    for (i = 1; i < num; i++) {
        tmp->next = (ListNode*)malloc(sizeof(ListNode));
        tmp->next->val = arr[i];
        tmp->next->next = NULL;
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

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode TreeNode;

void treeShow(TreeNode* root, int n) {
    if (root) {
        treeShow(root->right, n + 1);
        for (int i = 0; i < n; ++i)
            printf("   ");
        printf("%d\n", root->val);
        treeShow(root->left, n + 1);
    }
}

TreeNode* treeCreate(int **data) {
    if (!(*(*data))) {
        *data += 1;
        return NULL;
    } else {
        TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
        root->val = *(*data);
        *data += 1;
        root->left = treeCreate(data);
        root->right = treeCreate(data);
        return root;
    }
}

int listCount(ListNode* head) {
    int count = 0;
    while (head) {
        ++count;
        head = head->next;
    }
    return count;
}

TreeNode* listToBST(ListNode** node, int count) {
    if (!count) return NULL;
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->left = listToBST(node, count / 2);
    root->val = (*node)->val;
    *node = (*node)->next;
    root->right = listToBST(node, count - count / 2 - 1);
    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    int count = listCount(head);
    ListNode* node = head;
    return listToBST(&node, count);
}

int main() {
    int nums[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int numsSize = sizeof(nums) / sizeof(int);
    ListNode* head = initList(nums, numsSize);
    printfList(head);
    TreeNode* root = sortedListToBST(head);
    treeShow(root, 0);
    system("pause");
    return 0;
}
