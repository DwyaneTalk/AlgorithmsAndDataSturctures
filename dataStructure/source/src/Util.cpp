#include "../inc/Util.h"
//global variables
ifstream fin;
ofstream fout;
ofstream ferr;

// global functions
void globalInit() {
    fin.open("input.txt");
    fout.open("output.txt");
    ferr.open("error.txt");
    ferr << "runtime error log start¡­¡­" << endl;
}

void* renew(void* base, int count, int inc, int size) {
    void* new_base;
    if (new_base = new UInt8[(count + inc) * size]) {
        memcpy(new_base, base, count * size);
        return new_base;
    } else {
        ferr << "ÉêÇëÄÚ´æÊ§°Ü£¡" << endl;
        exit(OVER);
    }
}

UInt32 getMin(UInt32 *array, UInt32 nums, UInt32 *index) {
    UInt32 min_value = *array;
    for (UInt32 i = 1; i < nums; ++i) {
        if (*(array + i) < min_value) {
            min_value = *(array + i);
            *(index) = i;
        }
    }
    return min_value;
}

void memShift(void *left, void *right, LR lr, UInt32 size) {
    UInt8 delta = (UInt8 *)right - (UInt8*)left;
    UInt8* end = (UInt8*)left + size - delta;
    if (!delta) return;
    if (lr == LEFT) {
        UInt8* base = (UInt8*)left;
        while (base <= end) {
            memcpy(base, base + delta, delta);
            base += delta;
        }
        memcpy(base, base + delta, (UInt8*)left + size - base);
    } else {
        UInt8* base = (UInt8*)right + size - delta;
        while (base >= right) {
            memcpy(base, base - delta, delta);
            base -= delta;
        }
        memcpy(right, left, base + delta - (UInt8*)right);
    }
}
