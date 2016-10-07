#ifndef TRIETREE_H
#define TRIETREE_H

#include "Util.h"
#include<queue>

/*
说明：
    键树（数字查找数）是一颗度>=2的树，树的每个非叶子结点表示关键字的一个字符；
    每个叶结点表示从根到叶子结点路径上所有非叶结点所表示字符组成的关键字

存储：
    键树以树的兄弟链表存储，则称为双链树
    键树以树的多重链表存储，则表示Trie树
*/


typedef struct TrieNode {
    TrieNodeType kind;
    UInt32       level;
    TrieNode*    parent;
    union {
        struct BhNode{
            UInt32      num;
            TrieNode*   ptr[27]; //以此表示0、A~Z（0表示结束）
        } bh;
        struct {
            UInt32      size;
            TrieType*   key;
            Record*     info;
        } lf;
    };
}TrieNode;

class TrieTree {
private:
    TrieNode* root;
    UInt32      charToInt(TrieType symbol);
    TrieType    intToChar(UInt32 index);
public:
    TrieTree();
    ~TrieTree();
    TrieNode* searchTrie(TrieType* key);
    void insertTrie(TrieNode* node, TrieType* tmp_key, TrieType* key);
    void deleteTrie(TrieNode* node, TrieType* key);
};

#endif  //TRIETREE_H