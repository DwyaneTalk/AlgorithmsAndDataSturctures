#include "../inc/SqList.h"


SqList::SqList(){
	elem = new SqListElemType[INIT_SIZE];
    if (!elem) {
        ferr << "�����ڴ�ʧ�ܣ�" << endl;
        exit(OVER);
    }
	listSize = INIT_SIZE;
	length = 0;
}

SqList::~SqList(){
	listSize = 0;
	length = 0;
	delete[] elem;
}

void SqList::Init() {
    delete[] elem;
    elem = new SqListElemType[INIT_SIZE];
    if (!elem) {
        ferr << "�����ڴ�ʧ�ܣ�" << endl;
        exit(OVER);
    }
    listSize = INIT_SIZE;
    length = 0;
}

void SqList::Destroy() {
    listSize = 0;
    length = 0;
    delete[] elem;
}

void SqList::clear(){
	length = 0;
}

bool SqList::isEmpty(){
	return !length;
}

int SqList::getLength(){
	return length;
}

SqListElemType SqList::getElem(int i){
	if (i < 0) {
        ferr << "���Ϸ��Ļ�ȡԪ��λ��" << endl;
		exit(ERROR);
	}
	return elem[i];
}

int SqList::insertElem(SqListElemType e, int i){
	if (i < 0 || i > length){
        ferr << "���Ϸ��Ĳ���Ԫ��λ��" << endl;
		exit(ERROR);
	}
	if (length >= listSize){
		elem = (SqListElemType*)realloc(elem, sizeof(SqListElemType)* (listSize + INCREMENT));
	}
	for (int p = length; p > i; p--){
		elem[p] = elem[p - 1];
	}
	elem[i] = e;
	return ++length;
}

SqListElemType SqList::deleleElem(int i){
	if (i < 0 || i >= length){
        ferr << "���Ϸ���ɾ��Ԫ��λ��" << endl;
		exit(ERROR);
	}
	SqListElemType delElem = elem[i];
	for (int p = i; i < length - 1; i++){
		elem[i] = elem[i + 1];
	}
	--length;
	return delElem;
}

SqListElemType SqList::replaceElem(SqListElemType e, int i) {
    if (i < 0 || i >= length) {
        ferr << "���Ϸ����滻Ԫ��λ��" << endl;
        exit(ERROR);
    }
    SqListElemType ans = elem[i];
    elem[i] = e;
    return ans;
}

void SqList::traverse(void(*visit)(SqListElemType& e)){
	for (int i = 0; i < length; i++){
		visit(elem[i]);
	}
}

void SqList::show() {
    cout << length << "��˳���Ԫ��Ϊ��";
    for (int i = 0; i < length; ++i) {
        cout << elem[i] << " ";
    }
    cout << endl;
}

void SqList::visit(QueueElemType &e) {
    e = e + 1;
}