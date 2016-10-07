/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode103  : Binary Tree Zigzag Level Order Traversal
*                : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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

void freeStack(Stack* stack) {
    free(stack->data);
    stack->data = NULL;
    stack->top = stack->max_size = 0;
}

typedef struct{
    int **ans;
    int *columnSizes;
    int returnSize;
    int max_size;
} Result;

void initResult(Result* res) {
    res->ans = (int**)malloc(sizeof(int*)* 10);
    res->columnSizes = (int*)malloc(sizeof(int)* 10);
    res->max_size = 10;
    res->returnSize = 0;
}

void newColumn(Result* res, int size) {
    if (res->returnSize >= res->max_size) {
        res->ans = (int**)realloc(res->ans, sizeof(int*)* (res->returnSize + 5));
        res->columnSizes = (int*)realloc(res->columnSizes, sizeof(int)* (res->returnSize + 5));
        res->max_size += 5;
    }
    res->columnSizes[res->returnSize] = size;
    res->ans[res->returnSize] = (int*)malloc(sizeof(int)* size);
    ++(res->returnSize);
}

int** zigzagLevelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    Result result, *res = &result;
    initResult(res);
    if (root) {
        Stack stack_a, stack_b, *stack = &stack_a, *stack_t = &stack_b, *tmp_stack;
        initStack(&stack_a);
        initStack(&stack_b);
        pushStack(stack, root);
        int curr_cnt = 1, next_cnt = 0, count = 0;
        newColumn(res, curr_cnt);
        while (stack->top) {
            root = popStack(stack);
            //visit
            res->ans[res->returnSize - 1][count] = root->val;

            if (res->returnSize % 2) {
                if (root->left) {
                    pushStack(stack_t, root->left);
                    ++next_cnt;
                }
                if (root->right) {
                    pushStack(stack_t, root->right);
                    ++next_cnt;
                }
            } else {
                if (root->right) {
                    pushStack(stack_t, root->right);
                    ++next_cnt;
                }
                if (root->left) {
                    pushStack(stack_t, root->left);
                    ++next_cnt;
                }
            }
            if (++count == curr_cnt) {
                count = 0;
                curr_cnt = next_cnt;
                next_cnt = 0;
                newColumn(res, curr_cnt);
                tmp_stack = stack;
                stack = stack_t;
                stack_t = tmp_stack;
            }
        }
        --(res->returnSize);
        free(res->ans[res->returnSize]);
        freeStack(stack);
        freeStack(stack_t);
    }
    *columnSizes = res->columnSizes;
    *returnSize = res->returnSize;
    return res->ans;
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
    int **ans, *column, size;
    ans = zigzagLevelOrder(root, &column, &size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < column[i]; ++j)
            printf("%d ", ans[i][j]);
        printf("\n");
    }
    system("pause");
    return 0;
}
