/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode112  : Path Sum
*                : https://leetcode.com/problems/path-sum/
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

bool hasPathSum(TreeNode* root, int sum) {
    if (!root)  return false;
    if (!root->left && !root->right && root->val == sum) return true;
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

int main() {
    int nums[] = { 1, 2, 4, 5, 0, 0, 0, 0, 3, 0, 0};
    int *ptr_nums = nums;
    TreeNode* root = treeCreate(&ptr_nums);
    treeShow(root, 0);
    if (hasPathSum(root, 12))
        printf("Yes!\n");
    else
        printf("No!\n");
    system("pause");
    return 0;
}
