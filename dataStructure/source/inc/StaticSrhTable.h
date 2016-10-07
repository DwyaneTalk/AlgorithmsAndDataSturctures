#ifndef STATICSRHTABLE_H
#define STATICSRHTABLE_H
#include "Util.h"
#include "BinaryTree.h"
#include<algorithm>

typedef struct IdxItem {
    SearchType  key;
    UInt32      start;
    UInt32      end;
} IdxItem;

typedef struct Index{
    IdxItem     *items;
    UInt32      nums;
    Index(UInt32 nums = 0) {
        this->nums = nums;
    }
} Index;

class StaticSrhTable {
private:
    SearchType *data;
    UInt32      size;
    UInt32     *weight;
    SearchType *seq_data;
    BinaryTree *sta_srh_tree;
    Index      idx_table;
    Int32 seqSearch(SearchType key);
    Int32 binSearch(SearchType key);
    Int32 fibSearch(SearchType key);
    Int32 intSearch(SearchType key);
    Int32 strSearch(SearchType key);
    Int32 idxSearch(SearchType key);
    void  sortData();
    void  initIdx();
    void  initTree();
    BiNode* createTree(UInt32 *sw, SearchType *seq_data, UInt32 low, UInt32 hig);
public:
    StaticSrhTable();
    ~StaticSrhTable();
    Int32 search(StaFindType f_type, SearchType key);
    void traverse(void(*visit) (SearchType &e));
    void static visit(SearchType &e);
};

#endif  //STATICSRHTABLE_H