#ifndef HEAP_H
#define HEAP_H

#include "Util.h"
#include "Sort.h"

class Heap {
private:
    SortElem* data;
    UInt32    max_num;  //数据表的大小
    UInt32    num;      //堆结构的大小
    SortElem* heapTop();
    void      heapDownAdjust(UInt32 top, UInt32 num, Int32(*compare)(SortElem* data_a, SortElem* data_b));
public:
    Heap();
    ~Heap();
    SortElem* getData(UInt32 &num);
    void      initData(SortElem* data, UInt32 num);
    void      heapAdjust(Int32(*compare)(SortElem* data_a, SortElem* data_b));
    void      heapInsert(SortElem* elem, Int32(*compare)(SortElem* data_a, SortElem* data_b));
    void      heapSort(Int32(*compare)(SortElem* data_a, SortElem* data_b));
    void      createSort(SortElem* data, UInt32 num, Int32(*compare)(SortElem* data_a, SortElem* data_b));
};



#endif  //HEAP_H