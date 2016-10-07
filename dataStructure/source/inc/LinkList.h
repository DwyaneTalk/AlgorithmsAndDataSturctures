#ifndef LINKLIST_H
#define LINKLIST_H

#include "Util.h"



typedef struct LinkNode {
    LinkListElemType data;
    struct LinkNode *next;
} LinkNode;

class LinkList {
private:
    LinkNode *head;
    LinkNode *tail;
    int size;
public:
    LinkList();
    ~LinkList();
    void init();
    bool isEmpty();
    int getLength();
    int getIndex(LinkListElemType e);
    LinkListElemType getElem(int i);
    void insertHeadElem(LinkListElemType e);
    void insertTailElem(LinkListElemType e);
    void insertElem(LinkListElemType e, int i);
    LinkListElemType deleteHeadElem();
    LinkListElemType deleteTailElem();
    LinkListElemType deleteElem(int i);
    LinkListElemType replaceElem(LinkListElemType e, int i);
    void traverse(void(*visit) (LinkListElemType &e));
    void show();
    void static visit(LinkListElemType &e);
};

#endif