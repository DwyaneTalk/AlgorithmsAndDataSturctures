/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode104  : Maximum Depth of Binary Tree
*                : https://leetcode.com/problems/maximum-depth-of-binary-tree/
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

int maxDepth(struct TreeNode* root) {
    if (!root)  return 0;
    Queue queue_q, *queue = &queue_q;
    initQueue(queue);
    pushQueue(queue, root);
    int depth = 0, curr_cnt = 1, next_cnt = 0, count = 0;
    while (queue->front < queue->rear) {
        root = popQueue(queue);
        if (root->left) {
            pushQueue(queue, root->left);
            ++next_cnt;
        }
        if (root->right) {
            pushQueue(queue, root->right);
            ++next_cnt;
        }
        if (++count == curr_cnt) {
            curr_cnt = next_cnt;
            count = 0;
            next_cnt = 0;
            ++depth;
        }
    }
    freeQueue(queue);
    return depth;
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

    printf("%d\n", maxDepth(root));
    system("pause");
    return 0;
}
