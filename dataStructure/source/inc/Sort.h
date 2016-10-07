#ifndef SORT_H
#define SORT_H

#include "Util.h"

/*说明：
算法      平均时间    最坏时间    辅助存储    稳定性
直接插入  O(n^2)      O(n^2)      O(1)        稳定
简单选择  O(n^2)      O(n^2)      O(1)        稳定
冒泡      O(n^2)      O(n^2)      O(1)        稳定
希尔      O(n^m)      O(n^2)      O(1)        不稳定
快排      O(nlog(n))  O(n^2)      O(log(n))   不稳定
归并      O(nlog(n))  O(nlog(n))  O(n)        稳定
堆        O(nlog(n))  O(nlog(n))  O(1)        不稳定

说明：
    1、希尔排序中1<m<2，m的值取决于希尔排序中的增量选择
    2、当排序规模非常大的时候，测试各种算法时间性能如下：
        快排 > 归并 ~= 堆 > 希尔 >直接插入 ~= 简单选择 >冒泡
        ~=：表示约等于
*/

typedef struct SortElem{
    SortKeyType key;
    Record*     info;
    SortElem(SortKeyType key = 0, Record* info = NULL) {
        this->key = key;
        this->info = info;
    }
} SortElem;

class Sort {
private:
    SortElem *data;
    UInt32  num;
    UInt32  selectMin(SortElem* data, UInt32 num, Int32(*compare)(SortElem* data_a, SortElem* data_b));
    void    shellInsert(SortElem* data, UInt32 num, UInt32 inc, Int32(*compare)(SortElem* data_a, SortElem* data_b));
    UInt32  partition(SortElem* data, UInt32 lo, UInt32 hi, Int32(*compare)(SortElem* data_a, SortElem* data_b));
    void    mSort(SortElem* data, UInt32 num, SortElem* tmp_data, Int32(*compare)(SortElem* data_a, SortElem* data_b));
    void    merge(SortElem* data, UInt32 num1, UInt32 num2, SortElem* tmp_data, Int32(*compare)(SortElem* data_a, SortElem* data_b));
public:
    Sort();
    ~Sort();
    void static copy(SortElem* dst, SortElem* src);
    void static exchange(SortElem* data_a, SortElem* data_b, SortElem* tmp_data);
    SortElem* createRandData(UInt32 num);
    void    insertSort(SortElem* data, UInt32 num, Int32(*compare)(SortElem* data_a, SortElem* data_b));
    void    selectSort(SortElem* data, UInt32 num, Int32(*compare)(SortElem* data_a, SortElem* data_b));
    void    bubbleSort(SortElem* data, UInt32 num, Int32(*compare)(SortElem* data_a, SortElem* data_b));
    void    shellSort(SortElem* data, UInt32 num, Int32(*compare)(SortElem* data_a, SortElem* data_b));
    void    quickSort(SortElem* data, UInt32 num, Int32(*compare)(SortElem* data_a, SortElem* data_b));
    void    mergeSort(SortElem* data, UInt32 num, Int32(*compare)(SortElem* data_a, SortElem* data_b));
    void    heapSort(SortElem* data, UInt32 num, Int32(*compare)(SortElem* data_a, SortElem* data_b));
};

Int32 compare_asc(SortElem* data_a, SortElem* data_b);

Int32 compare_des(SortElem* data_a, SortElem* data_b);

#endif  //SORT_H