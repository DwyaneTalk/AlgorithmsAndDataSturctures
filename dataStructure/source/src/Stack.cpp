#include "../inc/Stack.h"

Stack::Stack() {
    base = new StackElemType[INIT_SIZE];
    if (base) {
        top = 0;
        max_size = INIT_SIZE;
    } else {
        ferr << "�����ڴ�ʧ��" << endl;
        exit(OVER);
    }
}

Stack::~Stack() {
    delete base;
    top = 0;
    max_size = 0;
}

void Stack::init() {
    top = 0;
}

bool Stack::isEmpty() {
    return !top;
}

int Stack::getLength() {
    return top;
}

StackElemType Stack::getTop() {
    if (top <= 0) {
        ferr << "ջ�գ��޷���ȡջ��Ԫ��" << endl;
        exit(ERROR);
    }
    return base[top - 1];
}

StackElemType Stack::pop() {
    if (top <= 0) {
        ferr << "ջ�գ��޷���ջ" << endl;
        exit(ERROR);
    }
    return base[--top];
}

void Stack::push(StackElemType e) {
    if (top >= max_size) {
        StackElemType *newBase = new StackElemType[max_size + INCREMENT];
        if (!newBase) {
            ferr << "�����ڴ�ʧ��" << endl;
            exit(OVER);
        }
        memcpy(newBase, base, sizeof(StackElemType)* max_size);
        delete base;
        base = newBase;
        max_size += INCREMENT;
    }
    base[top++] = e;
}

void Stack::traverse(void(*visit)(StackElemType &e)) {
    for (int i = 0; i < top; ++i) {
        visit(base[i]);
    }
}

void Stack::show(){
    cout << "ջ��" << top << "��Ԫ�طֱ�Ϊ��";
    for (int i = 0; i < top; ++i) {
        cout << " " << base[i];
    }
    cout << endl;
}

void Stack::visit(StackElemType &e) {
    e = e + 1;
}