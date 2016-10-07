#include "../inc/DynamicSrhTable.h"

DynamicSrhTable::DynamicSrhTable() {
    size = 0;
    if (data = new SearchType[INIT_SIZE]) {
        max_size = INIT_SIZE;
        bin_sort_tree = new BinaryTree;
        bal_bin_tree = new BinaryTree;
        if(!bin_sort_tree || !bal_bin_tree) {
            ferr << "申请初始内存失败！" << endl;
            exit(OVER);
        }
    } else {
        ferr << "申请初始内存失败！" << endl;
        exit(OVER);
    }
}

DynamicSrhTable::~DynamicSrhTable() {
    size = 0;
    max_size = 0;
    delete data;
    delete bin_sort_tree;
    delete bal_bin_tree;
}

void DynamicSrhTable::init() {
    size = 0;
    bin_sort_tree->init();
    bal_bin_tree->init();
}

UInt32 DynamicSrhTable::newElem(SearchType key) {
    if (size < max_size) {
        data[size] = key;
    } else {
        data = (SearchType*) renew(data, size, INCREMENT, sizeof(SearchType));
        max_size += INCREMENT;
        data[size] = key;
    }
    return size++;
}

void DynamicSrhTable::delElem(UInt32 index) {
    data[index] = NULL_DATA;
    --size;
}

Int32 DynamicSrhTable::search(DynFindType f_type, SearchType key) {
    BiNode *node;
    Int32 index;
    switch (f_type) {
    case BST:
        index = bstSearch(key, node);
        if (index < 0) {
            bstInsert(node, newElem(key));
        }
        return index;
    case BBT:
        return bbtSearch(key);
    }
    return -1;
}

void DynamicSrhTable::deleteData(DynFindType f_type, SearchType key) {
    BiNode *node;
    Int32 index;
    switch (f_type) {
    case BST:
        index = bstSearch(key, node);
        if (index >= 0) {
            delElem(index);
            bstDelete(node, index);
        } else {
            cout << "要删除的结点没有找到！" << endl;
        }
        break;
    }
}

Int32 DynamicSrhTable::bstSearch(SearchType key, BiNode *&node) {
    BiNode *cur_node = bin_sort_tree->getRoot();
    node = NULL;
    while (cur_node) {
        if (data[cur_node->data] == key) {
            return cur_node->data;
        } else if (data[cur_node->data] < key) {
            node = cur_node;
            cur_node = cur_node->rchild;
        } else {
            node = cur_node;
            cur_node = cur_node->lchild;
        }
    }
    return -1;
}

BiNode* DynamicSrhTable::bstInsert(BiNode *node, UInt32 index) {
    if (!node) {
        if (bin_sort_tree->getRoot()) {
            ferr << "无效的插入位置" << endl;
            exit(ERROR);
        } else {
            BiNode *new_node = new BiNode(index);
            *(bin_sort_tree->getRootPoint()) = new_node;
            return new_node;
        }
    } else {
        BiNode *new_node = new BiNode(index);
        if (data[node->data] < data[index]) {
            node->rchild = new_node;
        } else {
            node->lchild = new_node;
        }
        return new_node;
    }
}

void DynamicSrhTable::bstDelete(BiNode *node, UInt32 index) {
    if (!node && !bin_sort_tree->getRoot()) {
        ferr << "无效的删除结点" << endl;
        exit(ERROR);
    } else {
        BiNode *del_node, **cld_node;
        if (!node) {
            cld_node = bin_sort_tree->getRootPoint();
            del_node = *cld_node;
        } else {
            if (node->lchild && node->lchild->data == index) {
                cld_node = &node->lchild;
                del_node = node->lchild;
            } else if (node->rchild && node->rchild->data == index) {
                cld_node = &node->rchild;
                del_node = node->rchild;
            } else {
                ferr << "非法的删除结点操作" << endl;
                exit(ERROR);
            }
        }
        if (!del_node->lchild) {
            *cld_node = del_node->rchild;
            delete del_node;
        } else if (!del_node->rchild) {
            *cld_node = del_node->lchild;
            delete del_node;
        } else {
            BiNode *t_node = del_node->lchild;
            node = del_node;
            while (t_node->rchild) {
                node = t_node;
                t_node = t_node->rchild;
            }
            del_node->data = t_node->data;
            bstDelete(node, t_node->data);
        }
    }
}

Int32 DynamicSrhTable::bbtSearch(SearchType key) {
    BiNode *parent = NULL, *node = bal_bin_tree->getRoot();
    stack<LR> lr_stack;
    lr_stack.push(LEFT);
    // search step
    while (node) {
        if (data[node->data] == key)
            return node->data;
        else if (data[node->data] < key) {
            parent = node;
            node = node->rchild;
            lr_stack.push(RIGHT);
        } else {
            parent = node;
            node = node->lchild;
            lr_stack.push(LEFT);
        }
    }
    LR lr = lr_stack.top();
    lr_stack.pop();
    UInt32 index = newElem(key);
    if (!parent) {
        *bal_bin_tree->getRootPoint() = node = new BiNode(index);
        node->info->i_value1 = EH;
        return -1;
    }
    (lr == LEFT ? parent->lchild : parent->rchild) = node = new BiNode(index);
    node->parent = parent;
    node->info->i_value1 = EH;
    bool taller = true;
    while (taller && parent) {
        if (lr == LEFT) {
            switch (parent->info->i_value1) {
            case LH:
                if (!parent->parent) {
                    (*bal_bin_tree->getRootPoint()) = leftBlance(parent);
                } else {
                    BiNode *parent_node = parent->parent;
                    if (parent_node->lchild == parent)
                        parent_node->lchild = leftBlance(parent);
                    else
                        parent_node->rchild = leftBlance(parent);
                }
                taller = false;
                break;
            case EH:
                parent->info->i_value1 = LH;
                break;
            case RH:
                parent->info->i_value1 = EH;
                taller = false;
                break;
            }
        } else {
            switch (parent->info->i_value1) {
            case LH:
                parent->info->i_value1 = EH;
                taller = false;
                break;
            case EH:
                parent->info->i_value1 = RH;
                break;
            case RH:
                if (!parent->parent) {
                    *(bal_bin_tree->getRootPoint()) = rightBlance(parent);
                } else {
                    BiNode *parent_node = parent->parent;
                    if (parent_node->lchild == parent)
                        parent_node->lchild = rightBlance(parent);
                    else
                        parent_node->rchild = rightBlance(parent);
                }
                taller = false;
                break;
            }
        }
        node = parent;
        parent = parent->parent;
        lr = lr_stack.top();
        lr_stack.pop();
    }
    while (!lr_stack.empty()) {
        lr_stack.pop();
    }
    return -1;
}

BiNode* DynamicSrhTable::leftBlance(BiNode *node) {
    BiNode *node_b = node->lchild, *node_c;
    switch (node_b->info->i_value1) {
    case LH:
        node->info->i_value1 = node_b->info->i_value1 = RH;
        return rightRotate(node);
    case RH:
        node_c = node_b->rchild;
        switch (node_c->info->i_value1) {
        case LH:
            node_b->info->i_value1 = EH;
            node->info->i_value1 = RH;
            break;
        case EH:
            node_b->info->i_value1 = node->info->i_value1 = EH;
            break;
        case RH:
            node_b->info->i_value1 = LH;
            node->info->i_value1 = EH;
            break;
        }
        node_c->info->i_value1 = EH;
        node->lchild = leftRotate(node_b);
        return rightRotate(node);
    default:
        ferr << "操作出现错误，非法坐平衡操作" << endl;
        exit(ERROR);
        break;
    }
}

BiNode* DynamicSrhTable::rightBlance(BiNode *node) {
    BiNode *node_b = node->rchild, *node_c;
    switch (node_b->info->i_value1) {
    case LH:
        node_c = node_b->lchild;
        switch (node_c->info->i_value1) {
        case LH:
            node->info->i_value1 = EH;
            node_b->info->i_value1 = RH;
            break;
        case EH:
            node->info->i_value1 = node_b->info->i_value1 = EH;
            break;
        case RH:
            node->info->i_value1 = LH;
            node_b->info->i_value1 = EH;
            break;
        }
        node_c->info->i_value1 = EH;
        node->rchild = rightRotate(node_b);
        return leftRotate(node);
    case RH:
        node->info->i_value1 = node_b->info->i_value1 = EH;
        return leftRotate(node);
    default:
        ferr << "操作出现错误，非法坐平衡操作" << endl;
        exit(ERROR);
        break;
    }
}

BiNode* DynamicSrhTable::leftRotate(BiNode *node) {
    BiNode *node_b = node->rchild;
    node->rchild = node_b->lchild;
    node_b->lchild = node;
    node_b->parent = node->parent;
    node->parent = node_b;
    if (node->rchild)
        node->rchild->parent = node;
    return node_b;
}

BiNode* DynamicSrhTable::rightRotate(BiNode *node) {
    BiNode *node_b = node->lchild;
    node->lchild = node_b->rchild;
    node_b->rchild = node;
    node_b->parent = node->parent;
    node->parent = node_b;
    if (node->lchild)
        node->lchild->parent = node;
    return node_b;
}

void DynamicSrhTable::traverse(DynFindType f_type, void(*visit)(SearchType &e)) {
    UInt32 length = size;
    for (UInt32 i = 0; i < length; ++i) {
        if (data[i] != NULL_DATA)
            visit(data[i]);
        else
            ++length;
    }
    cout << endl;
    SearchType *tmp_data = new SearchType[size], *in_data;
    switch (f_type) {
    case BST:
        in_data = tmp_data;
        bin_sort_tree->show(0);
        bin_sort_tree->inOrderTraverse(BinaryTree::visit, &in_data);
        break;
    case BBT:
        in_data = tmp_data;
        bal_bin_tree->show(0);
        bal_bin_tree->inOrderTraverse(BinaryTree::visit, &in_data);
        break;
    }
    for (UInt32 i = 0; i < size; ++i)
        cout << data[tmp_data[i]] << " ";
    cout << endl;
}

void DynamicSrhTable::visit(SearchType &e) {
    cout << e << " ";
}