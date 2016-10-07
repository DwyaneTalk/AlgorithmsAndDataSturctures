#ifndef DYNAMICSRHTABLE_H
#define DYNAMICSRHTABLE_H

#include "Util.h"
#include "BinaryTree.h"
#include<stack>

class DynamicSrhTable {
private:
    SearchType *data;
    UInt32      max_size;
    UInt32      size;
    BinaryTree *bin_sort_tree;
    BinaryTree *bal_bin_tree;
    UInt32 newElem(SearchType key);
    void delElem(UInt32 index);
    Int32 bstSearch(SearchType key, BiNode *&node);
    BiNode* bstInsert(BiNode *node, UInt32 index);
    void bstDelete(BiNode *node, UInt32 index);
    Int32 bbtSearch(SearchType key);
    BiNode* leftBlance(BiNode *node);
    BiNode* rightBlance(BiNode *node);
    BiNode* leftRotate(BiNode *node);
    BiNode* rightRotate(BiNode *node);
public:
    DynamicSrhTable();
    ~DynamicSrhTable();
    void init();
    Int32 search(DynFindType f_type, SearchType key);
    void deleteData(DynFindType f_type, SearchType key);
    void traverse(DynFindType f_type, void(*visit)(SearchType &e));
    void static visit(SearchType &e);
};

#endif  // DYNAMICSRHTABLE_H