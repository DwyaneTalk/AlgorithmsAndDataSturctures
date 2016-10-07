#include "../inc/BMinusTree.h"

BMinusTree::BMinusTree() {
    root = NULL;
    rank = m;
}

BMinusTree::~BMinusTree() {
    queue<BTreeNode*> node_queue;
    BTreeNode *node;
    if (root)   node_queue.push(root);
    while (!node_queue.empty()) {
        node = node_queue.front();
        node_queue.pop();
        for (UInt32 i = 0; i <= node->key_num; ++i) {
            if (node->child[i])
                node_queue.push(node->child[i]);
        }
        for (UInt32 i = 1; i <= node->key_num; ++i) {
            if (node->key[i]) {
                if (node->key[i]->info) {
                    delete node->key[i]->info;
                }
                delete node->key[i];
            }
        }
        delete node;
    }
    rank = 0;
    root = NULL;
}

Int32 BMinusTree::searchInNode(BTreeNode *node, BTreeType key_value) {
    int low = 0, high = node->key_num, mid;
    while (low < high) {
        mid = (low + high + 1) / 2;
        if (node->key[mid]->value == key_value) {
            return mid;
        } else if (node->key[mid]->value < key_value) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

bool BMinusTree::searchKey(BTreeType key_value, BTreeNode* &res_node, UInt32 &res_idx) {
    BTreeNode *parent_node = NULL, *node = root;
    UInt32 idx = 1;
    while (node) {
        idx = searchInNode(node, key_value);
        if (idx > 0 && idx <= node->key_num && node->key[idx]->value == key_value) {
            res_node = node;
            res_idx = idx;
            return true;
        } else {
            parent_node = node;
            node = node->child[idx];
        }
    }
    Location* loc = new Location(parent_node, idx, false);
    Key* key = new Key(key_value);
    insertKey(loc, key);
    res_node = parent_node;
    res_idx = idx;
    delete loc;
    return false;
}

void BMinusTree::insertInNode(Location* loc, Key* key, BTreeNode* child) {
    BTreeNode *node = loc->node;
    Int32 key_num = node->key_num;
    Int32 idx = loc->idx;
    memShift(node->key + idx + 1, node->key + idx + 2, RIGHT, sizeof(Key*)* (key_num - idx));
    memShift(node->child + idx +1, node->child + idx +2, RIGHT, sizeof(BTreeNode**)* (key_num - idx));
    node->key[idx + 1] = key;
    node->child[idx + 1] = child;
    ++(node->key_num);
    if (child)  child->parent = node;
    loc->idx += 1;
}

Key* BMinusTree::splitNode(BTreeNode *node, Location* loc, BTreeNode* &new_node) {
    if (!node || node->key_num < m) {
        ferr << "非法的结点分裂" << endl;
        exit(ERROR);
    }
    int mid = (m + 1) / 2;
    BTreeNode *left_node = new BTreeNode, *right_node = new BTreeNode;
    Key* res_key;

    if (!node->parent) 
        node->parent = root = new BTreeNode;

    left_node->key_num = mid - 1;
    memcpy(left_node->key + 1, node->key + 1, sizeof(Key*)* left_node->key_num);
    for (UInt32 i = 0; i <= left_node->key_num; ++i) {
        left_node->child[i] = node->child[i];
        if (left_node->child[i])
            left_node->child[i]->parent = left_node;
    }
    left_node->parent = node->parent;

    right_node->key_num = m - mid;
    memcpy(right_node->key + 1, node->key + mid + 1, sizeof(Key*)* left_node->key_num);
    for (UInt32 i = 0; i <= right_node->key_num; ++i) {
        right_node->child[i] = node->child[mid + i];
        if (right_node->child[i])
            right_node->child[i]->parent = right_node;
    }
    right_node->parent = node->parent;

    new_node = right_node;
    res_key = node->key[mid];
    loc->node = node->parent;
    loc->idx = searchInNode(node->parent, res_key->value);
    loc->tag = false;
    node->parent->child[loc->idx] = left_node;
    delete node;
    return res_key;
}

void BMinusTree::insertKey(Location* loc, Key* key) {
    if (loc->node) {
        if (!loc->tag && (loc->idx >= 0 && loc->idx <= loc->node->key_num)) {
            BTreeNode *cur_node = loc->node, *new_node;
            Key* res_key;
            Location *new_loc = new Location;
            // insert key
            insertInNode(loc, key, NULL);
            while (cur_node->key_num >= m) {
                // split
                res_key = splitNode(cur_node, new_loc, new_node);
                insertInNode(new_loc, res_key, new_node);
                cur_node = new_loc->node;
            }
            delete new_loc;
        }
    } else {
        root = new BTreeNode;
        root->key_num = 1;
        root->key[1] = key;
        root->child[0] = root->child[1] = NULL;
        loc->idx = 1;
        loc->node = root;
    }
}

void BMinusTree::deleteKey(Location* loc) {
    if (!loc || !loc->tag || !loc->node || loc->idx <0 || loc->idx > loc->node->key_num) {
        ferr << "无效的删除结点" << endl;
        exit(ERROR);
    } else {
        BTreeNode* node = loc->node;
        UInt32 idx = loc->idx;
        Key* key = node->key[idx];
        BTreeNode* child = node->child[idx];
        while (child) {
            idx = 0;
            node = child;
            child = node->child[idx];
        }
        if (!idx) {
            loc->node->key[loc->idx] = node->key[1];
            idx = 1;
        }
        if (node->key_num >= (m + 1) / 2) {
            memShift(node->key + idx, node->key + idx + 1, LEFT, sizeof(Key*)* (node->key_num - idx));
            memShift(node->child + idx, node->child + idx + 1, LEFT, sizeof(BTreeNode*)* (node->key_num - idx));
            node->key[node->key_num] = NULL;
            node->child[node->key_num] = NULL;
            --(node->key_num);
        } else {
            if (node == root) {
                if (node->key_num == 1) {
                    delete node;
                    root = NULL;
                } else {
                    memShift(node->key + idx, node->key + idx + 1, LEFT, sizeof(Key*)* (node->key_num - idx));
                    memShift(node->child + idx, node->child + idx + 1, LEFT, sizeof(BTreeNode*)* (node->key_num - idx));
                    node->key[node->key_num] = NULL;
                    node->child[node->key_num] = NULL;
                    --(node->key_num);
                }
            } else {
                UInt32 cur_idx = searchInNode(node->parent, node->key[1]->value);
                if (cur_idx > 0 && node->parent->child[cur_idx - 1]->key_num >= (m + 1) / 2) {  //有左兄弟
                    memShift(node->key + 1, node->key + 2, RIGHT, sizeof(Key*)* (idx - 1));
                    node->key[1] = node->parent->key[cur_idx];
                    node->parent->key[cur_idx] = node->parent->child[cur_idx - 1]->key[node->parent->child[cur_idx - 1]->key_num];
                    node->parent->child[cur_idx - 1]->key[node->parent->child[cur_idx - 1]->key_num] = NULL;
                    --(node->parent->child[cur_idx - 1]->key_num);
                } else if (cur_idx < node->parent->key_num && node->parent->child[cur_idx + 1]->key_num >= (m + 1) / 2) {   //有右兄弟
                    memShift(node->key + idx, node->key + idx + 1, LEFT, sizeof(Key*)* (node->key_num - idx));
                    node->key[node->key_num] = node->parent->key[cur_idx + 1];
                    node->parent->key[cur_idx + 1] = node->parent->child[cur_idx + 1]->key[1];
                    memShift(node->parent->child[cur_idx + 1]->key + 1, node->parent->child[cur_idx + 1]->key + 2, LEFT, sizeof(Key*)* (node->parent->child[cur_idx + 1]->key_num - 1));
                    node->parent->child[cur_idx + 1]->key[node->parent->child[cur_idx + 1]->key_num] = NULL;
                    --(node->parent->child[cur_idx + 1]->key_num);
                } else {
                    //todo
                    BTreeNode *parent, *n_child;
                    do {
                        memShift(node->key + idx, node->key + idx + 1, LEFT, sizeof(Key*)* (node->key_num - idx));
                        memShift(node->child + idx, node->child + idx + 1, LEFT, sizeof(BTreeNode*)* (node->key_num - idx));
                        node->key[node->key_num] = NULL;
                        node->child[node->key_num] = NULL;
                        --(node->key_num);
                        if (node == root) {
                            root = node->child[0];
                            delete node;
                            node = NULL;
                            break;
                        } else {
                            parent = node->parent;
                            if (cur_idx > 0) {
                                n_child = parent->child[cur_idx - 1];
                                n_child->key[++(n_child->key_num)] = parent->key[cur_idx];
                                n_child->child[n_child->key_num] = node->child[0];
                                for (UInt32 i = 1; i <= node->key_num; ++i) {
                                    n_child->key[++(n_child->key_num)] = node->key[i];
                                    n_child->child[n_child->key_num] = node->child[i];
                                }
                                idx = cur_idx;
                                cur_idx = searchInNode(node->parent, node->parent->key[idx]->value);
                                delete node;
                                node = n_child->parent;
                            } else if (cur_idx < parent->key_num) {
                                n_child = parent->child[cur_idx + 1];
                                node->key[++(node->key_num)] = parent->key[cur_idx + 1];
                                node->child[node->key_num] = n_child->child[0];
                                for (UInt32 i = 1; i <= n_child->key_num; ++i) {
                                    node->key[++(node->key_num)] = n_child->key[i];
                                    node->child[node->key_num] = n_child->child[i];
                                }
                                idx = cur_idx + 1;
                                cur_idx = searchInNode(node->parent, node->parent->key[idx]->value);
                                delete n_child;
                                node = node->parent;
                            } else {
                                ferr << "出错，不合理的删除位置，树结构出错" << endl;
                                exit(ERROR);
                            }
                        }
                     } while (node->key_num < (m + 1) / 2);
                    if (node) {
                        memShift(node->key + idx, node->key + idx + 1, LEFT, sizeof(Key*)* (node->key_num - idx));
                        memShift(node->child + idx, node->child + idx + 1, LEFT, sizeof(BTreeNode*)* (node->key_num - idx));
                        node->key[node->key_num] = NULL;
                        node->child[node->key_num] = NULL;
                        --(node->key_num);
                    }
                }
            }
        }
        if (key)
            delete key->info;
        delete key;
    }
}