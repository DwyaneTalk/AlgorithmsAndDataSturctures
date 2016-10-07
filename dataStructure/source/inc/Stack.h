#ifndef STACK_H
#define STACK_H

#include "Util.h"

class Stack {
private:
    StackElemType *base;
    int top;
    int max_size;
public:
    Stack();
    ~Stack();
    void init();
    bool isEmpty();
    int getLength();
    StackElemType getTop();
    StackElemType pop();
    void push(StackElemType e);
    void traverse(void(*visit)(StackElemType &e));
    void show();
    void static visit(StackElemType &e);
};
#endif