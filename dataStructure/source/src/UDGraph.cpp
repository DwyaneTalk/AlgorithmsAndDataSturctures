#include "../inc/UDGraph.h"


UDGraph::UDGraph() {
    if ((vexs = new UVex[MAXELEMNUM]) && (arcs = new UArc*[MAXELEMNUM])) {
        for (UInt8 i = 0; i < MAXELEMNUM; ++i) {
            if (!(arcs[i] = new UArc[MAXELEMNUM])) {
                ferr << "申请内存失败！" << endl;
                exit(OVER);
            }
        }
        graph_type  = UDN;
        vex_nums    = 0;
        arc_nums    = 0;
    } else {
        ferr << "申请内存失败！" << endl;
        exit(OVER);
    }
}

UDGraph::~UDGraph() {
    vex_nums = 0;
    arc_nums = 0;
    delete vexs;
    for (UInt8 i = 0; i < MAXELEMNUM; ++i)
        delete arcs[i];
    delete arcs;
}

void    UDGraph::init() {
    vex_nums = 0;
    arc_nums = 0;
}

void    UDGraph::createGraph() {
    fin >> vex_nums >> arc_nums;
    if (vex_nums > MAXELEMNUM) {
        ferr << "图的顶点数超过最大限制！" << endl;
        exit(ERROR);
    }
    for (UInt8 i = 0; i < vex_nums; ++i)
        fin >> vexs[i].data;
    VexType t_vex, h_vex;
    UInt8 t_idx, h_idx;
    for (UInt8 i = 0; i < arc_nums; ++i) {
        fin >> t_vex >> h_vex;
        t_idx = getDataIndex(t_vex);
        h_idx = getDataIndex(h_vex);
        if (t_idx < 0 || h_idx < 0) {
            ferr << "构造图结构出错，不合法的弧存在" << endl;
            exit(ERROR);
        }
        fin >> arcs[t_idx][h_idx].value;
        arcs[h_idx][t_idx].value = arcs[t_idx][h_idx].value;
    }
}

UVex*    UDGraph::locateVex(VexType data) {
    UInt8 index = getDataIndex(data);
    if (index < 0)  return NULL;
    else            return vexs + index;
}

UArc*   UDGraph::locateArc(UVex* vex1, UVex* vex2) {
    if (vex1 && vex2) {
        UInt8 idx1 = getVexIndex(vex1), idx2 = getVexIndex(vex2);
        return &arcs[idx1][idx2];
    } else {
        ferr << "对空顶点的非法操作" << endl;
        exit(ERROR);
    }
}

VexType UDGraph::getVexData(UVex* vex) {
    if (vex) {
        return vex->data;
    } else {
        ferr << "对空顶点非法操作！" << endl;
        exit(ERROR);
    }
}

void    UDGraph::setVexData(UVex* vex, VexType data) {
    if (vex) {
        vex->data = data;
    } else {
        ferr << "对空顶点非法操作！" << endl;
        exit(ERROR);
    }
}

UInt8   UDGraph::getVexDegree(UVex *vex) {
    UInt8 index = getVexIndex(vex);
    UInt8 degree = 0;
    for (UInt8 i = 0; i < vex_nums; ++i) {
        if (arcs[index][i].value != NULL_ARC)   ++degree;
    }
    return degree;
}

UVex*    UDGraph::firstVex(UVex* vex) {
    UInt8 idx = getVexIndex(vex);
    for (UInt8 i = 0; i < vex_nums; ++i) {
        if (arcs[idx][i].value != NULL_ARC)  return vexs + i;
    }
    return NULL;
}

UVex*    UDGraph::nextVex(UVex* vex, UVex* cur_vex) {
    if (!cur_vex)   return firstVex(vex);
    UInt8 t_idx = getVexIndex(vex);
    UInt8 h_idx = getVexIndex(cur_vex);
    for (UInt8 i = h_idx + 1; i < vex_nums; ++i) {
        if (arcs[t_idx][i].value != NULL_ARC)    return vexs + i;
    }
    return NULL;
}

UVex*    UDGraph::insertVex(VexType data) {
    if (vex_nums < MAXELEMNUM) {
        vexs[vex_nums++].data = data;
        return vexs + vex_nums - 1;
    } else {
        ferr << "顶点数达到最大，无法添加新的顶点！" << endl;
        exit(ERROR);
    }
}

VexType UDGraph::deleteVex(UVex* vex) {
    if (vex) {
        VexType data = vex->data;
        UArc *tmp_arc;
        UInt8 index = getVexIndex(vex);
        --vex_nums;
        vexs[index] = vexs[vex_nums];
        for (UInt8 i = 0; i <= vex_nums; ++i) {
            if (arcs[index][i].value != NULL_ARC)   --arc_nums;
        }
        tmp_arc = arcs[index];
        arcs[index] = arcs[vex_nums];
        arcs[vex_nums] = tmp_arc;
        for (UInt8 i = 0; i < vex_nums; ++i) {
            arcs[i][index] = arcs[i][vex_nums];
        }
        return data;
    } else {
        ferr << "对空顶点的非法操作！" << endl;
        exit(ERROR);
    }
}

void    UDGraph::insertArc(UVex* t_vex, UVex* h_vex, ArcType arc) {
    if (t_vex && h_vex) {
        UInt8 t_idx = getVexIndex(t_vex);
        UInt8 h_idx = getVexIndex(h_vex);
        if (t_idx >= 0 && h_idx >= 0) {
            arcs[t_idx][h_idx].value = arc;
            arcs[h_idx][t_idx].value = arc;
            ++arc_nums;
        } else {
            ferr << "对空顶点的非法操作！" << endl;
            exit(ERROR);
        }
    } else {
        ferr << "对空顶点的非法操作！" << endl;
        exit(ERROR);
    }
}

ArcType UDGraph::deleteArc(UVex* t_vex, UVex* h_vex) {
    if (t_vex && h_vex) {
        UInt8 t_idx = getVexIndex(t_vex);
        UInt8 h_idx = getVexIndex(h_vex);
        ArcType arc = arcs[t_idx][h_idx].value;
        if (t_idx >= 0 && h_idx >= 0) {
            arcs[t_idx][h_idx].value = NULL_ARC;
            arcs[h_idx][t_idx].value = NULL_ARC;
            --arc_nums;
            return arc;
        } else {
            ferr << "对空顶点的非法操作！" << endl;
            exit(ERROR);
        }
    } else {
        ferr << "对空顶点的非法操作！" << endl;
        exit(ERROR);
    }
}

void    UDGraph::DFSTraverse(void(*visit)(VexType &data)) {
    UInt32 vex_nums = getVexNums();
    bool *visited = new bool[vex_nums];
    UInt8 *order = new UInt8[vex_nums];
    stack<UVex*>stack;
    UVex *cur_vex, *ner_vex;
    UInt8 index;
    memset(visited, 0, sizeof(bool)* vex_nums);
    memset(order, 0, sizeof(UInt8)* vex_nums);
    for (UInt8 i = 0; i < vex_nums; ++i) {
        if (!visited[i]) {
            cur_vex = getIndexVex(i);
            visit(cur_vex->data);
            visited[i] = true;
            stack.push(cur_vex);
            while (!stack.empty()) {
                cur_vex = stack.top();
                UInt8 j;
                index = getVexIndex(cur_vex);
                for (j = order[index]; j < vex_nums; ++j) {
                    if (arcs[index][j].value != NULL_ARC && !visited[j]) {
                        order[index] = j + 1;
                        break;
                    }
                }
                if (j < vex_nums) {
                    ner_vex = getIndexVex(j);
                    visit(ner_vex->data);
                    visited[j] = true;
                    stack.push(ner_vex);
                } else {
                    stack.pop();
                }
            }
        }
    }
    delete visited;
    delete order;
}

void    UDGraph::BFSTraverse(void(*visit)(VexType &data)) {
    queue<UVex*>queue;
    UVex *cur_vex, *first_vex, *next_vex;
    bool *visited = new bool[vex_nums];
    memset(visited, 0, sizeof(bool)* vex_nums);
    for (UInt8 i = 0; i < vex_nums; ++i) {
        if (!visited[i]) {
            cur_vex = getIndexVex(i);
            visit(cur_vex->data);
            visited[getVexIndex(cur_vex)] = true;
            queue.push(cur_vex);
            while (!queue.empty()) {
                cur_vex = queue.front();
                queue.pop();
                first_vex = firstVex(cur_vex);
                if (first_vex) {
                    if (!visited[getVexIndex(first_vex)]) {
                        visit(first_vex->data);
                        visited[getVexIndex(first_vex)] = true;
                        queue.push(first_vex);
                    }
                    next_vex = nextVex(cur_vex, first_vex);
                    while (next_vex) {
                        if (!visited[getVexIndex(next_vex)]) {
                            visit(next_vex->data);
                            visited[getVexIndex(next_vex)] = true;
                            queue.push(next_vex);
                        }
                        next_vex = nextVex(cur_vex, next_vex);
                    }
                }
            }
        }
    }
    delete visited;
}

void    UDGraph::show() {
    cout << "图的存储结构显示如下：" << endl;
    cout << "顶点集：";
    for (UInt8 j = 0; j < vex_nums; ++j)
        cout << " " << vexs[j].data;
    cout << endl;
    for (UInt8 i = 0; i < vex_nums; ++i) {
        cout << "顶点：" << vexs[i].data << " ";
        for (UInt8 j = 0; j < vex_nums; ++j) {
            if (arcs[i][j].value != NULL_ARC )
                cout << " " << arcs[i][j].value;
            else 
                cout << " x";
        }
        cout << endl;
    }
}

void    UDGraph::visit(VexType& data) {
    //do some visit operation
    cout << " " << data;
}

UInt8   UDGraph::getDataIndex(VexType data) {
    for (UInt8 i = 0; i < vex_nums; ++i) {
        if (vexs[i].data == data)  return i;
    }
    return -1;
}

UInt8   UDGraph::getVexIndex(UVex* vex) {
    UInt8 index = vex - vexs;
    if (index < 0 || index >= vex_nums)     return -1;
    else    return index;
}

UVex*   UDGraph::getIndexVex(UInt8 index) {
    return vexs + index;
}

UInt32  UDGraph::connectedCompnent() {
    UInt32 connected_count = 0;
    stack<UVex*> stack;
    UInt32  vex_nums = getVexNums();
    UInt8 index;
    UVex *cur_vex, *ner_vex;
    bool*   visited = new bool[vex_nums];
    memset(visited, 0, sizeof(bool)* vex_nums);
    int*    order = new int[vex_nums];
    memset(order, 0, sizeof(int)* vex_nums);
    for (UInt8 i = 0; i < vex_nums; ++i) {
        if (!visited[i]) {
            ++connected_count;
            cout << "第" << connected_count << "个连通分量：";
            cur_vex = getIndexVex(i);
            visited[i] = true;
            cout << " " << cur_vex->data;
            stack.push(cur_vex);
            while (!stack.empty()) {
                cur_vex = stack.top();
                index = getVexIndex(cur_vex);
                UInt32 j;
                for (j = order[index]; j < vex_nums; ++j) {
                    if (arcs[index][j].value != NULL_ARC && !visited[j]) {
                        order[index] = j + 1;
                        break;
                    }
                }
                if (j < vex_nums) {
                    ner_vex = getIndexVex(j);
                    visited[j] = true;
                    cout << " " << ner_vex->data;
                    stack.push(ner_vex);
                } else {
                    stack.pop();
                }
            }
            cout << endl;
        }
    }
    delete visited;
    delete order;
    return connected_count;
}

Tree*   UDGraph::SpanTree() {
    Tree *tree = new Tree;
    tree->InsertChild(NULL, '0');
    TreeNode *parent;
    UInt32 vex_nums = getVexNums();
    bool* visited = new bool[vex_nums];
    memset(visited, 0, sizeof(bool)* vex_nums);
    int* order = new int[vex_nums];
    memset(order, 0, sizeof(int)* vex_nums);
    UVex *cur_vex, *ner_vex;
    UInt32 index;
    stack<UVex*> vex_stack;
    stack<TreeNode*> tree_node;
    for (UInt32 i = 0; i < vex_nums; ++i) {
        if (!visited[i]) {
            parent = tree->getRoot();
            cur_vex = getIndexVex(i);
            parent =  tree->InsertChild(parent, cur_vex->data);
            visited[i] = true;
            vex_stack.push(cur_vex);
            tree_node.push(parent);
            while (!vex_stack.empty()) {
                cur_vex = vex_stack.top();
                parent = tree_node.top();
                index = getVexIndex(cur_vex);
                UInt32 j;
                for (j = order[index]; j < vex_nums; ++j) {
                    if (arcs[index][j].value != NULL_ARC && !visited[j]) {
                        order[index] = j + 1;
                        break;
                    }
                }
                if (j < vex_nums) {
                    ner_vex = getIndexVex(j);
                    parent = tree->InsertChild(parent, ner_vex->data);
                    visited[j] = true;
                    vex_stack.push(ner_vex);
                    tree_node.push(parent);
                } else {
                    vex_stack.pop();
                    tree_node.pop();
                }
            }
        }
    }
    delete visited;
    delete order;
    return tree;
}

Tree*   UDGraph::primMinSpanTree() {
    Tree* tree = new Tree;
    UInt32 vex_nums = getVexNums();
    TreeNode* *adj_vex = new TreeNode*[vex_nums];
    Int32 *cost = new Int32[vex_nums];
    bool   *chosed = new bool[vex_nums];
    cost[0] = 0;
    chosed[0] = true;
    UInt32 total_cost = 0;
    UVex *cur_vex = getIndexVex(0);
    TreeNode* parent = tree->InsertChild(NULL, cur_vex->data);
    for (UInt32 i = 1; i < vex_nums; ++i) {
        adj_vex[i] = parent;
        cost[i] = arcs[0][i].value;
        chosed[i] = false;
    }
    for (UInt32 i = 1; i < vex_nums; ++i) {
        UInt32 next;
        ArcType min_value = NULL_ARC;
        for (UInt32 j = 0; j < vex_nums; ++j) {
            if (!chosed[j] && cost[j] < min_value) {
                next = j;
                min_value = cost[j];
            }
        }
        cur_vex = getIndexVex(next);
        parent = tree->InsertChild(adj_vex[next], cur_vex->data);
        total_cost += min_value;
        cost[next] = 0;
        chosed[next] = true;
        for (UInt32 j = 0; j < vex_nums; ++j) {
            if (cost[j] > arcs[next][j].value) {
                cost[j] = arcs[next][j].value;
                adj_vex[j] = parent;
            }
        }
    }
    delete adj_vex;
    delete cost;
    delete chosed;
    return tree;
}

typedef struct {
    ArcType value;
    UInt32 l1;
    UInt32 l2;
} Link;

int compare(const void *a, const void *b) {
    Link *A = (Link *)a;
    Link *B = (Link *)b;
    return (A->value) - (B->value);
}

void connect(UInt32 *connect_cnt, UInt32 nums, UInt32 l1, UInt32 l2) {
    for (UInt32 i = 0; i < nums; ++i) {
        if (connect_cnt[i] == l2)   connect_cnt[i] = l1;
    }
}

Tree*   UDGraph::KruskalMinSpanTree() {
    Tree* tree = new Tree;
    Link *link = new Link[arc_nums];
    UInt32 count = 0, total_cost = 0;
    bool   *inserted = new bool[vex_nums];
    memset(inserted, 0, sizeof(bool)* vex_nums);
    UInt32 *connect_cnt = new UInt32[vex_nums];
    for (UInt32 i = 0; i < vex_nums; ++i) {
        connect_cnt[i] = i;
        for (UInt32 j = i; j < vex_nums; ++j) {
            if (arcs[i][j].value != NULL_ARC) {
                link[count++] = { arcs[i][j].value, i, j };
            }
        }
    }
    qsort(link, arc_nums, sizeof(Link), compare);
    count = 0;
    UDGraph graph;
    UVex *vex1, *vex2, *new_vex1, *new_vex2;
    for (UInt32 i = 1; i < vex_nums; ++i) {
        while (connect_cnt[link[count].l1] == connect_cnt[link[count].l2]) {
            ++count;
        }
        total_cost += link[count].value;
        vex1 = getIndexVex(link[count].l1);
        vex2 = getIndexVex(link[count].l2);
        if (!inserted[link[count].l1]) {
            new_vex1 = graph.insertVex(vex1->data);
            inserted[link[count].l1] = true;
        } else {
            new_vex1 = graph.locateVex(vex1->data);
        }
        if (!inserted[link[count].l2]) {
            new_vex2 = graph.insertVex(vex2->data);
            inserted[link[count].l2] = true;
        } else {
            new_vex2 = graph.locateVex(vex2->data);
        }
        connect(connect_cnt, vex_nums, connect_cnt[link[count].l1], connect_cnt[link[count].l2]);
        graph.insertArc(new_vex1, new_vex2, link[count++].value);
    }
    return graph.SpanTree();
}

void  UDGraph::articulationPoint() {
    stack<UVex *>stack;
    UInt32 vex_nums = getVexNums(), index, par_index, count = 0;;
    UInt32 *visited = new UInt32[vex_nums];
    UInt32 *low = new UInt32[vex_nums];
    UInt32 *order = new UInt32[vex_nums];
    bool   *point = new bool[vex_nums];
    memset(visited, 0, sizeof(UInt32)* vex_nums);
    memset(order, 0, sizeof(UInt32)* vex_nums);
    memset(point, 0, sizeof(bool)* vex_nums);
    UVex *cur_vex, *ner_vex, *par_vex;
    for (UInt32 i = 0; i < vex_nums; ++i) {
        if (!visited[i]) {
            count = 0;
            cur_vex = getIndexVex(i);
            visited[i] = low[i] = ++count;
            stack.push(cur_vex);
            while (!stack.empty()) {
                cur_vex = stack.top();
                index = getVexIndex(cur_vex);
                UInt32 j;
                for (j = order[index]; j < vex_nums; ++j) {
                    if (arcs[index][j].value != NULL_ARC) {
                        if (!visited[j]) {
                            order[index] = j + 1;
                            break;
                        } else if (visited[j] < low[index]) {
                            low[index] = visited[j];
                        }
                    }
                }
                if (j < vex_nums) {
                    ner_vex = getIndexVex(j);
                    visited[j] = low[j] = ++count;
                    stack.push(ner_vex);
                } else {
                    stack.pop();
                    if (!stack.empty()) {
                        par_vex = stack.top();
                        par_index = getVexIndex(par_vex);
                        if (low[index] < low[par_index])    low[par_index] = low[index];
                        if (low[index] >= visited[par_index]) {
                            point[par_index] = true;
                        }
                    }
                }
            }
        }
    }
    cout << "关节点：";
    for (UInt32 i = 0; i < vex_nums; ++i) {
        if (point[i])   cout << " " << getIndexVex(i)->data << " ";
    }
    cout << endl;
    delete order;
    delete visited;
    delete low;
    delete point;
}
