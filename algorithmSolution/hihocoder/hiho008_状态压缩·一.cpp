/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : 状态压缩·一
*             : http://hihocoder.com/contest/hiho8/problem/1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct LinkNode{
    int pos;
    int status;
    int mount;
    struct LinkNode *next;
} LinkNode;

typedef struct {
    LinkNode *head;
    LinkNode *rear;
} LinkList;

typedef struct {
    int n;
    int m;
    int q;
    int mount[1000];
    LinkList linkList;
    LinkNode *newNode;
    LinkNode *freeNode;
} publicData;


void input(publicData *data) {
    int i;
    FILE *fin = fopen("input.txt", "r");
    //scanf("%d%d%d", &data->n, &data->m, &data->q);
    fscanf(fin, "%d%d%d", &data->n, &data->m, &data->q);
    for (i = 0; i < data->n; ++i) {
        //scanf("%d", &data->mount[i]);
        fscanf(fin, "%d", &data->mount[i]);
    }
    data->linkList.head = data->linkList.rear = NULL;
}

void listAddRear(LinkList *linkList, LinkNode *linkNode) {
    if (!linkList->head) {
        linkList->head = linkList->rear = linkNode;
    } else {
        linkList->rear->next = linkNode;
        linkList->rear = linkNode;
    }
}

LinkNode *listRemoveHead(LinkList *linkList, int pos) {
    LinkNode *returnNode;
    if (linkList->head && linkList->head->pos == pos)   return NULL;
    if (linkList->head == linkList->rear) {
        returnNode = linkList->head;
        linkList->head = linkList->rear = NULL;
    } else {
        returnNode = linkList->head;
        linkList->head = linkList->head->next;
    }
    return returnNode;
}

int isValid(int status, int m, int q) {
    int cnt = 0;
    while (--m) {
        cnt += status & 1;
        status >>= 1;
    }
    return cnt < q;
}

//  针对每一个位置，针对当前链表中的状态，有两种操作，每次执行一种操作，进行一次状态转换加入队列
int solution1(publicData *data) {
    data->newNode = (LinkNode *)malloc(sizeof(LinkNode));
    data->newNode->status = 0;
    data->newNode->mount = 0;
    data->newNode->pos = -1;
    listAddRear(&data->linkList, data->newNode);
    int i, ans = 0;
    for (i = 0; i < data->n; ++i) {
        while (data->freeNode = listRemoveHead(&data->linkList, i)) {
            if (isValid(data->freeNode->status, data->m, data->q)) {        //当前位置可以
                data->newNode = (LinkNode *)malloc(sizeof(LinkNode));
                data->newNode->status = (data->freeNode->status << 1) | 1;
                data->newNode->mount = data->freeNode->mount + data->mount[i];
                data->newNode->pos = i;
                listAddRear(&data->linkList, data->newNode);
            }
            data->freeNode->status <<= 1;
            data->freeNode->pos = i;
            listAddRear(&data->linkList, data->freeNode);
        }
    }
    while (data->freeNode = listRemoveHead(&data->linkList, data->n)) {
        if (data->freeNode->mount > ans)    ans = data->freeNode->mount;
        free(data->freeNode);
    }
    return ans;
}

int solution2(publicData *data) {
    int best[1024] = { 0 }, tmp[1024] = { 0 }, i, j, status_cnt, ans = 0, mask = ~(1 << data->m);
    status_cnt = 1 << data->m;
    for (i = 0; i < data->n; ++i) {
        for (j = 0; j < status_cnt; ++j) {
            if (isValid(j, data->m, data->q)) {
                tmp[((j << 1) | 1) & mask] = MAX(tmp[((j << 1) | 1) & mask], best[j] + data->mount[i]);
            }
            tmp[(j << 1) & mask] = MAX(tmp[(j << 1) & mask], best[j]);
        }
        for (j = 0; j < status_cnt; ++j) {
            best[j] = tmp[j];
            tmp[j] = 0;
        }
    }
    for (j = 0; j < status_cnt; ++j) {
        if (best[j] > ans)  ans = best[j];
    }
    return ans;
}

int main() {
    publicData data;
    input(&data);
    //int ans = solution1(&data);
    int ans = solution2(&data);
    printf("%d\n", ans);
    system("pause");
    return 0;
}