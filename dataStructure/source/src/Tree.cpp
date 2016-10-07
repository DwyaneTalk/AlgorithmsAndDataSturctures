#include "../inc/Tree.h"

Tree::Tree() {
    if (base = new TreeNode[INIT_SIZE]) {
        root_idx = -1;
        node_nums = 0;
        max_nums = INIT_SIZE;
    } else {
        ferr << "内存申请失败！" << endl;
        exit(OVER);
    }
}

Tree::~Tree(){
    ChildNode* child_node = NULL;
    ChildNode* free_node = NULL;
    for (UInt8 i = 0; i < node_nums; ++i) {
        child_node = base[i].child_list;
        while (child_node) {
            free_node = child_node;
            child_node = child_node->next;
            delete free_node;
        }
    }
    delete base;
    root_idx = -1;
    node_nums = 0;
    max_nums = 0;
}

void Tree::init() {
    ChildNode* child_node = NULL;
    ChildNode* free_node = NULL;
    for (UInt8 i = 0; i < node_nums; ++i) {
        child_node = base[i].child_list;
        while (child_node) {
            free_node = child_node;
            child_node = child_node->next;
            delete free_node;
        }
    }
    root_idx = -1;
    node_nums = 0;
}

void Tree::createTree() {
    queue<UInt8> queue;
    TreeElemType e;
    UInt8 idx;
    ChildNode **child_node;
    fin >> e;
    if (e) {
        if (node_nums >= max_nums) {
            base = (TreeNode *) renew(base, max_nums, INCREMENT, sizeof(TreeNode));
            max_nums += INCREMENT;
        }
        base[node_nums].e = e;
        base[node_nums].parent_idx = -1;
        base[node_nums].child_list = NULL;
        root_idx = node_nums;
        queue.push(node_nums);
        ++node_nums;
        while (!queue.empty()) {
            idx = queue.front();
            queue.pop();
            child_node = &(base[idx].child_list);
            fin >> e;
            while (e) {
                if (node_nums >= max_nums) {
                    base = (TreeNode*)renew(base, max_nums, INCREMENT, sizeof(TreeNode));
                    max_nums += INCREMENT;
                }
                base[node_nums].e = e;
                base[node_nums].parent_idx = idx;
                base[node_nums].child_list = NULL;
                *child_node = new ChildNode(node_nums);
                child_node = &((*child_node)->next);
                queue.push(node_nums);
                ++node_nums;
                fin >> e;
            }
        }
    }
}

bool Tree::isEmpty() {
    return !node_nums;
}

UInt8 Tree::getNodeNums() {
    return node_nums;
}

UInt8 Tree::getLeafNums() {
    UInt8 nums = 0;
    for (UInt8 i = 0; i < node_nums; ++i) {
        if (!(base[i].child_list))  ++nums;
    }
    return nums;
}


void Tree::getTreeInfo(UInt8 &depth, UInt8 &all_nums, UInt8 &leaf_nums) {
    queue<UInt8> idx_queue;
    queue<UInt8> dph_queue;
    UInt8 index;
    UInt8 tmp_tph;
    ChildNode* child_node;
    depth = 0;
    all_nums = 0;
    leaf_nums = 0;
    if (node_nums) {
        idx_queue.push(root_idx);
        dph_queue.push(1);
        while (!idx_queue.empty()) {
            index = idx_queue.front();
            idx_queue.pop();
            tmp_tph = dph_queue.front();
            dph_queue.pop();
            depth = MAX(depth, tmp_tph);
            ++all_nums;
            child_node = base[index].child_list;
            if (child_node) {
                while (child_node) {
                    idx_queue.push(child_node->index);
                    dph_queue.push(depth + 1);
                    child_node = child_node->next;
                }
            } else {
                ++leaf_nums;
            }
        }
    }
}

TreeNode* Tree::getRoot() {
    if (root_idx >= 0)
        return base + root_idx; 
    else    return NULL;
}

TreeNode* Tree::getTreeNode(TreeElemType e) {
    for (UInt8 i = 0; i < node_nums; ++i) {
        if (base[i].e == e) {
            return base + i;
        }
    }
    return NULL;
}

TreeElemType Tree::getNodeData(TreeNode* node) {
    if(node)    return node->e;
    ferr << "无效的操作结点" << endl;
    exit(ERROR);
}

void Tree::setNodeData(TreeNode* node, TreeElemType e) {
    if (node)   node->e = e;
    else {
        ferr << "无效的操作结点" << endl;
        exit(ERROR);
    }
}

TreeNode* Tree::getParent(TreeNode* node) {
    if (node)   return base + node->parent_idx;
    ferr << "无效的操作结点" << endl;
    exit(ERROR);
}

TreeNode* Tree::getChild(TreeNode* node, UInt8 index) {
    if (node) {
        UInt8 i = 1;
        ChildNode *child_node = node->child_list;
        while (i++ < index && child_node) {
            child_node = child_node->next;
        }
        if (child_node)     return base + child_node->index;
        ferr << "该结点孩子结点数少于：" << index << endl;
        exit(ERROR);
    }
    ferr << "无效的操作结点" << endl;
    exit(ERROR);
}

TreeNode* Tree::getSbling(TreeNode* node, LR lr) {
    if (node) {
        TreeNode *parent_node = getParent(node);
        ChildNode *child_node = parent_node->child_list;
        if (lr == LEFT) {
            if (!child_node) {
                ferr << "树结构出错！" << endl;
                exit(ERROR);
            }
            while (child_node->next && base[child_node->next->index].e != node->e) {
                child_node = child_node->next;
            }
            if (child_node->next)   return base + child_node->index;
        } else {
            while (child_node && base[child_node->index].e != node->e) {
                child_node = child_node->next;
            }
            if (child_node->next)   return base + child_node->next->index;
        }
        ferr << "该结点没有相应的兄弟结点" << endl;
        exit(ERROR);
    }
    ferr << "无效的操作结点" << endl;
    exit(ERROR);
}

UInt8 Tree::getChildIndex(TreeNode* node, TreeElemType e) {
    UInt8 index = 1;
    ChildNode* child_node = node->child_list;
    while (child_node && base[child_node->index].e != e) {
        child_node = child_node->next;
        ++index;
    }
    if (child_node)     return index;
    else                return -1;
}

TreeNode* Tree::InsertChild(TreeNode* node, TreeElemType e) {
    if (node) {
        if (node_nums >= max_nums) {
            base = (TreeNode*)renew(base, max_nums, INCREMENT, sizeof(TreeNode));
            max_nums += INCREMENT;
        }
        base[node_nums].e = e;
        base[node_nums].parent_idx = node - base;
        base[node_nums].child_list = NULL;
        if (!node->child_list) {
            if (!(node->child_list = new ChildNode(node_nums))) {
                ferr << "申请内存失败！" << endl;
                exit(OVER);
            }
        } else {
            ChildNode* child_node = node->child_list;
            while (child_node->next)    child_node = child_node->next;
            if (!(child_node->next = new ChildNode(node_nums))) {
                ferr << "申请内存失败！" << endl;
                exit(OVER);
            }
        }
        ++node_nums;
    } else if(isEmpty()){
        base[node_nums].e = e;
        base[node_nums].parent_idx = -1;
        base[node_nums].child_list = NULL;
        root_idx = node_nums++;
    } else {
        ferr << "无效的操作结点" << endl;
        exit(ERROR);
    }
    return base + node_nums - 1;
}

TreeElemType Tree::deleteChild(TreeNode* node, UInt8 index) {
    if (node) {
        ChildNode* free_node;
        TreeNode* free_tree_node;
        ChildNode* free_node_child;
        ChildNode* tmp_child;
        TreeElemType e;
        UInt8 free_idx;
        if (index == 1) {
            if (!node->child_list) {
                ferr << "该结点孩子结点数少于：" << index << endl;
                exit(ERROR);
            }
            free_node = node->child_list;
            free_idx = free_node->index;
            free_tree_node = base + free_idx;
            free_node_child = free_tree_node->child_list;
            while (free_node_child) {
                tmp_child = free_node_child->next;
                deleteNode(base + free_node_child->index);
                free_node_child = tmp_child;
            }
            node->child_list = free_node->next;
        } else {
            UInt8 idx = 2;
            ChildNode* child_node = node->child_list;
            while (idx++ < index && child_node->next) {
                child_node = child_node->next;
            }
            if (child_node) {
                free_node = child_node->next;
                free_idx = free_node->index;
                free_tree_node = base + free_idx;
                free_node_child = free_tree_node->child_list;
                while (free_node_child) {
                    tmp_child = free_node_child->next;
                    deleteNode(base + free_node_child->index);
                    free_node_child = tmp_child;
                }
                child_node->next = free_node->next;
            } else {
                ferr << "该结点孩子结点数少于：" << index << endl;
                exit(ERROR);
            }
        }
        delete free_node;
        UInt8 start_idx = free_idx + 1;
        ChildNode* child_list;
        e = base[free_idx].e;
        while (start_idx < node_nums && start_idx > 0) {
            base[start_idx - 1] = base[start_idx];
            child_list = getParent(base + start_idx)->child_list;
            while (child_list && child_list->index != start_idx) {
                child_list = child_list->next;
            }
            if (child_list) {
                child_list->index = start_idx - 1;
            } else {
                ferr << "树结构出错" << endl;
                exit(ERROR);
            }
            ++start_idx;
        }
        --node_nums;
        return e;
    } else {
        ferr << "无效的操作结点" << endl;
        exit(ERROR);
    }
}

TreeElemType Tree::deleteNode(TreeNode* node) {
    UInt8 index = getChildIndex(getParent(node), node->e);
    return deleteChild(getParent(node), index);
}

void Tree::DFSTraverse(void(*visit)(TreeElemType& e), TreeElemType *data) {
    stack<UInt8> idx_stack;
    stack<UInt8> tmp_stack;
    if (node_nums) {
        TreeNode* tree_node;
        ChildNode* child_node;
        idx_stack.push(root_idx);
        while (!idx_stack.empty()) {
            tree_node = base + idx_stack.top();
            idx_stack.pop();
            visit(tree_node->e);
            (*data++) = tree_node->e;
            child_node = tree_node->child_list;
            while (child_node) {
                tmp_stack.push(child_node->index);
                child_node = child_node->next;
            }
            while (!tmp_stack.empty()) {
                idx_stack.push(tmp_stack.top());
                tmp_stack.pop();
            }
        }
    }
}

void Tree::BFSTraverse(void(*visit)(TreeElemType& e), TreeElemType *data) {
    queue<UInt8> queue;
    if (node_nums) {
        TreeNode* tree_node;
        ChildNode* child_node;
        queue.push(root_idx);
        while (!queue.empty()) {
            tree_node = base + queue.front();
            queue.pop();
            visit(tree_node->e);
            (*data++) = tree_node->e;
            child_node = tree_node->child_list;
            while (child_node) {
                queue.push(child_node->index);
                child_node = child_node->next;
            }
        }
    }
}

void Tree::show() {
    queue<UInt8> queue;
    UInt8   index;
    ChildNode* child_node;
    cout << "树的结点存储结构如下：" << endl;
    if (node_nums)  queue.push(root_idx);
    while (!queue.empty()) {
        index = queue.front();
        queue.pop();
        cout << "元素" << base[index].e << "; 孩子 ";
        child_node = base[index].child_list;
        while (child_node) {
            cout << "->" << base[child_node->index].e;
            queue.push(child_node->index);
            child_node = child_node->next;
        }
        cout << "->Null" << endl;
    }
}

void Tree::visit(TreeElemType& e) {
    // to something you want
}
