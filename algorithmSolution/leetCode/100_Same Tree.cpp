/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode100  : Same Tree 
*                : https://leetcode.com/problems/same-tree/
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

bool isSameTree(TreeNode* p, TreeNode* q) {
    Stack stack_sp, stack_sq, *stack_p = &stack_sp, *stack_q = &stack_sq;
    initStack(stack_p);
    initStack(stack_q);
    while ((p || stack_p->top) && (q || stack_q)) {
        if (p && q) {
            pushStack(stack_p, p);
            pushStack(stack_q, q);
            p = p->left;
            q = q->left;
        } else if (!p && !q) {
            p = popStack(stack_p);
            q = popStack(stack_q);
            if (p->val != q->val)   return false;
            p = p->right;
            q = q->right;
        } else return false;
    }
    return (p == q) && (stack_p->top == stack_q->top);
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
    if (isSameTree(root, root))
        printf("Yes!\n");
    else
        printf("No!\n");
    system("pause");
    return 0;
}
