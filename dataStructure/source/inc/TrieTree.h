#ifndef TRIETREE_H
#define TRIETREE_H

#include "Util.h"
#include<queue>

/*
˵����
    ���������ֲ���������һ�Ŷ�>=2����������ÿ����Ҷ�ӽ���ʾ�ؼ��ֵ�һ���ַ���
    ÿ��Ҷ����ʾ�Ӹ���Ҷ�ӽ��·�������з�Ҷ�������ʾ�ַ���ɵĹؼ���

�洢��
    �����������ֵ�����洢�����Ϊ˫����
    ���������Ķ�������洢�����ʾTrie��
*/


typedef struct TrieNode {
    TrieNodeType kind;
    UInt32       level;
    TrieNode*    parent;
    union {
        struct BhNode{
            UInt32      num;
            TrieNode*   ptr[27]; //�Դ˱�ʾ0��A~Z��0��ʾ������
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