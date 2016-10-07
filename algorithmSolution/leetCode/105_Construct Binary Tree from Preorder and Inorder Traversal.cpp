/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode105  : Construct Binary Tree from Preorder and Inorder Traversal
*                : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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


TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if (preorderSize != inorderSize || !preorderSize)    return NULL;
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = preorder[0];
    int mid = 0;
    for (; inorder[mid] != preorder[0]; ++mid);
    node->left = buildTree(preorder + 1, mid, inorder, mid);
    ++mid;
    node->right = buildTree(preorder +  mid, preorderSize - mid , inorder + mid, preorderSize - mid);
    return node;
}

int main() {
    //int preOrder[] = { 1, 2, 4, 5, 3, 6, 7 };
    //int inOrder[] = { 4, 2, 5, 1, 6, 3, 7 };
    //int size = sizeof(preOrder) / sizeof(int);
    //TreeNode* root = buildTree(preOrder, size, inOrder, size);
    //treeShow(root, 0);
    int test[] = { 1, 2, 4, 0, 0, 5, 0, 0, 3, 6, 0, 0, 7, 0, 0};
    int *ptr = test;
    TreeNode* root1 = treeCreate(&ptr);
    treeShow(root1, 0);
    system("pause");
    return 0;
}
