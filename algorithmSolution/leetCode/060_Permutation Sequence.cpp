/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Permutation Sequence
*             : https://leetcode.com/problems/permutation-sequence/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


typedef struct List{
    char val;
    struct List* next;
} List;

int getFact(int n) {
    int ans = 1;
    while (n) {
        ans *= n;
        --n;
    }
    return ans;
}

List *initList(int n) {
    if (n < 1) {
        printf("n error!\n");
        exit(-1);
    }
    List *head = (List *)malloc(sizeof(List));
    head->val = '1';
    head->next = NULL;
    List *ptr = head;
    for (int i = 2; i <= n; ++i) {
        ptr->next = (List *)malloc(sizeof(List));
        ptr->next->val = i + '0';
        ptr->next->next = NULL;
        ptr = ptr->next;
    }
    return head;
}

void printList(List *list) {
    while (list) {
        printf("%c -> ", list->val);
        list = list->next;
    }
    printf("->NULL\n");
}

List *getListElem(List *list, int pos, char *elem) {
    List *head = list;
    if (pos == 1) {
        head = list->next;
        *elem = list->val;
        free(list);
    } else {
        List *pre = list, *cur;
        while (pos > 2) {
            pre = pre->next;
            --pos;
        }
        cur = pre->next;
        pre->next = cur->next;
        *elem = cur->val;
        free(cur);
    }
    return head;
}

void getSubPermutation(int curr, int k, char *ans, List *list) {
    char elem;
    if (curr == 1) {
        list = getListElem(list, 1, &elem);
        *ans = elem;
    } else {
        int fact = getFact(curr - 1);
        int a = k / fact;
        int b = k % fact;
        if (b) {
            list = getListElem(list, a + 1, &elem);
            *ans = elem;
            getSubPermutation(curr - 1, b, ans + 1, list);
        } else {
            list = getListElem(list, a, &elem);
            *ans = elem;
            getSubPermutation(curr - 1, fact, ans + 1, list);
        }
    }
}

char* getPermutation(int n, int k) {
    char *ans = (char *)malloc(sizeof(char)* (n + 1));
    ans[n] = '\0';
    List *list = initList(n);
    //printList(list);
    getSubPermutation(n, k, ans, list);
    return ans;
}

int main() {
    int n = 4, k = 6;
    char *ans = getPermutation(n, k);
    printf("%s", ans);
    system("pause");
    return 0;
}
