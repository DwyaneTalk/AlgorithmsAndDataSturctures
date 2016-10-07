#ifndef BMINUSTREE_H
#define BMINUSTREE_H

#include "Util.h"
#include<queue>

/*
B-树说明：m（m >= 3）阶的B-树是一种平衡的多路查找树，要么是孔数，要么满足如下条件
    1、树的每个结点最多有m颗子树
    2、树的根结点（非叶子结点时）最少有2颗子树
    3、除根之外，树的非终端结点最少有(m + 1) / 2颗子树
    4、树的叶子结点为空，而且所有的叶子结点都在同一层上
    5、所有的非终端结点应该包含如下信息：
        （n, C0, K1, C1,……,Cn, Kn）
        因此每个非终端结点，关键字n个，子树n+1个， n个关键字有序排列。

B+树说明：B+树和B-树一样是一种平衡的多路查找树，区别如下：
    1、所有的非终端结点包含如下信息：
        （n, K1, C1, ……, Kn, Cn）
        因此结点中关键字数目和子树的数目相等，所有关键字有序排列
    2、所有非终端结点中，每个关键字（Ki）是对应的子树(Ci)中所有关键字最大值
    3、所有非终端结点可以看成是终端结点的索引，非终端结点中的关键字会在其子树中再次出现

B*树说明：相对与B+树，B*树增加了非终端结点指向其右兄弟（如果存在）结点的指针
*/

#define m   3

typedef struct KeyInfo{
    // other information

} KeyInfo;

typedef struct Key {
    BTreeType value;
    KeyInfo*  info;
    Key(BTreeType value = 0, KeyInfo *info = NULL) {
        this->value = value;
        this->info = info;
    }
} Key; 

typedef struct BTreeNode {
    UInt32 key_num;
    BTreeNode*   parent;
    Key*     key[m + 1]; //key[0]不用
    BTreeNode*   child[m + 1];  //多出来一个空间，是在分裂结点之前的暂存空间
    BTreeNode(BTreeNode *parent = NULL) {
        this->key_num = 0;
        this->parent = parent;
        for (UInt32 i = 1; i <= m; ++i) {
            this->key[i] = NULL;
        }
        for (UInt32 i = 0; i <= m; ++i) {
            this->child[i] = NULL;
        }
    }
} BTreeNode;

typedef struct Location {
    BTreeNode*   node;
    UInt32     idx;
    bool    tag;
    Location(BTreeNode *node = NULL, int idx = 0, bool tag = false) {
        this->node = node;
        this->idx  = idx;
        this->tag  = tag;
    }
}Location;

class BMinusTree {
private:
    BTreeNode* root;
    UInt32 rank;
    Int32 searchInNode(BTreeNode *node, BTreeType key_value);
    void  insertInNode(Location *loc, Key* key, BTreeNode* child);
    Key*  splitNode(BTreeNode* node, Location* loc, BTreeNode* &new_node);
public:
    BMinusTree();
    ~BMinusTree();
    bool searchKey(BTreeType key_value, BTreeNode* &res_node, UInt32 &res_idx);
    void insertKey(Location* loc, Key* key);
    void deleteKey(Location* res);
};

#endif  //DMINUSTREE_H