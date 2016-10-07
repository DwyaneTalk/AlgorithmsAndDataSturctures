/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode124  : Binary Tree Maximum Path Sum
*                : https://leetcode.com/problems/binary-tree-maximum-path-sum/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode  {
    int val;
    struct TreeNode  *left;
    struct TreeNode  *right;
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

TreeNode* maxDownPathSum(TreeNode* root) {
    TreeNode* path = (TreeNode*)malloc(sizeof(TreeNode));
    memset(path, 0, sizeof(TreeNode));
    int maxPathSum = 0;
    if (root->left) {
        path->left = maxDownPathSum(root->left);
        maxPathSum = MAX(maxPathSum, path->left->val);
    }
    if (root->right) {
        path->right = maxDownPathSum(root->right);
        maxPathSum = MAX(maxPathSum, path->right->val);
    }
    path->val = root->val + maxPathSum;
    return path;
}

void maxTurnPathSum(TreeNode* root, TreeNode* path) {
    int maxPathSum = root->val, maxPathSum2 = INT_MIN;
    if (path->left) {
        if (path->left->val > 0)    maxPathSum += path->left->val;
        maxTurnPathSum(root->left, path->left);
        maxPathSum2 = MAX(maxPathSum2, root->left->val);
    }
    if (path->right) {
        if (path->right->val > 0)   maxPathSum += path->right->val;
        maxTurnPathSum(root->right, path->right);
        maxPathSum2 = MAX(maxPathSum2, root->right->val);
    }
    root->val = MAX(maxPathSum, maxPathSum2);
}

void maxPathToRoot(TreeNode* root, int* maxPathSum) {
    int maxPathSumLeft = 0, maxPathSumRight = 0;
    if (root->left) {
        maxPathToRoot(root->left, maxPathSum);
        maxPathSumLeft = MAX(maxPathSumLeft, root->left->val);
    }
    if (root->right) {
        maxPathToRoot(root->right, maxPathSum);
        maxPathSumRight = MAX(maxPathSumRight, root->right->val);
    }
    *maxPathSum = MAX(*maxPathSum, root->val + maxPathSumLeft + maxPathSumRight);
    root->val += MAX(maxPathSumLeft, maxPathSumRight);
}

int maxPathSum(TreeNode* root) {
    if (!root)  return 0;
    if (rand() % 2) {
        TreeNode* path = maxDownPathSum(root);
        maxTurnPathSum(root, path);
        return root->val;
    } else {
        int maxPathSum = INT_MIN;
        maxPathToRoot(root, &maxPathSum);
        return maxPathSum;
    }
}


int main() {
    int data[] = { 1, 2, 0, 0, 3, 0, 0};
    int *data_ptr = data;
    TreeNode* root = treeCreate(&data_ptr);
    treeShow(root, 0);
    printf("ans : %d\n", maxPathSum(root));
    system("pause");
    return 0;
}
