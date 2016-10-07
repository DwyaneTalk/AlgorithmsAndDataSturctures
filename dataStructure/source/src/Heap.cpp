#include "../inc/Heap.h"

Heap::Heap() {
    data = NULL;
    max_num = NULL;
    num = 0;
}

Heap::~Heap() {
    data = NULL;
    max_num = NULL;
    num = 0;
}

SortElem* Heap::heapTop() {
    if (!data) 
        cout << "堆为空，请初始化堆数据" << endl;
    return data;
}

void Heap::heapDownAdjust(UInt32 top, UInt32 num, Int32(*compare)(SortElem* data_a, SortElem* data_b)) {
    SortElem tmp_data(data[top].key, data[top].info);
    UInt32 left = top * 2;
    while (left <= num) {
        if (left == num || compare(data + left, data + left + 1) > 0) {
            if (compare(&tmp_data, data + left) >= 0) {
                Sort::copy(data + top, &tmp_data);
                return;
            } else {
                Sort::copy(data + top, data + left);
                top = left;
                left = top * 2;
            }
        } else {
            if (compare(&tmp_data, data + left + 1) >= 0) {
                Sort::copy(data + top, &tmp_data);
                return;
            } else {
                Sort::copy(data + top, data + left + 1);
                top = left + 1;
                left = top * 2;
            }
        }
    }
    Sort::copy(data + top, &tmp_data);
}


SortElem* Heap::getData(UInt32 &num) {
    num = this->max_num;
    return data;
}

void Heap::initData(SortElem* data, UInt32 num) {
    this->max_num = num;
    this->data = data;
    this->num = 0;
}

void Heap::heapAdjust(Int32(*compare)(SortElem* data_a, SortElem* data_b)) {
    if (data) {
        for (UInt32 i = max_num / 2; i >= 1; --i) {
            heapDownAdjust(i, max_num, compare);
        }
        num = max_num;
    } else {
        cout << "堆为空，请初始化堆数据" << endl;
    }
}

void Heap::heapSort( Int32(*compare)(SortElem* data_a, SortElem* data_b)) {
    SortElem tmp_data, *tmp_ptr = &tmp_data;
    for (UInt32 j = num; j > 1;) {
        Sort::exchange(data + 1, data + j, tmp_ptr);
        heapDownAdjust(1, --j, compare);
    }
}

void Heap::createSort(SortElem* data, UInt32 num, Int32(*compare)(SortElem* data_a, SortElem* data_b)) {
    initData(data, num);
    heapAdjust(compare);
    heapSort(compare);
}

void Heap::heapInsert(SortElem* elem, Int32(*compare)(SortElem* data_a, SortElem* data_b)) {
    if (num == max_num) {
        cout << "堆数据空间已满，无法继续插入" << endl;
    } else {
        data[++num].key = elem->key;
        data[num].info = elem->info;
        UInt32 curr = num, top = curr / 2;
        SortElem tmp_data, *tmp_ptr = &tmp_data;
        while (top >= 1) {
            if (compare(data + curr, data + top) > 0) {
                Sort::exchange(data + curr, data + top, tmp_ptr);
                curr = top;
                top /= 2;
            } else {
                break;
            }
        }
    }
}