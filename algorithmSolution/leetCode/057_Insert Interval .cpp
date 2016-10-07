/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Insert Interval  
 *             : https://leetcode.com/problems/insert-interval/
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

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

Interval* insert(Interval* intervals, int intervalsSize, Interval newInterval, int* returnSize) {
    if (!intervals || !intervalsSize) {
        Interval * ans = (Interval *)malloc(sizeof(Interval));
        ans->start = newInterval.start;
        ans->end = newInterval.end;
        *returnSize = 1;
        return ans;
    }
    Interval * ans = (Interval *)malloc(sizeof(Interval)* (intervalsSize + 1));
    int i = 0, cc = 0, start, end;
    while (i < intervalsSize && intervals[i].end < newInterval.start) {
        ans[cc].start = intervals[i].start;
        ans[cc++].end = intervals[i++].end;
    }
    if (i == intervalsSize) {
        ans[cc].start = newInterval.start;
        ans[cc++].end = newInterval.end;
    } else if (intervals[i].start > newInterval.end) {
        ans[cc].start = newInterval.start;
        ans[cc++].end = newInterval.end;
        while (i < intervalsSize) {
            ans[cc].start = intervals[i].start;
            ans[cc++].end = intervals[i++].end;
        }
    } else {
        start = MIN(newInterval.start, intervals[i].start);
        end = MAX(newInterval.end, intervals[i].end);
        ++i;
        while (i < intervalsSize && end >= intervals[i].start) {
            ++i;
        }
        ans[cc].start = start;
        ans[cc++].end = MAX(intervals[i - 1].end, end);
        while (i < intervalsSize) {
            ans[cc].start = intervals[i].start;
            ans[cc++].end = intervals[i++].end;
        }
    }
    *returnSize = cc;
    return ans;
}

int main() {
    int start[] = { 1};
    int end[] = {5};
    Interval *intervals = initInterval(start, end, sizeof(start) / sizeof(int));
    Interval newInterval(0, 0);
    int returnSize;
    qsort(intervals, sizeof(start) / sizeof(int), sizeof(Interval), compare);
    Interval *ans = insert(intervals, sizeof(start) / sizeof(int), newInterval, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d\t%d\n", ans[i].start, ans[i].end);
    }
    system("pause");
    return 0;
}
