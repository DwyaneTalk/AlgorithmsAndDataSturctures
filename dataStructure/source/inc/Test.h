#ifndef TEST_H
#define TEST_H

#include<time.h>

#include "SqList.h"
#include "LinkList.h"
#include "Stack.h"
#include "Queue.h"
#include "BinaryTree.h"
#include "Tree.h"
#include "DGraph.h"
#include "UDGraph.h"
#include "StaticSrhTable.h"
#include "DynamicSrhTable.h"
#include "BMinusTree.h"
#include "TrieTree.h"
#include "Hash.h"
#include "Heap.h"
#include "Sort.h"

class Test{
private:
public:
    void testSqList();
    void testLinkList();
    void testStack();
    void testQueue();
    void testBinaryTree();
    void testTree();
    void testDGraph();
    void testUDGraph();
    void testDGraphApp();
    void testUDGraphApp();
    void testStaSrhTable();
    void testDynSrhTable();
    void testBMinusTree();
    void testTrieTree();
    void testHash();
    void testHeap();
    void testSort();
};

#endif