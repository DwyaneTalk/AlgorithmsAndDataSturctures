/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Binary Tree Right Side View 
*             : https://leetcode.com/problems/binary-tree-right-side-view/
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
//typedef struct TreeNode TreeNode;

void DFS_tree(struct TreeNode *root, int *n, int *ans, int depth) {
    if (depth > *n) *n = depth;
    ans[depth] = root->val;
    if (root->left)
        DFS_tree(root->left, n, ans, depth + 1);
    if (root->right)
        DFS_tree(root->right, n, ans, depth + 1);
}

int *rightSideView(struct TreeNode *root, int *n) {
    int *ans = (int *)malloc(sizeof(int)* 1000);
    *n = 0;
    if (root) {
        DFS_tree(root, n, ans, 0);
        *n = *n + 1;
    }
    return ans;
}

int main() {
    int *ans, n, i;
    struct TreeNode root, *ptr;
    root.val = 1;
    root.left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root.left->val = 2;
    root.left->left = NULL;
    root.left->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root.left->right->left = NULL;
    root.left->right->right = NULL;
    root.left->right->val = 5;
    root.right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root.right->left = NULL;
    root.right->val = 3;
    root.right->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));;
    root.right->right->val = 4;
    root.right->right->left = NULL;
    root.right->right->right = NULL;
    ans = rightSideView(&root, &n);
    for (i = 0; i < n; i++)
        printf("%d\t", ans[i]);
    system("pause");
    return 0;
}
