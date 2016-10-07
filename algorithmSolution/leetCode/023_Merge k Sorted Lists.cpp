/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Merge k Sorted Lists
 *             : https://leetcode.com/problems/merge-k-sorted-lists/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
typedef struct ListNode ListNode;

ListNode *initList(int arr[], int num){
    if(num == 0)    return NULL;
    ListNode *l = new ListNode(arr[0]);
    ListNode *tmp = l;
    int i;
    for(i = 1; i < num; i++) {
        tmp->next = new ListNode(arr[i]);
        tmp = tmp->next;
    }
    return l;
}

void printfList(ListNode *l) {
    ListNode *ll = l;
    while(ll) {
        printf("%d  ", ll->val);
        ll = ll->next;
    }
    printf("\n");
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *ans = NULL;
    ListNode *p1 = l1, *p2 = l2, *ptr;
    if(!l1) return l2;
    if(!l2) return l1;
    if(p1->val < p2->val) {
        ans = ptr = p1;
        p1 = p1->next;
    } else{
        ans = ptr = p2;
        p2 = p2->next;
    }
    while(p1 && p2) {
        if(p1->val < p2->val) {
            ptr->next = p1;
            ptr = p1;
            p1 = p1->next;
        } else {
            ptr->next = p2;
            ptr = p2;
            p2 = p2->next;
        }
    }
    if(p1)  ptr->next = p1;
    else    ptr->next = p2;
    return ans;
}
//  ͨ�������ϲ��ķ�ʽ�����Ӷ�Ϊ(O(N*log(k)))��N�����ж���Ԫ�ظ���֮��
ListNode* solution1(ListNode** lists, int listsSize) {
    if(listsSize == 0)  return NULL;
    int i;
    while(listsSize > 1) {
        i =0;
        while(2 * i + 1  < listsSize) {
            lists[i] = mergeTwoLists(lists[2 * i], lists[2 * i + 1]);
            i++;
        }
        if(listsSize & 1){
            lists[i++] = lists[listsSize - 1];
        }
        listsSize = i;
    }
    return lists[0];
}

// С����
typedef struct Heap {
    int size;
    int max_size;
    ListNode **elem;
    Heap()  : size(0), max_size(0), elem(NULL)   {}
} Heap;

void initHeap(Heap *heap, int size) {
    heap->size = 0;
    heap->max_size = size;
    // ����ռ䣬elem[0]����ţ�����Ϊ�˱�֤elem[i]�������ӽڵ�Ϊelem[2*i]��elem[2*i+1]
    heap->elem = (ListNode **)malloc(sizeof(ListNode *) * (size + 1));
}

void insertElem(Heap *heap, ListNode *elem) {
    if(!heap || !heap->elem)    return;
    if(heap->size == heap->max_size)    return;
    int i = ++(heap->size);
    while(i > 1 && heap->elem[i / 2]->val > elem->val){
        heap->elem[i] = heap->elem[i / 2];
        i = i / 2;
    }
    heap->elem[i] = elem;
}

ListNode *removeElem(Heap *heap) {
    if(!heap || !heap->elem)    return NULL;
    if(!heap->size) return NULL;
    ListNode *ans = heap->elem[1];
    ListNode *lastElem = heap->elem[(heap->size)--];
    int i = 1, child = 2;
    while(child <= heap->size) {//��ǰ��Ҫ���Ľڵ����ӽڵ�
        if(child < heap->size && heap->elem[child]->val > heap->elem[child + 1]->val)
            child++;        //��Ҫ�¸������ҽ��
        if(lastElem->val < heap->elem[child]->val)
            break;          //���һ��Ԫ�ر���Ҫ�ϸ���Ԫ�ػ���������Ԫ�ط���iλ��
        heap->elem[i] = heap->elem[child];
        i = child;
        child = i << 1;
    }
    heap->elem[i] = lastElem;//�����һ���ŵ����ʵ����λ��
    return ans;
}

ListNode* solution2(ListNode** lists, int listsSize) {
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    ListNode *ans = NULL, *ptr;
    initHeap(heap, listsSize);
    int i;
    for(i = 0; i < listsSize; ++i) {
        if(lists[i])
            insertElem(heap, lists[i]);
    }
    ans = ptr = removeElem(heap);
    while(ptr) {
        if(ptr->next)
            insertElem(heap, ptr->next);
        ptr->next = removeElem(heap);
        ptr = ptr->next;
    }
    free(heap);
    return ans;
}

ListNode* mergeKLists(ListNode** lists, int listsSize) {
    if(false)
        return solution1(lists, listsSize);
    else
        return solution2(lists, listsSize);
}

int main() {
    int a0[] = {};
    int a1[] = {};
    int a2[] = {2, 7, 7, 18};
    int a3[] = {10, 12, 23, 32};
    int a4[] = {7, 14, 20, 22};
    int a5[] = {6, 12, 13, 42};
    int a6[] = {12, 18, 23, 26};
    ListNode *la[7];
    la[0] = initList(a0, sizeof(a0) / sizeof(int));
    la[1] = initList(a1, sizeof(a1) / sizeof(int));
    la[2] = initList(a2, sizeof(a2) / sizeof(int));
    la[3] = initList(a3, sizeof(a3) / sizeof(int));
    la[4] = initList(a4, sizeof(a4) / sizeof(int));
    la[5] = initList(a5, sizeof(a5) / sizeof(int));
    la[6] = initList(a6, sizeof(a6) / sizeof(int));
    ListNode *ans= mergeKLists(la, 2);
    printfList(ans);
    return 0;
}
