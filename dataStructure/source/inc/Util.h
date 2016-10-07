#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <fstream>
#include "stdlib.h"
#include <limits.h>
#include <algorithm>

#include "TypeDef.h"


using namespace std;

// global variable externs
extern ifstream fin;
extern ofstream fout;
extern ofstream ferr;

// global function statements

void globalInit();

void* renew(void* base, int count, int inc, int size);

UInt32 getMin(UInt32 *array, UInt32 nums, UInt32 *index);

void memShift(void *left, void *right, LR lr, UInt32 size);

#endif 