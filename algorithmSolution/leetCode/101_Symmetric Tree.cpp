/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode101  : Symmetric Tree
*                : https://leetcode.com/problems/symmetric-tree/
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

bool recursiveSolution(TreeNode* left, TreeNode* right) {
    if (!left && !right)    return true;
    else if (left && right) {
        if (left->val != right->val)    return false;
        return recursiveSolution(left->left, right->right) && recursiveSolution(left->right, right->left);
    } else  return false;
}

bool stackSolution(TreeNode* root) {
    Stack stack_s, *stack = &stack_s;
    initStack(stack);
    TreeNode *left = root->left, *right = root->right;
    pushStack(stack, left);
    pushStack(stack, right);
    while (stack->top) {
        left = popStack(stack);
        right = popStack(stack);
        if (left && right) {
            if (left->val != right->val)    return false;
            pushStack(stack, left->left);
            pushStack(stack, right->right);
            pushStack(stack, left->right);
            pushStack(stack, right->left);
        } else if (left || right) {
            return false;
        }
    }
    return true;
}

bool isSymmetric(TreeNode* root) {
    return !root || recursiveSolution(root->left, root->right);
    return !root || stackSolution(root);
}

int main() {
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = 10;
    root->left = (TreeNode*)malloc(sizeof(TreeNode));
    root->left->val = 5;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (TreeNode*)malloc(sizeof(TreeNode));;
    root->right->val = 15;
    root->right->left = root->right->right = NULL;

    TreeNode* root2 = (TreeNode*)malloc(sizeof(TreeNode));
    root2->val = 10;
    root2->left = (TreeNode*)malloc(sizeof(TreeNode));
    root2->left->val = 5;
    root2->left->left = NULL;
    root2->left->right = (TreeNode*)malloc(sizeof(TreeNode));
    root2->left->right->val = 15;
    root2->left->right->left = root2->left->right->right = NULL;
    root2->right = NULL;
    if (isSymmetric(root))
        printf("Yes!\n");
    else
        printf("No!\n");
    system("pause");
    return 0;
}
