/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode117  : Populating Next Right Pointers in Each Node II
*                : https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct TreeLinkNode  {
    int val;
    struct TreeLinkNode  *left;
    struct TreeLinkNode  *right;
    struct TreeLinkNode  *next;
};
typedef struct TreeLinkNode TreeLinkNode;

void treeShow(TreeLinkNode* root, int n) {
    if (root) {
        treeShow(root->right, n + 1);
        for (int i = 0; i < n; ++i)
            printf("   ");
        printf("%d\n", root->val);
        treeShow(root->left, n + 1);
    }
}

TreeLinkNode* treeCreate(int **data) {
    if (!(*(*data))) {
        *data += 1;
        return NULL;
    } else {
        TreeLinkNode* root = (TreeLinkNode*)malloc(sizeof(TreeLinkNode));
        root->val = *(*data);
        *data += 1;
        root->left = treeCreate(data);
        root->right = treeCreate(data);
        root->next = NULL;
        return root;
    }
}

void connect(TreeLinkNode *root) {
    if (!root)  return;
    TreeLinkNode* list1 = root, *node_tmp;
    TreeLinkNode* list2 = (TreeLinkNode*)malloc(sizeof(TreeLinkNode));
    memset(list2, 0, sizeof(TreeLinkNode));
    node_tmp = list2;
    while (list1 || list2->next) {
        if (list1) {
            if (list1->left) {
                node_tmp->next = list1->left;
                node_tmp = node_tmp->next;
            }
            if (list1->right) {
                node_tmp->next = list1->right;
                node_tmp = node_tmp->next;
            }
            list1 = list1->next;
        } else {
            list1 = list2->next;
            list2->next = NULL;
            node_tmp = list2;
        }
    }
}

int main() {
    int nums[] = { 1, 2, 4, 0, 0, 5, 0, 0, 3, 0, 7, 0, 0};
    int *ptr_nums = nums;
    TreeLinkNode* root = treeCreate(&ptr_nums);
    treeShow(root, 0);
    connect(root);
    system("pause");
    return 0;
}
