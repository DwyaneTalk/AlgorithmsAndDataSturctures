#ifndef SQLIST_H
#define SQLIST_H

#include "Util.h"

class SqList{
private:
	int			length;//列表长度
	int			listSize;//当前最大空前
	SqListElemType *	elem;
public:
	SqList();
	~SqList();
	void Init();
	void Destroy();
	void clear();
	bool isEmpty();
	int getLength();
	SqListElemType getElem(int i);//获取从0开始的第i个元素
	int insertElem(SqListElemType e, int i);//在从0开始的i位置处插入元素e
	SqListElemType deleleElem(int i);
    SqListElemType replaceElem(SqListElemType e, int i);
	void traverse(void (*visit)(SqListElemType& e));
	void show();
    void static visit(SqListElemType &e);
};

#endif