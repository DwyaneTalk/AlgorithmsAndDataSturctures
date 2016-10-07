/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Merge Intervals 
 *             : https://leetcode.com/problems/merge-intervals/
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct Interval {
    int start;
    int end;
    Interval(int x, int y) : start(x), end(y) {}
};
typedef struct Interval Interval;


Interval *initInterval(int *start, int *end, int num) {
    if (!num)   return NULL;
    else {
        Interval *ans = (Interval *)malloc(sizeof(Interval)* num);
        int i;
        for (i = 0; i < num; ++i) {
            ans[i].start = start[i];
            ans[i].end = end[i];
        }
        return ans;
    }
}

int compare(const void *a, const void *b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}



Interval* merge(Interval* intervals, int intervalsSize, int* returnSize) {
    if (!intervals || !intervalsSize)   return NULL;
    Interval * ans = (Interval *)malloc(sizeof(Interval) * intervalsSize);
    qsort(intervals, intervalsSize, sizeof(Interval), compare);
    int i, start = intervals[0].start, end = intervals[0].end, cc = 0;
    for (i = 1; i < intervalsSize; ++i) {
        if (intervals[i].start <= end) {
            end = MAX(intervals[i].end, end);
        } else {
            ans[cc].start = start;
            ans[cc++].end = end;
            start = intervals[i].start;
            end = intervals[i].end;
        }
    }
    ans[cc].start = start;
    ans[cc++].end = end;
    *returnSize = cc;
    return ans;
}


int main() {
    int start[] = { 2, 4, 6, 8, 1};
    int end[] = { 3, 5, 7, 9, 10};
    Interval *intervals = initInterval(start, end, sizeof(start) / sizeof(int));
    int returnSize;
    Interval *ans = merge(intervals, sizeof(start) / sizeof(int), &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d\t%d\n", ans[i].start, ans[i].end);
    }
    system("pause");
    return 0;
}
