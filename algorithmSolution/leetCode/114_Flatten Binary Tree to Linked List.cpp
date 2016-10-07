/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode114  : Flatten Binary Tree to Linked List
*                : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

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

TreeNode* DFS(TreeNode* root) {
    if (root) {
        TreeNode* left  = DFS(root->left);
        TreeNode* right = DFS(root->right);
        if (left) {
            left->right = root->right;
            root->right = root->left;
        }
        root->left = NULL;
        if (!right) right = left;
        if (!right) right = root;
        return right;
    } else {
        return NULL;
    }
}

void flatten(TreeNode* root) {
    DFS(root);
}

int main() {
    int nums[] = {1, 0, 5, 0, 6, 0, 0};
    int *ptr_nums = nums;
    TreeNode* root = treeCreate(&ptr_nums);
    treeShow(root, 0);
    flatten(root);
    treeShow(root, 0);
    system("pause");
    return 0;
}
