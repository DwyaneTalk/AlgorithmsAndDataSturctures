#ifndef QUEUE_H
#define QUEUE_H

#include "Util.h"


typedef struct QueueNode{
    QueueElemType data;
    struct QueueNode* next;
} QueueNode;

class Queue {
private:
    QueueNode *head;
    QueueNode *tail;
    int size;
public:
    Queue();
    ~Queue();
    void init();
    bool isEmpty();
    int getLength();
    QueueElemType getHead();
    QueueElemType deQueue();
    void enQueue(QueueElemType e);
    void traverse(void(*visit)(QueueElemType &e));
    void show();
    void static visit(QueueElemType &e);
};

#endif