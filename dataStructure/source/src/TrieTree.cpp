#include "../inc/TrieTree.h"


TrieTree::TrieTree() {
    root = new TrieNode;
    root->kind = BRANCH;
    root->level = 1;
    root->parent = NULL;
    root->bh.num = 0;
    for (UInt32 i = 0; i < 27; ++i)
        root->bh.ptr[i] = NULL;
}

TrieTree::~TrieTree() {
    queue<TrieNode*> tr_queue;
    TrieNode* node;
    if (root)   tr_queue.push(root);
    while (!tr_queue.empty()) {
        node = tr_queue.front();
        tr_queue.pop();
        if (node->kind == BRANCH) {
            for (UInt32 i = 0; i < 27; ++i) {
                if (node->bh.ptr[i]) {
                    tr_queue.push(node->bh.ptr[i]);
                }
            }
        } else {
            if(node->lf.key)  delete node->lf.key;
            if(node->lf.info) delete node->lf.info;
        }
        delete node;
    }
}

UInt32 TrieTree::charToInt(TrieType symbol) {
    if (symbol == '\0')  return 0;
    else if (symbol >= 'A' && symbol <= 'Z')    return symbol - 'A' + 1;
    else {
        ferr << "非法字符，只能是A~Z" << endl;
        exit(ERROR);
    }
}

TrieType TrieTree::intToChar(UInt32 index) {
    if (index == 0) return '\0';
    else if (index >= 1 && index <= 26) return TrieType('A' + index - 1);
    else {
        ferr << "非法字符索引，只能是0~26" << endl;
        exit(ERROR);
    }
}

TrieNode* TrieTree::searchTrie(TrieType* key) {
    TrieNode *node = root, *parent = NULL;
    UInt32 index;
    TrieType *tmp_key = key;
    while (node && node->kind == BRANCH) {
        index = charToInt(*tmp_key++);
        parent = node;
        node = node->bh.ptr[index];
    }
    if (node) {
        if (!strcmp(node->lf.key + node->level - 2, tmp_key - 1)) {
            return node;
        } else {
            insertTrie(parent, tmp_key - 1, key);
            return parent;
        }
    } else {
        insertTrie(parent, tmp_key - 1, key);
        return parent;
    }
}

void TrieTree::insertTrie(TrieNode* node, TrieType* tmp_key, TrieType* key) {
    UInt32 index = charToInt(*tmp_key);
    TrieNode* new_node = new TrieNode;
    if (!node->bh.ptr[index]) {
        new_node->kind = LEAF;
        new_node->level = node->level + 1;
        new_node->parent = node;
        new_node->lf.size = strlen(key);
        new_node->lf.key = new TrieType[new_node->lf.size + 1];
        memcpy(new_node->lf.key, key, sizeof(TrieType)* new_node->lf.size);
        new_node->lf.key[new_node->lf.size] = '\0';
        new_node->lf.info = NULL;
        node->bh.ptr[index] = new_node;
        ++(node->bh.num);
    } else {
        tmp_key += 1;
        TrieType *old_key = node->bh.ptr[index]->lf.key;
        TrieType *tmp_old_key = old_key + +(tmp_key - key);
        delete node->bh.ptr[index];
        while (*tmp_old_key == *tmp_key) {
            node->bh.ptr[index] = new_node;
            new_node->kind = BRANCH;
            new_node->level = node->level + 1;
            new_node->parent = node;
            new_node->bh.num = 1;
            memset(new_node->bh.ptr, 0, sizeof(TrieNode*)* 27);
            index = charToInt(*tmp_key);
            ++tmp_key;
            ++tmp_old_key;
            node = new_node;
            new_node = new TrieNode;
        }
        node->bh.ptr[index] = new_node;
        new_node->kind = BRANCH;
        new_node->level = node->level + 1;
        new_node->parent = node;
        new_node->bh.num = 2;
        memset(new_node->bh.ptr, 0, sizeof(TrieNode*)* 27);
        node = new_node;
        node->bh.ptr[charToInt(*tmp_old_key)] = new_node = new TrieNode;
        new_node->kind = LEAF;
        new_node->level = node->level + 1;
        new_node->parent = node;
        new_node->lf.size = strlen(old_key);
        new_node->lf.key = old_key;
        new_node->lf.info = NULL;
        node->bh.ptr[charToInt(*tmp_key)] = new_node = new TrieNode;
        new_node->kind = LEAF;
        new_node->level = node->level + 1;
        new_node->parent = node;
        new_node->lf.size = strlen(key);
        new_node->lf.key = new TrieType[new_node->lf.size + 1];
        memcpy(new_node->lf.key, key, sizeof(TrieType)* new_node->lf.size);
        new_node->lf.key[new_node->lf.size] = '\0';
        new_node->lf.info = NULL;
    }
}

void TrieTree::deleteTrie(TrieNode* node, TrieType* key) {
    UInt32 index = charToInt(*(key + node->level - 1));
    TrieNode* del_node = node->bh.ptr[index];
    if (del_node->lf.info)  delete del_node->lf.info;
    if (del_node->lf.key) delete del_node->lf.key;
    delete del_node;
    node->bh.ptr[index] = NULL;
    --(node->bh.num);
    if (node->bh.num ==1) {
        UInt32 i;
        for (i = 0; i < 27; ++i) {
            if (node->bh.ptr[i])    break;
        }
        if (node->bh.ptr[i]->kind == LEAF) {
            for (index = 0; index < 27; ++index) {
                if (node->parent->bh.ptr[index] == node)    break;
            }
            node->parent->bh.ptr[index] = node->bh.ptr[i];
            node->bh.ptr[i]->level = node->parent->level + 1;
            node->bh.ptr[i]->parent = node->parent;
            delete node;
        }
    }
}
