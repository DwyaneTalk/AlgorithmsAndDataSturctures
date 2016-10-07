/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode106  : Construct Binary Tree from Inorder and Postorder Traversal
*                : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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


TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if (!inorderSize)   return NULL;
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = postorder[postorderSize - 1];
    int mid = 0;
    for (; inorder[mid] != root->val; ++mid);
    root->left = buildTree(inorder, mid, postorder, mid);
    root->right = buildTree(inorder + mid + 1, inorderSize - mid - 1, postorder + mid, postorderSize - mid - 1);
    return root;
}

int main() {
    int postOrder[] = { 4, 5, 2, 6, 7, 3, 1 };
    int inOrder[] = { 4, 2, 5, 1, 6, 3, 7 };
    int size = sizeof(postOrder) / sizeof(int);
    TreeNode* root = buildTree(inOrder, size, postOrder, size);
    treeShow(root, 0);
    system("pause");
    return 0;
}
