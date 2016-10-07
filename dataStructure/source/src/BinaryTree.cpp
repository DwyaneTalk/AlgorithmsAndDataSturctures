#include "../inc/BinaryTree.h"

BinaryTree::BinaryTree() {
    root = NULL;
}

BinaryTree::~BinaryTree() {
    if (root) {
        queue<BiNode *> queue;
        BiNode *node;
        queue.push(root);
        while (!queue.empty()) {
            node = queue.front();
            queue.pop();
            if (node->lchild)   queue.push(node->lchild);
            if (node->rchild)   queue.push(node->rchild);
            delete node;
        }
        root = NULL;
    }
}

void BinaryTree::init() {
    if (root) {
        BinaryTree *leftTree = getChildTree(LEFT), *rightTree = getChildTree(RIGHT);
        leftTree->init();
        rightTree->init();
        delete root;
        root = NULL;
    }
}

void BinaryTree::createBibaryTree(BiNode **root, BiNode *parent) {
    BiTreeElemType data;
    fin >> data;
    if (data == 0) {
        (*root) = NULL;
    } else {
        (*root) = new BiNode(data);
        (*root)->parent = parent;
        createBibaryTree(&(*root)->lchild, *root);
        createBibaryTree(&(*root)->rchild, *root);
    }
}

void BinaryTree::preinCreateBinaryTree(BiNode **root, BiNode *parent, BiTreeElemType *pre_data, BiTreeElemType *in_data, int nums) {
    if (nums) {
        (*root) = new BiNode(pre_data[0]);
        (*root)->parent = parent;
        int idx = 0;
        for (; idx < nums; ++idx) {
            if (in_data[idx] == pre_data[0]) {
                break;
            }
        }
        preinCreateBinaryTree(&(*root)->lchild, *root, pre_data + 1, in_data, idx);
        preinCreateBinaryTree(&(*root)->rchild, *root, pre_data + 1 + idx, in_data + idx + 1, nums - idx - 1);
    } else {
        (*root) = NULL;
    }
}

void BinaryTree::postinCreateBinaryTree(BiNode **root, BiNode *parent, BiTreeElemType *post_data, BiTreeElemType *in_data, int nums) {
    if (nums) {
        (*root) = new BiNode(post_data[nums - 1]);
        (*root)->parent = parent;
        int idx = 0;
        for (; idx < nums; ++idx) {
            if (in_data[idx] == post_data[nums - 1]) {
                break;
            }
        }
        postinCreateBinaryTree(&(*root)->lchild, (*root), post_data, in_data, idx);
        postinCreateBinaryTree(&(*root)->rchild, (*root), post_data + idx, in_data + idx + 1, nums - idx - 1);
    } else {
        (*root) = NULL;
    }
}

bool BinaryTree::isEmpty() {
    return !root;
}

void BinaryTree::getNodeInfo(int& depth, int& allNodeNums, int& leafNodeNums) {
    if (root) {
        BinaryTree *lChildTree = getChildTree(LEFT), *rChildTree = getChildTree(RIGHT);
        int ldepth, lallNums, lleafNums, rdepth, rallNums, rleafNums;
        lChildTree->getNodeInfo(ldepth, lallNums, lleafNums);
        rChildTree->getNodeInfo(rdepth, rallNums, rleafNums);
        if (ldepth || rdepth) {
            depth = MAX(ldepth, rdepth) + 1;
            allNodeNums = lallNums + rallNums + 1;
            leafNodeNums = lleafNums + rleafNums;
        } else {
            depth = 1;
            allNodeNums = 1;
            leafNodeNums = 1;
        }
    } else {
        depth = 0;
        allNodeNums = 0;
        leafNodeNums = 0;
    }

}

BiNode* BinaryTree::getRoot() {
    return root;
}

BiNode** BinaryTree::getRootPoint() {
    return &root;
}

BiNode* BinaryTree::findNode(BiTreeElemType data) {
    if (root) {
        if (root->data == data) {
            return root;
        }
        BiNode *ansNode;
        BinaryTree *leftree = getChildTree(LEFT);
        ansNode = leftree->findNode(data);
        if (!ansNode) {
            BinaryTree *rightTree = getChildTree(RIGHT);
            ansNode = rightTree->findNode(data);
        }
        return ansNode;
    }
   return NULL;
}

void BinaryTree::setChildNode(BiNode *node, LR lr, BiNode *newNode) {
    if (node) {
        if (lr == LEFT) {
            node->lchild = newNode;
        } else {
            node->rchild = newNode;
        }
    } else {
        ferr << "对空结点的非法操作" << endl;
        exit(ERROR);
    }
}

BiTreeElemType BinaryTree::getNodeData(BiNode *node) {
    return node->data;
}

void BinaryTree::setNodeData(BiNode *node, BiTreeElemType data) {
    node->data = data;
}

BinaryTree* BinaryTree::getChildTree( LR lr) {
    if (root) {
        BinaryTree *childTree = new BinaryTree;
        if (lr == LEFT)     childTree->root = root->lchild;
        else                childTree->root = root->rchild;
        return childTree;
    }
    return NULL;
}


BiNode* BinaryTree::getNodeParent(BiNode *node) {
    if (node)   return node->parent;
    else        return NULL;
}

BiNode* BinaryTree::getNodeChild(BiNode *node, LR lr) {
    if (node) {
       if(lr == LEFT)   return node->lchild;
       else             return node->rchild;
    }
    else        return NULL;
}


BiNode* BinaryTree::getNodeSibling(BiNode *node, LR &lr) {
    if (node && node->parent) {
        if (node->parent->lchild == node) {
            lr = LEFT;
            return node->parent->rchild;
        } else {
            lr = RIGHT;
            return node->parent->lchild;
        }
    }
    return NULL;
}


void BinaryTree::insertChildNode(BiNode *node, LR lr, BiTreeElemType data){
    if (!node) {
        ferr << "无效的二叉树插入节点" << endl;
        exit(ERROR);
    }
    if (lr == LEFT) {
        if (node->lchild) {
            node->lchild->data = data;
        } else {
            node->lchild = new BiNode(data);
            node->lchild->parent = node;
        }
    } else {
        if (node->rchild) {
            node->rchild->data = data;
        } else {
            node->rchild = new BiNode(data);
            node->rchild->parent = node;
        }
    }
}

BiTreeElemType BinaryTree::deleteChildNode(BiNode *node, LR lr) {
    BiTreeElemType ans = 0;
    if (node) {
        BinaryTree *nodeTree = new BinaryTree;
        nodeTree->root = node;
        BinaryTree *childTree = nodeTree->getChildTree(lr);
        ans = getNodeData(getNodeChild(node, lr));
        if (childTree) {
            childTree->init();
            setChildNode(node, lr, NULL);
        }
    }
    return ans;
}

void BinaryTree::preOrderTraverse(void(*visit)(BiTreeElemType &e), BiTreeElemType **data) {
    if (root) {
        **data = root->data;
        visit(root->data);
        (*data)++;
        BinaryTree *lChildTree = getChildTree(LEFT), *rChildTree = getChildTree(RIGHT);
        lChildTree->preOrderTraverse(visit, data);
        rChildTree->preOrderTraverse(visit, data);
    }
}

void BinaryTree::inOrderTraverse(void(*visit)(BiTreeElemType &e), BiTreeElemType **data) {
    if (root) {
        BinaryTree *lChildTree = getChildTree(LEFT), *rChildTree = getChildTree(RIGHT);
        lChildTree->inOrderTraverse(visit, data);
        **data = root->data;
        visit(root->data);
        (*data)++;
        rChildTree->inOrderTraverse(visit, data);
    }
}

void BinaryTree::postOrderTraverse(void(*visit)(BiTreeElemType &e), BiTreeElemType **data) {
    if (root) {
        BinaryTree *lChildTree = getChildTree(LEFT), *rChildTree = getChildTree(RIGHT);
        lChildTree->postOrderTraverse(visit, data);
        rChildTree->postOrderTraverse(visit, data);
        **data = root->data;
        visit(root->data);
        (*data)++;
    }
}

void BinaryTree::levelOrderTraverse(void(*visit)(BiTreeElemType &e), BiTreeElemType *data) {
    if (root) {
        queue<BiNode*>queue;
        BiNode *node;
        queue.push(root);
        while (!queue.empty()) {
            node = queue.front();
            queue.pop();
            if (node->lchild)   queue.push(node->lchild);
            if (node->rchild)   queue.push(node->rchild);
            *(data++) = node->data;
        }
    }
}

void BinaryTree::show(int n) {
    if (root) {
        BinaryTree *rTree = getChildTree(RIGHT), *lTree = getChildTree(LEFT);
        rTree->show(n + 1);
        for (int i = 0; i < n; ++i)
            cout << "     ";
        cout << root->data << endl;
        lTree->show(n + 1);
    }
}

void BinaryTree::visit(BiTreeElemType &data) {
    data = data;
}