/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode98   : Validate Binary Search Tree
*                : https://leetcode.com/problems/validate-binary-search-tree/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

bool treeMin(TreeNode* root, int* min);

bool treeMax(TreeNode* root, int* max) {
    int curr_val = root->val, l_max, r_min, r_max;
    bool l_flags = true, r_flags = true;
    *max = curr_val;
    if (root->left) {
        if(!treeMax(root->left, &l_max))    l_flags =  false;
        if (l_max >= curr_val)  l_flags = false;
        *max = MAX(*max, l_max);
    }
    if (root->right) {
        if(!treeMax(root->right, &r_max))   r_flags = false;
        treeMin(root->right, &r_min);
        if (r_min <= curr_val)  r_flags = false;
        *max = MAX(*max, r_max);
    }
    return l_flags && r_flags;;
}

bool treeMin(TreeNode* root, int* min) {
    int curr_val = root->val, l_min, l_max, r_min;
    bool l_flags = true, r_flags = true;
    *min = curr_val;
    if (root->left) {
        treeMin(root->left, &l_min);
        if (!treeMax(root->left, &l_max))   l_flags = false;
        if (l_max >= curr_val)  l_flags = false;
        *min = MIN(*min, l_min);
    }
    if (root->right) {
        if (!treeMin(root->right, &r_min)) r_flags = false;
        if (r_min <= curr_val)  r_flags = false;
        *min = MIN(*min, r_min);
    }
    return l_flags && r_flags;
}


bool isValidBST(TreeNode* root) {
    if (!root)  return true;
    int curr_val = root->val, l_val, r_val;
    if (root->left) {
        if (!treeMax(root->left, &l_val))    return false;
        if (l_val >= curr_val)  return false;
    }
    if (root->right) {
        if (!treeMin(root->right, &r_val))   return false;
        if (r_val <= curr_val)  return false;
    }
    return true;
}

int main() {
    TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
    node->val = 10;
    node->left = (TreeNode*)malloc(sizeof(TreeNode));
    node->left->val = 5;
    node->left->left = NULL;
    node->left->right = NULL;
    node->right = (TreeNode*)malloc(sizeof(TreeNode));
    node->right->val = 15;
    node->right->left = (TreeNode*)malloc(sizeof(TreeNode));
    node->right->left->val = 6;
    node->right->left->left = NULL;
    node->right->left->right = NULL;
    node->right->right = (TreeNode*)malloc(sizeof(TreeNode));
    node->right->right->val = 20;
    node->right->right->left = NULL;
    node->right->right->right = NULL;
    if (isValidBST(node))    printf("Yes!\n");
    else                     printf("No!\n");
    system("pause");
    return 0;
}
