/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode99   : Recover Binary Search Tree
*                : https://leetcode.com/problems/recover-binary-search-tree/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <algorithm>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode TreeNode;

typedef struct {
    TreeNode* *data;
    int top;
    int max_size;
} Stack;

void initStack(Stack* stack) {
    stack->data = (TreeNode**)malloc(sizeof(TreeNode*)* 100);
    stack->top = 0;
    stack->max_size = 100;
}

void renewStack(Stack* stack) {
    stack->data = (TreeNode**)realloc(stack->data, sizeof(TreeNode*)* (stack->max_size + 50));
    stack->max_size += 50;
}

void pushStack(Stack* stack, TreeNode* node) {
    if (stack->top >= stack->max_size)
        renewStack(stack);
    stack->data[stack->top++] = node;
}

TreeNode* popStack(Stack* stack) {
    --(stack->top);
    return stack->data[stack->top];
}

void inOrderTraverseSolution(TreeNode* root) {
    if (!root)  return;
    Stack stack_s, *stack = &stack_s;
    TreeNode *first = NULL, *second = NULL, *pre = (TreeNode*) malloc(sizeof(TreeNode)), *tmp_pre = pre;
    pre->val = INT_MIN;
    initStack(stack);
 /*   pushStack(stack, root);
    while (stack->top) {
        while (root->left) {
            pushStack(stack, root->left);
            root = root->left;
        }
        while (stack->top) {
            root = popStack(stack);
            if (!first && pre->val >= root->val)
                first = pre;
            if (first && pre->val >= root->val)
                second = root;
            pre = root;
            if (root->right) {
                pushStack(stack, root->right);
                root = root->right;
                break;
            }
        }
    }*/
    while (root || stack->top) {
        if (root) {
            pushStack(stack, root);
            root = root->left;
        } else {
            root = popStack(stack);
            if (!first && pre->val >= root->val)
                first = pre;
            if (first && pre->val >= root->val)
                second = root;
            pre = root;
            root = root->right;
        }
    }
    tmp_pre->val = first->val;
    first->val = second->val;
    second->val = tmp_pre->val;
    free(tmp_pre);
}

void recoverTree(TreeNode* root) {
    inOrderTraverseSolution(root);
}

int main() {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = 0;
    node->left = (TreeNode*)malloc(sizeof(TreeNode));
    node->left->val = 1;
    node->left->left = NULL;
    node->left->right = NULL;
    node->right = NULL;// (TreeNode*)malloc(sizeof(TreeNode));
    //node->right->val = 15;
    //node->right->left = (TreeNode*)malloc(sizeof(TreeNode));
    //node->right->left->val = 6;
    //node->right->left->left = NULL;
    //node->right->left->right = NULL;
    //node->right->right = (TreeNode*)malloc(sizeof(TreeNode));
    //node->right->right->val = 20;
    //node->right->right->left = NULL;
    //node->right->right->right = NULL;
    recoverTree(node);
    system("pause");
    return 0;
}
