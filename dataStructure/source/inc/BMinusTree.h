#ifndef BMINUSTREE_H
#define BMINUSTREE_H

#include "Util.h"
#include<queue>

/*
B-��˵����m��m >= 3���׵�B-����һ��ƽ��Ķ�·��������Ҫô�ǿ�����Ҫô������������
    1������ÿ����������m������
    2�����ĸ���㣨��Ҷ�ӽ��ʱ��������2������
    3������֮�⣬���ķ��ն˽��������(m + 1) / 2������
    4������Ҷ�ӽ��Ϊ�գ��������е�Ҷ�ӽ�㶼��ͬһ����
    5�����еķ��ն˽��Ӧ�ð���������Ϣ��
        ��n, C0, K1, C1,����,Cn, Kn��
        ���ÿ�����ն˽�㣬�ؼ���n��������n+1���� n���ؼ����������С�

B+��˵����B+����B-��һ����һ��ƽ��Ķ�·���������������£�
    1�����еķ��ն˽�����������Ϣ��
        ��n, K1, C1, ����, Kn, Cn��
        ��˽���йؼ�����Ŀ����������Ŀ��ȣ����йؼ�����������
    2�����з��ն˽���У�ÿ���ؼ��֣�Ki���Ƕ�Ӧ������(Ci)�����йؼ������ֵ
    3�����з��ն˽����Կ������ն˽������������ն˽���еĹؼ��ֻ������������ٴγ���

B*��˵���������B+����B*�������˷��ն˽��ָ�������ֵܣ�������ڣ�����ָ��
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
    Key*     key[m + 1]; //key[0]����
    BTreeNode*   child[m + 1];  //�����һ���ռ䣬���ڷ��ѽ��֮ǰ���ݴ�ռ�
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