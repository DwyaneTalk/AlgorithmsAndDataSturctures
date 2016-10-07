/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode110  : Balanced Binary Tree
*                : https://leetcode.com/problems/balanced-binary-tree/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define ABS(x)  ((x) > 0 ? (x) : (-(x)))
#define MAX(a, b)   ((a) > (b) ? (a) : (b))

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

bool balanceHeight(TreeNode* root, int *height) {
    if (!root) {
        *height = 0;
        return true;
    }
    int left, right;
    if (!balanceHeight(root->left, &left) || !balanceHeight(root->right, &right))
        return false;
    if (ABS(left - right) > 1)  return false;
    *height = MAX(left, right) + 1;
    return true;
}

bool isBalanced(TreeNode* root) {
    int height;
    return balanceHeight(root, &height);
}

int main() {
    int nums[] = { 1, 2, 4, 5, 0, 0, 0, 0, 3, 0, 0};
    int *ptr_nums = nums;
    TreeNode* root = treeCreate(&ptr_nums);
    treeShow(root, 0);
    if (isBalanced(root))   printf("Yes!\n");
    else    printf("No!\n");
    system("pause");
    return 0;
}
