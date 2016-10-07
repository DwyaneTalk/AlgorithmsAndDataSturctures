/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode95   : Unique Binary Search Trees II 
*                : https://leetcode.com/problems/unique-binary-search-trees-ii/
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
    TreeNode* *ans;
    int returnSize;
    int max_size;
}Result;

void initResult(Result* res) {
    res->ans = (TreeNode* *)malloc(sizeof(TreeNode*)* 20);
    res->max_size = 20;
    res->returnSize = 0;
}

void renewResult(Result* res) {
    res->ans = (TreeNode* *)realloc(res->ans, sizeof(TreeNode*)* (res->max_size + 5));
    res->max_size += 5;
}

void pushResult(Result* res, TreeNode* data) {
    if (res->returnSize >= res->max_size)
        renewResult(res);
    res->ans[res->returnSize++] = data;
}

void freeResult(Result* res) {
    free(res->ans);
}

Result* genTrees(int low, int high) {
    Result *res = (Result*) malloc(sizeof(Result));
    initResult(res);
    if (low > high) {
        pushResult(res, NULL);
        return res;
    }
    Result *res_left, *res_right;
    TreeNode* root;
    for (int i = low; i <= high; ++i) {
        res_left = genTrees(low, i - 1);
        res_right = genTrees(i + 1, high);
        for (int l = 0; l < res_left->returnSize; ++l) {
            for (int r = 0; r < res_right->returnSize; ++r) {
                root = (TreeNode*)malloc(sizeof(TreeNode));
                root->val = i;
                root->left = res_left->ans[l];
                root->right = res_right->ans[r];
                pushResult(res, root);
            }
        }
        freeResult(res_left);
        freeResult(res_right);
    }
    return res;
}

TreeNode** generateTrees(int n, int* returnSize) {
    Result *res = genTrees(1, n);
    *returnSize = res->returnSize;
    return res->ans;
}

int main() {
    int n = 3, returnSize;
    TreeNode** ans = generateTrees(n, &returnSize);
    TreeNode* node;
    for (int i = 0; i < returnSize; ++i) {
        node = ans[i];
    }
    system("pause");
    return 0;
}
