/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode102  : Binary Tree Level Order Traversal
*                : https://leetcode.com/problems/binary-tree-level-order-traversal/
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
    int front;
    int rear;
    int end;
} Queue;

void initQueue(Queue* queue) {
    queue->data = (TreeNode**)malloc(sizeof(TreeNode*)* 100);
    queue->front = 0;
    queue->rear = 0;
    queue->end = 100;
}

void renewQueue(Queue* queue) {
    queue->data = (TreeNode**)realloc(queue->data, sizeof(TreeNode*)* (queue->end + 50));
    queue->end += 50;
}

void pushQueue(Queue* queue, TreeNode* node) {
    if (queue->rear >= queue->end)
        renewQueue(queue);
    queue->data[queue->rear++] = node;
}

TreeNode* popQueue(Queue* queue) {
    return queue->data[(queue->front)++];
}

void freeQueue(Queue* queue) {
    free(queue->data);
    queue->data = NULL;
    queue->front = queue->rear = queue->end = 0;
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

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    Result result, *res = &result;
    initResult(res);
    if (root) {
        Queue queue_s, *queue = &queue_s;
        initQueue(queue);
        pushQueue(queue, root);
        int curr_cnt = 1, next_cnt = 0, count = 0;
        newColumn(res, curr_cnt);
        while (queue->front < queue->rear) {
            root = popQueue(queue);
            //visit
            res->ans[res->returnSize - 1][count] = root->val;
            if (root->left) {
                ++next_cnt;
                pushQueue(queue, root->left);
            }
            if (root->right) {
                ++next_cnt;
                pushQueue(queue, root->right);
            }
            if (++count == curr_cnt) {
                curr_cnt = next_cnt;
                count = 0;
                next_cnt = 0;
                newColumn(res, curr_cnt);
            }
        }
        freeQueue(queue);
        --(res->returnSize);
        free(res->ans[res->returnSize]);
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
    ans = levelOrder(root2, &column, &size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < column[i]; ++j)
            printf("%d ", ans[i][j]);
        printf("\n");
    }
    system("pause");
    return 0;
}
