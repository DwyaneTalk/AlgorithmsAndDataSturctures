#include "../inc/Sort.h"
#include "../inc/Heap.h"

Sort::Sort() {
    num = 0;
    data = NULL;
}

Sort::~Sort() {
    delete data;
    data = NULL;
    num = 0;
}

SortElem* Sort::createRandData(UInt32 num) {
    for (UInt32 i = 1; i <= this->num; ++i) {
        if (data[i].info)
            delete data[i].info;
    }
    delete data;

    this->num = num;
    if (data = new SortElem[num + 1]) {
        srand((int)time_t());
        for (UInt32 i = 1; i <= num; ++i) {
            data[i].key = rand();
            data[i].info = NULL;
        }
        return data;
    } else {
        ferr << "申请内存失败" << endl;
        exit(OVER);
    }
}

void Sort::copy(SortElem* dst, SortElem* src) {
    dst->key = src->key;
    dst->info = src->info;
}

void Sort::exchange(SortElem* data_a, SortElem* data_b , SortElem* tmp_data) {
    copy(tmp_data, data_a);
    copy(data_a, data_b);
    copy(data_b, tmp_data);
}

UInt32 Sort::selectMin(SortElem* data, UInt32 num, Int32(*compare)(SortElem* data_a, SortElem* data_b)) {
    UInt32 index = 0;
    SortElem min_data(data->key, data->info), *min_ptr = &min_data;
    for (UInt32 i = 1; i < num; ++i) {
        if (compare(data + i, min_ptr) < 0) {
            copy(min_ptr, data + i);
            index = i;
        }
    }
    return index;
}

void Sort::shellInsert(SortElem* data, UInt32 num, UInt32 inc, Int32(*compare)(SortElem* data_a, SortElem* data_b)) {
    for (UInt32 i = inc + 1; i <= num; ++i) {
        copy(data, data + i);
        Int32 j = i - inc;
        for (; j > 0 && compare(data, data + j) < 0; j -= inc) {
            copy(data + j + inc, data + j);
        }
        if (j + inc != i)
            copy(data + j + inc, data);
    }
}

UInt32 Sort::partition(SortElem* data, UInt32 lo, UInt32 hi, Int32(*compare)(SortElem* data_a, SortElem* data_b)) {
    SortElem target(data[lo].key, data[lo].info), *tar_ptr = &target;
    while (lo < hi) {
        while (lo < hi && compare(data + hi, tar_ptr) >= 0) --hi;
        copy(data + lo, data + hi);
        while (lo < hi && compare(data + lo, tar_ptr) <= 0) ++lo;
        copy(data + hi, data + lo);
    }
    copy(data + lo, tar_ptr);
    return lo;
}

void Sort::mSort(SortElem* data, UInt32 num, SortElem* tmp_data, Int32(*compare)(SortElem* data_a, SortElem* data_b)) {
    if (num > 1) {
        UInt32 mid = num / 2;
        mSort(data, mid, tmp_data, compare);
        mSort(data + mid, num - mid, tmp_data + mid, compare);
        merge(data, mid, num, tmp_data, compare);
        memcpy(data + 1, tmp_data + 1, sizeof(SortElem)* num);
    }
}

void Sort::merge(SortElem* data, UInt32 num1, UInt32 num2, SortElem* tmp_data, Int32(*compare)(SortElem* data_a, SortElem* data_b)) {
    //合并data[1……num1]和data[num1 + 1, num2]到tmp_data[1……num2]
    UInt32 i, j, k;
    for (i = 1, j = num1 + 1, k = 1; i <= num1 && j <= num2 ; ++k) {
        if (compare(data + i, data + j) <= 0)   copy(tmp_data + k, data + i++);
        else copy(tmp_data + k, data + j++);
    }
    if (i <= num1) memcpy(tmp_data + k, data + i, sizeof(SortElem)* (num1 - i + 1));
    if (j <= num2) memcpy(tmp_data + k, data + j, sizeof(SortElem)* (num2 - j + 1));
}


void Sort::insertSort(SortElem* data, UInt32 num, Int32(*compare)(SortElem* data_a, SortElem* data_b)) {
    for (UInt32 i = 2; i <= num; ++i) {
        copy(data, data + i);
        UInt32 j;
        for (j = i - 1; j >= 1 && compare(data, data + j) < 0; --j) {
            copy(data + j + 1, data + j);
        }
        if (j + 1 != i)
            copy(data + j + 1, data);
    }
}

void Sort::selectSort(SortElem* data, UInt32 num, Int32(*compare)(SortElem* data_a, SortElem* data_b)) {
    for (UInt32 i = 1; i < num; ++i) {
        UInt32 j = selectMin(data + i, num - i + 1, compare) + i;
        if (i != j) exchange(data + i, data + j, data);
    }
}

void Sort::bubbleSort(SortElem* data, UInt32 num, Int32(*compare)(SortElem* data_a, SortElem* data_b)) {
    Bool bubble = true;
    for (UInt32 i = 1; i < num && bubble; ++i) {
        bubble = false;
        for (UInt32 j = 1; j <= num - i; ++j) {
            if (compare(data + j, data + j + 1) > 0) {
                bubble = true;
                exchange(data + j, data + j + 1, data);
            }
        }
    }
}

void Sort::shellSort(SortElem* data, UInt32 num, Int32(*compare)(SortElem* data_a, SortElem* data_b)) {
    UInt32 shell_para = UInt32(log10(num + 1) / log10(2));
    UInt32 inc;
    for (UInt32 k = 1; k <= shell_para; ++k) {
        inc = (UInt32)pow(2.0, double(shell_para - k + 1)) - 1;
        shellInsert(data, num, inc, compare);
    }
}

void Sort::quickSort(SortElem* data, UInt32 num, Int32(*compare)(SortElem* data_a, SortElem* data_b)) {
    if (num > 1) {
        UInt32 mid = partition(data, 1, num, compare);
        quickSort(data, mid - 1, compare);
        quickSort(data + mid, num - mid, compare);
    }
}

void Sort::mergeSort(SortElem* data, UInt32 num, Int32(*compare)(SortElem* data_a, SortElem* data_b)) {
    if (num > 1) {
        SortElem* tmp_data = new SortElem[num + 1];
        mSort(data, num, tmp_data, compare);
        delete tmp_data;
    }
}

void Sort::heapSort(SortElem* data, UInt32 num, Int32(*compare)(SortElem* data_a, SortElem* data_b)) {
    Heap heap;
    heap.createSort(data, num, compare);
    data = heap.getData(num);
}


Int32 compare_asc(SortElem* data_a, SortElem* data_b) {
    return data_a->key - data_b->key;
}

Int32 compare_des(SortElem* data_a, SortElem* data_b) {
    return data_b->key - data_a->key;
}

