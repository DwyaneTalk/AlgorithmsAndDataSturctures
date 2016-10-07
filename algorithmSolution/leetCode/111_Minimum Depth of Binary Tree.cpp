/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode111  : Minimum Depth of Binary Tree
*                : https://leetcode.com/problems/minimum-depth-of-binary-tree/
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

int minDepth(TreeNode* root) {
    if (!root)  return 0;
    Queue queue_s, *queue = &queue_s;
    initQueue(queue);
    pushQueue(queue, root);
    int curr_cnt = 1, next_cnt = 0, count = 0, min_depth = 1;
    while (queue->front < queue->rear) {
        root = popQueue(queue);
        if (!root->left && !root->right)
            break;
        if (root->left) {
            pushQueue(queue, root->left);
            ++next_cnt;
        }
        if (root->right) {
            pushQueue(queue, root->right);
            ++next_cnt;
        }
        if (++count == curr_cnt) {
            count = 0;
            curr_cnt = next_cnt;
            next_cnt = 0;
            ++min_depth;
        }
    }
    freeQueue(queue);
    return min_depth;
}

int main() {
    int nums[] = { 1, 2, 4, 5, 0, 0, 0, 0, 3, 0, 0};
    int *ptr_nums = nums;
    TreeNode* root = treeCreate(&ptr_nums);
    treeShow(root, 0);
    int ans = minDepth(root);
    printf("%d\n", ans);
    system("pause");
    return 0;
}
