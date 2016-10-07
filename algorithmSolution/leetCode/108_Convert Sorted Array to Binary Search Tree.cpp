/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode108  : Convert Sorted Array to Binary Search Tree
*                : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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

TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (!numsSize)  return NULL;
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    int mid = numsSize / 2;
    root->val = nums[mid];
    root->left = sortedArrayToBST(nums, mid);
    root->right = sortedArrayToBST(nums + mid + 1, numsSize - 1 - mid);
    return root;
}

int main() {
    int nums[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int numsSize = sizeof(nums) / sizeof(int);
    TreeNode* root = sortedArrayToBST(nums, numsSize);
    treeShow(root, 0);
    system("pause");
    return 0;
}
