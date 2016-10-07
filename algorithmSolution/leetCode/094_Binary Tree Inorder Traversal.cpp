/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode94   : Binary Tree Inorder Traversal
*                : https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    int *ans;
    int returnSize;
    int max_size;
}Result;

void initResult(Result* res) {
    res->ans = (int*)malloc(sizeof(int)* 100);
    res->max_size = 100;
    res->returnSize = 0;
}

void renewResult(Result* res) {
    res->ans = (int*)realloc(res->ans, sizeof(int)* (res->max_size + 50));
    res->max_size += 50;
}

void pushResult(Result* res, int data) {
    if (res->returnSize >= res->max_size)
        renewResult(res);
    res->ans[res->returnSize++] = data;
}

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

void inorderTraversalWithStack(struct TreeNode* root, Result* res) {
    Stack stack_s, *stack = &stack_s;
    initStack(stack);
    /* solution1
    if (root && root->val != '#') {
        pushStack(stack, root);
        while (stack->top) {
            while (root->left && root->left->val != '#') {
                root = root->left;
                pushStack(stack, root);
            }
            while (stack->top) {
                root = popStack(stack);
                pushResult(res, root->val);
                if (root->right && root->right->val != '#') {
                    root = root->right;
                    pushStack(stack, root);
                    break;
                }
            }
        }
    }*/
    while (root || stack->top) {
        if (root) {
            pushStack(stack, root);
            root = root->left;
        } else {
            root = popStack(stack);
            pushResult(res, root->val);
            root = root->right;
        }
    }
}

// referring : http://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html
/*
    步骤：

1. 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点。

2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。

   a) 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。当前节点更新为当前节点的左孩子。

   b) 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空（恢复树的形状）。输出当前节点。当前节点更新为当前节点的右孩子。

3. 重复以上1、2直到当前节点为空。
*/
void inorderMorrisTraversal(struct TreeNode* root,  Result* res) {
    struct TreeNode *pre;
    while (root) {
        if (root->left) {
            pre = root->left;
            while (pre->right && pre->right != root) {
                pre = pre->right;
            }
            if (pre->right) {
                pre->right = NULL;
                pushResult(res, root->val);
                root = root->right;
            } else {
                pre->right = root;
                root = root->left;
            }
        } else {
            pushResult(res, root->val);
            root = root->right;
        }
    }
}

void inorderRecursiveTravesal(struct TreeNode* root, Result* res) {
    if (root) {
        inorderRecursiveTravesal(root->left, res);
        pushResult(res, root->val);
        inorderRecursiveTravesal(root->right, res);
    }
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    Result result, *res = &result;
    initResult(res);

    inorderTraversalWithStack(root, res);
    inorderMorrisTraversal(root, res);

    *returnSize = res->returnSize;
    return res->ans;
}

int main() {
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = 1;
    root->right = NULL;
    root->left = (TreeNode*)malloc(sizeof(TreeNode));
    root->left->val = 2;
    root->left->left = (TreeNode*)malloc(sizeof(TreeNode));
    root->left->left->val = 3;
    root->left->left->left = root->left->left->right = NULL;
    root->left->right = NULL;
    int returnSize;
    int* ans = inorderTraversal(root, &returnSize);
    for (int i = 0; i < returnSize; ++i)
        printf("%d ", ans[i]);
    system("pause");
    return 0;
}
