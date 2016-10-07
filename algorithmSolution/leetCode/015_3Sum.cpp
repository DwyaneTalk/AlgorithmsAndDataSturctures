/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : 3Sum
 *             : https://leetcode.com/problems/3sum/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct Node{
    int a;
    int b;
    int c;
    struct Node *next;
} Node;


int compare(const void *p1, const void *p2) {
    return *(int *)p1 - *(int *)p2;
}

bool insertNode(Node *node, int a, int b, int c) {
    Node *ptrNode = node, *newNode;
    while(ptrNode->next){
        if(a < ptrNode->next->a || b < ptrNode->next->b || c < ptrNode->next->c) {
            ptrNode = ptrNode->next;
        } else if(a == ptrNode->next->a || b == ptrNode->next->b || c == ptrNode->next->c){
            return false;
        } else {
            newNode = (Node *)malloc(sizeof(Node));
            newNode->a = a;
            newNode->b = b;
            newNode->c = c;
            newNode->next = ptrNode->next->next;
            ptrNode->next->next = newNode;
            return true;
        }
    }
    ptrNode->next = newNode = (Node *)malloc(sizeof(Node));
    newNode->a = a;
    newNode->b = b;
    newNode->c = c;
    newNode->next = NULL;
    return true;
}

int **threeSum(int num[], int n, int *returnSize) {
    int **ans = NULL;
    int i = 0, low = 0, high = n - 1;
    int tarVal = 0, twoSum = 0;
    Node ansNode, *ptrNode;
    ansNode.next = NULL;
    *returnSize = 0;
    qsort((void *)num, n, sizeof(int), compare);
    for(i = 0; i < n - 2; ++i) {
        low = i + 1;
        high = n - 1;
        tarVal = -num[i];
        while(low < high) {
            twoSum = num[low] + num[high];
            if(twoSum < tarVal)
                low++;
            else if(twoSum > tarVal)
                high--;
            else {
                if(insertNode(&ansNode, num[i], num[low], num[high])) {
                    (*returnSize)++;
                }
                while(low < high && num[low]  == num[low + 1])  low++;
                while(low < high && num[high] == num[high - 1]) high--;
                low++;
                high--;
            }
        }
    }
    ans = (int **) malloc(sizeof(int *) * (*returnSize));
    ptrNode = ansNode.next;
    i = 0;
    while(ptrNode) {
        ans[i] = (int *)malloc(sizeof(int) * 3);
        ans[i][0] = ptrNode->a;
        ans[i][1] = ptrNode->b;
        ans[i][2] = ptrNode->c;
        ptrNode = ptrNode->next;
        i++;
    }
    return ans;
}

int main() {
    int arrIn[] = {-1, 0, 1, 2, -1, -4};
    int ansNum = 0, i;
    int **ans = threeSum(arrIn, 6, &ansNum);
    for(i = 0; i < ansNum; i++) {
        printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
    }
    return 0;
}
