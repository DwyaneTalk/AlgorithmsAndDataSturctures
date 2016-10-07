#ifndef SQLIST_H
#define SQLIST_H

#include "Util.h"

class SqList{
private:
	int			length;//�б���
	int			listSize;//��ǰ����ǰ
	SqListElemType *	elem;
public:
	SqList();
	~SqList();
	void Init();
	void Destroy();
	void clear();
	bool isEmpty();
	int getLength();
	SqListElemType getElem(int i);//��ȡ��0��ʼ�ĵ�i��Ԫ��
	int insertElem(SqListElemType e, int i);//�ڴ�0��ʼ��iλ�ô�����Ԫ��e
	SqListElemType deleleElem(int i);
    SqListElemType replaceElem(SqListElemType e, int i);
	void traverse(void (*visit)(SqListElemType& e));
	void show();
    void static visit(SqListElemType &e);
};

#endif