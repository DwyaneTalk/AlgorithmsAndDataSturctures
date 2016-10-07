/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode93   : Restore IP Addresses
*                : https://leetcode.com/problems/restore-ip-addresses/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <algorithm>

#define MIN(a, b) ((a) > (b) ? (b) : (a))

typedef struct {
    char **ans;
    int  returnSize;
    int  max_size;
    int  len;
} Result;

void initResult(Result* res, int len) {
    res->ans = (char**) malloc(sizeof(char*) * 50);
    res->returnSize = 0;
    res->max_size = 50;
    res->len = len + 4;
}

void renewResult(Result* res) {
    res->ans = (char**)realloc(res->ans, sizeof(char*)* (res->returnSize + 10));
    res->max_size += 10;
}

void pushResult(Result*res, char* s, int* pos) {
    if (res->returnSize >= res->max_size)
        renewResult(res);
    res->ans[res->returnSize] = (char*)malloc(sizeof(char)* res->len);
    res->ans[res->returnSize][res->len - 1] = '\0';
    memcpy(res->ans[res->returnSize], s, sizeof(char)* pos[0]);
    res->ans[res->returnSize][pos[0]] = '.';
    memcpy(res->ans[res->returnSize] + pos[0] + 1, s + pos[0], sizeof(char)* (pos[1] - pos[0]));
    res->ans[res->returnSize][pos[1] + 1] = '.';
    memcpy(res->ans[res->returnSize] + pos[1] + 2, s + pos[1], sizeof(char)* (pos[2] - pos[1]));
    res->ans[res->returnSize][pos[2] + 2] = '.';
    memcpy(res->ans[res->returnSize] + pos[2] + 3, s + pos[2], sizeof(char)* (res->len - 4 - pos[0]));
    ++res->returnSize;
}

int charToNum(char* s, int size) {
    int num = 0;
    for (int i = 0; i < size; ++i)
        num = num * 10 + s[i] - '0';
    return num;
}

void ipAddress(char* s, Result* res, int* pos, int idx) {
    int len = res->len - 4;
    int num;
    if (idx == 4) {
        num = charToNum(s + pos[3], len - pos[3]);
        if (num < 256 && !(s[pos[3]] == '0' && len > pos[3] + 1))
            pushResult(res, s, pos + 1);
    } else {
        int start = pos[idx - 1], end = MIN(start + 3, len + idx - 4);
        for (int i = start; i < end; ++i) {
            num = charToNum(s + start, i - start + 1);
            if (num < 256 && !(s[start] == '0' && i > start)) {
                pos[idx] = i + 1;
                ipAddress(s, res, pos, idx + 1);
            }
        }
    }
}

char** restoreIpAddresses(char* s, int* returnSize) {
    *returnSize = 0;
    if (!s) return NULL;
    int len = strlen(s);
    if (len < 4 || len > 12)    return NULL;
    Result result, *res = &result;
    initResult(res, len);
    int pos[4] = {0}, idx = 1;
    ipAddress(s, res, pos, idx);
    *returnSize = res->returnSize;
    return res->ans;
}

int main() {
    char s[] = "010010";
    int returnSize;
    char **ans = restoreIpAddresses(s, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%s\n", ans[i]);
    }
    system("pause");
    return 0;
}
