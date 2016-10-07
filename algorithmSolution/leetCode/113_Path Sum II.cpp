/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode113  : Path Sum II
*                : https://leetcode.com/problems/path-sum-ii/
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

typedef struct{
    int **ans;
    int *columnSizes;
    int returnSize;
    int max_size;
} Result;

typedef struct {
    int *data;
    int max_size;
    int size;
} Route;

void initResult(Result* res) {
    res->ans = (int**)malloc(sizeof(int*)* 10);
    res->columnSizes = (int*)malloc(sizeof(int)* 10);
    res->max_size = 10;
    res->returnSize = 0;
}

void newColumn(Result* res, Route* route) {
    if (res->returnSize >= res->max_size) {
        res->ans = (int**)realloc(res->ans, sizeof(int*)* (res->returnSize + 5));
        res->columnSizes = (int*)realloc(res->columnSizes, sizeof(int)* (res->returnSize + 5));
        res->max_size += 5;
    }
    res->columnSizes[res->returnSize] = route->size;
    res->ans[res->returnSize] = (int*)malloc(sizeof(int)* route->size);
    memcpy(res->ans[res->returnSize], route->data, sizeof(int)* route->size);
    ++(res->returnSize);
}

void initRoute(Route *route) {
    route->data = (int*)malloc(sizeof(int) * 10);
    route->max_size = 10;
    route->size = 0;
}

void addRoute(Route *route, int data) {
    if (route->size == route->max_size) {
        route->data = (int*)realloc(route->data, sizeof(int) * (route->max_size + 5));
        route->max_size += 5;
    }
    route->data[route->size++] = data;
}

void DFS(TreeNode* root, int sum, Result* res, Route* route) {
    if (sum == root->val) {
        if (!root->left && !root->right) {
            addRoute(route, root->val);
            newColumn(res, route);
            route->size -= 1;
        } else {
            addRoute(route, root->val);
            if (root->left) DFS(root->left, sum - root->val, res, route);
            if (root->right) DFS(root->right, sum - root->val, res, route);
            route->size -= 1;
        }
    } else {
        addRoute(route, root->val);
        if (root->left) DFS(root->left, sum - root->val, res, route);
        if (root->right) DFS(root->right, sum - root->val, res, route);
        route->size -= 1;
    }
}

int** pathSum(TreeNode* root, int sum, int** columnSizes, int* returnSize) {
    Result result, *res = &result;
    Route route, *rou = &route;
    initResult(res);
    initRoute(rou);
    if (root)
        DFS(root, sum, res, rou);
    free(rou->data);
    *columnSizes = res->columnSizes;
    *returnSize = res->returnSize;
    return res->ans;
}

int main() {
    int nums[] = {1, -2, 1, -1, 0, 0, 0, 3, 0, 0, -3, -2, 0, 0, 0};
    int *ptr_nums = nums;
    TreeNode* root = treeCreate(&ptr_nums);
    treeShow(root, 0);
    int **ans, *columnSizes, returnSize;
    ans = pathSum(root, -1, &columnSizes, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        for (int j = 0; j < columnSizes[i]; ++j)
            printf("%d ", ans[i][j]);
        printf("\n");
    }
    system("pause");
    return 0;
}
