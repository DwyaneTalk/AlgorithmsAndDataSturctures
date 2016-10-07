#include "../inc/DGraph.h"

DGraph::DGraph() {
    if (vexs = new DVex[MAXELEMNUM]) {
        graph_type = DN;
        arc_nums = 0;
        vex_nums = 0;
    } else {
        ferr << "申请内存失败！" << endl;
        exit(OVER);
    }
}

DGraph::~DGraph() {
    for (UInt8 i = 0; i < vex_nums; ++i) {
        DArc* list_arc = getIndexVex(i)->t_list, *free_arc;
        while (list_arc) {
            free_arc = list_arc;
            list_arc = list_arc->tlink;
            delete free_arc;
        }
    }
    delete vexs;
}

void DGraph::init() {
    DVex* vex;
    DArc* list_arc, *free_arc;
    for (UInt8 i = 0; i < vex_nums; ++i) {
        vex = getIndexVex(i);
        list_arc = vex->t_list;
        vex->h_list = NULL;
        vex->t_list = NULL;
        while (list_arc) {
            free_arc = list_arc;
            list_arc = list_arc->tlink;
            delete free_arc;
        }
    }
    vex_nums = 0;
    arc_nums = 0;
}

void DGraph::createGraph() {
    fin >> vex_nums >> arc_nums;
    if (vex_nums > MAXELEMNUM) {
        ferr << "顶点时超过最大限制！" << endl;
        exit(ERROR);
    }
    for (UInt8 i = 0; i < vex_nums; ++i) {
        fin >> vexs[i].data;
    }
    VexType t_data, h_data;
    UInt8 t_index, h_index;
    UInt32 arc_value;
    DArc* new_arc;
    DArc *t_list, *h_list;
    DVex *t_vex, *h_vex;
    for (UInt8 i = 0; i < arc_nums; ++i) {
        fin >> t_data >> h_data >> arc_value;
        t_index = getDataIndex(t_data);
        h_index = getDataIndex(h_data);
        new_arc = new DArc(arc_value, t_index, h_index);
        t_vex = getIndexVex(t_index);
        h_vex = getIndexVex(h_index);
        if (!t_vex->t_list) t_vex->t_list = new_arc;
        else {
            t_list = t_vex->t_list;
            while (t_list->tlink) {
                t_list = t_list->tlink;
            }
            t_list->tlink = new_arc;
        }
        if (!h_vex->h_list) h_vex->h_list = new_arc;
        else {
            h_list = h_vex->h_list;
            while (h_list->hlink) {
                h_list = h_list->hlink;
            }
            h_list->hlink = new_arc;
        }
    }
}

DVex* DGraph::locateVex(VexType data) {
    for (UInt8 i = 0; i < vex_nums; ++i) {
        if (vexs[i].data == data) {
            return vexs + i;
        }
    }
    return NULL;
}

VexType DGraph::getVexData(DVex *vex) {
    if (vex) {
        return vex->data;
    } else {
        ferr << "对空顶点非法操作！" << endl;
        exit(ERROR);
    }
}

void DGraph::setVexData(DVex *vex, VexType data) {
    if (vex) {
        vex->data = data;
    } else {
        ferr << "对空顶点非法操作！" << endl;
        exit(ERROR);
    }
}

DArc* DGraph::locateArc(DVex* t_vex, DVex* h_vex) {
    if (t_vex && h_vex) {
        UInt8 index = getVexIndex(h_vex);
        DArc* arc_list = t_vex->t_list;
        while (arc_list && arc_list->hidx != index) {
            arc_list = arc_list->tlink;
        }
        return arc_list;
    } else {
        ferr << "对空顶点非法操作！" << endl;
        exit(ERROR);
    }
}

ArcType DGraph::getArcValue(DArc* arc) {
    if (arc)    return arc->value;
    else {
        ferr << "对空弧非法操作！" << endl;
        exit(ERROR);
    }
}

void DGraph::setArcValue(DArc* arc, ArcType value) {
    if (arc)    arc->value = value;
    else {
        ferr << "对空弧非法操作！" << endl;
        exit(ERROR);
    }
}

UInt8 DGraph::getVexInDegree(DVex *vex) {
    if (vex) {
        UInt8 degree = 0;
        DArc* arc_list = vex->h_list;
        while (arc_list) {
            ++degree;
            arc_list = arc_list->hlink;
        }
        return degree;
    } else {
        ferr << "对空顶点非法操作！" << endl;
        exit(ERROR);
    }
}

UInt8 DGraph::getVexOutDegree(DVex *vex) {
    if (vex) {
        UInt8 degree = 0;
        DArc* arc_list = vex->t_list;
        while (arc_list) {
            ++degree;
            arc_list = arc_list->tlink;
        }
        return degree;
    } else {
        ferr << "对空顶点非法操作！" << endl;
        exit(ERROR);
    }

}

//求以vex为尾的弧
DArc* DGraph::adjArc(DVex* vex, DArc* cur_arc) {
    if (!vex) {
        ferr << "对空顶点非法操作！" << endl;
        exit(ERROR);
    }
    if (!cur_arc) {
        return vex->t_list;
    } else {
        DArc* arc_list = vex->t_list;
        while (arc_list && arc_list != cur_arc) {
            arc_list = arc_list->tlink;
        }
        if (arc_list && arc_list->tlink) {
            return arc_list->tlink;
        } else {
            return NULL;
        }
    }
}

//求以vex为尾的邻接顶点
DVex* DGraph::adjVex(DVex *vex, DVex *cur_vex) {
    if (!vex) {
        ferr << "对空顶点非法操作！" << endl;
        exit(ERROR);
    }
    if (!cur_vex) {
        if (vex->t_list)
            return vexs + vex->t_list->hidx;
        else
            return NULL;
    } else {
        UInt8 index = getVexIndex(cur_vex);
        DArc* arc_list = vex->t_list;
        while (arc_list && arc_list->hidx != index) {
            arc_list = arc_list->tlink;
        }
        if (arc_list && arc_list->tlink) {
            return vexs + arc_list->tlink->hidx;
        } else {
            return NULL;
        }
    }
}

//求以vex为头的弧
DArc* DGraph::adjReverseArc(DVex* vex, DArc* cur_arc) {
    if (!vex) {
        ferr << "对空顶点非法操作！" << endl;
        exit(ERROR);
    }
    if (!cur_arc) {
        return vex->h_list;
    } else {
        DArc* arc_list = vex->h_list;
        while (arc_list && arc_list != cur_arc) {
            arc_list = arc_list->hlink;
        }
        if (arc_list && arc_list->hlink) {
            return arc_list->hlink;
        } else {
            return NULL;
        }
    }
}

//求以vex为头的邻接顶点
DVex* DGraph::adjReverseVex(DVex *vex, DVex *cur_vex) {
    if (!vex) {
        ferr << "对空顶点非法操作！" << endl;
        exit(ERROR);
    }
    if (!cur_vex) {
        if (vex->h_list)
            return vexs + vex->h_list->tidx;
        else
            return NULL;
    } else {
        UInt8 index = getVexIndex(cur_vex);
        DArc* arc_list = vex->h_list;
        while (arc_list && arc_list->tidx != index) {
            arc_list = arc_list->hlink;
        }
        if (arc_list && arc_list->hlink) {
            return vexs + arc_list->hlink->tidx;
        } else {
            return NULL;
        }
    }
}

DVex* DGraph::insertVex(VexType data) {
    if (vex_nums < MAXELEMNUM) {
        vexs[vex_nums].data = data;
        return vexs + vex_nums++;
    } else {
        ferr << "顶点达到最大数目，无法增加！" << endl;
        exit(ERROR);
    }
}

VexType DGraph::deleteVex(DVex *vex) {
    VexType data = getVexData(vex);
    UInt8 index = getVexIndex(vex);
    DArc* t_list = vex->t_list, *h_list = vex->h_list, *free_arc;
    while (t_list) {
        free_arc = t_list;
        t_list = t_list->tlink;
        deleteArc(vex, getIndexVex(free_arc->hidx));
    }
    while (h_list) {
        free_arc = h_list;
        h_list = h_list->hlink;
        deleteArc(getIndexVex(free_arc->tidx), vex);
    }
    vexs[index] = vexs[--vex_nums];
    t_list = vexs[index].t_list;
    h_list = vexs[index].h_list;
    while (t_list) {
        t_list->tidx = index;
        t_list = t_list->tlink;
    }
    while (h_list) {
        h_list->hidx = index;
        h_list = h_list->hlink;
    }
    return data;
}

void DGraph::insertArc(DVex* t_vex, DVex* h_vex, ArcType value) {
    if (t_vex && h_vex) {
        DArc* new_arc = new DArc(value, getVexIndex(t_vex), getVexIndex(h_vex));
        DArc *t_list = t_vex->t_list, *h_list = h_vex->h_list;
        if (!t_list)    t_vex->t_list = new_arc;
        else {
            while (t_list->tlink) {
                t_list = t_list->tlink;
            }
            t_list->tlink = new_arc;
        }
        if (!h_list)    h_vex->h_list = new_arc;
        else {
            while (h_list->hlink) {
                h_list = h_list->hlink;
            }
            h_list->hlink = new_arc;
        }
        ++arc_nums;
    } else {
        ferr << "对空顶点非法操作！" << endl;
        exit(ERROR);
    }
}

ArcType DGraph::deleteArc(DVex* t_vex, DVex* h_vex) {
    if (t_vex && h_vex) {
        DArc *cur_arc = adjArc(t_vex, NULL), *free_arc = NULL;
        UInt32 index = getVexIndex(h_vex);
        if (cur_arc && cur_arc->hidx == index) {
            free_arc = cur_arc;
            t_vex->t_list = free_arc->tlink;
        } else {
            while (cur_arc && cur_arc->tlink && cur_arc->tlink->hidx != index) {
                cur_arc = cur_arc->tlink;
            }
            if (cur_arc && cur_arc->tlink) {
                free_arc = cur_arc->tlink;
                cur_arc->tlink = free_arc->tlink;
            } else {
                ferr << "该弧不存在！" << endl;
                exit(ERROR);
            }
        }
        cur_arc = h_vex->h_list;
        index = getVexIndex(t_vex);
        if (cur_arc && cur_arc->tidx == index) {
            h_vex->h_list = free_arc->hlink;
        } else {
            while (cur_arc && cur_arc->hlink && cur_arc->hlink->tidx != index) {
                cur_arc = cur_arc->hlink;
            }
            if (cur_arc && cur_arc->hlink) {
                cur_arc->hlink = free_arc->hlink;
            } else {
                ferr << "该弧不存在！" << endl;
                exit(ERROR);
            }
        }
        if (cur_arc) {
            ArcType arc_value = free_arc->value;
            delete free_arc;
            --arc_nums;
            return arc_value;
        } else {
            ferr << "该弧不存在！" << endl;
            exit(ERROR);
        }
     } else {
        ferr << "对空顶点非法操作！" << endl;
        exit(ERROR);
    }
}

void DGraph::DFSTraverse(void(*visit)(VexType &data)) {
    stack<DVex*>stack;
    DVex *cur_vex, *ner_vex, **pre_vex = new DVex*[vex_nums];
    UInt8 index, idx;
    bool *visited = new bool[vex_nums];
    memset(visited, 0, sizeof(bool)* vex_nums);
    memset(pre_vex, 0, sizeof(DVex*)* vex_nums);
    for (UInt8 i = 0; i < vex_nums; ++i) {
        if (!visited[i]) {
            cur_vex = getIndexVex(i);
            visit(cur_vex->data);
            visited[i] = true;
            stack.push(cur_vex);
            while (!stack.empty()) {
                cur_vex = stack.top();
                index = getVexIndex(cur_vex);
                ner_vex = pre_vex[index];
                while (ner_vex = adjVex(cur_vex, ner_vex)) {
                    idx = getVexIndex(ner_vex);
                    if (!visited[idx]) {
                        visit(ner_vex->data);
                        visited[idx] = true;
                        pre_vex[index] = ner_vex;
                        stack.push(ner_vex);
                        break;
                    }
                }
                if (!ner_vex) {
                    stack.pop();
                }
            }
        }
    }
    delete visited;
}

void DGraph::BFSTraverse(void(*visit)(VexType &data)) {
    queue<DVex*>queue;
    bool *visited = new bool[vex_nums];
    DVex *cur_vex, *ner_vex;
    UInt8 index;
    memset(visited, 0, sizeof(bool)* vex_nums);
    for (UInt8 i = 0; i < vex_nums; ++i) {
        if (!visited[i]) {
            cur_vex = getIndexVex(i);
            visit(cur_vex->data);
            visited[i] = true;
            queue.push(cur_vex);
            while (!queue.empty()) {
                cur_vex = queue.front();
                queue.pop();
                ner_vex = NULL;
                while (ner_vex = adjVex(cur_vex, ner_vex)) {
                    index = getVexIndex(ner_vex);
                    if (!visited[index]) {
                        visit(ner_vex->data);
                        visited[index] = true;
                        queue.push(ner_vex);
                    }
                }
            }
        }
    }
    delete visited;
}

void DGraph::show() {
    cout << "图的存储结构如下：" << endl;
    DVex *vex, *cur_vex;
    DArc *cur_arc;
    for (UInt8 i = 0; i < vex_nums; ++i) {
        vex = getIndexVex(i);
        cout << "顶点：" << getVexData(vex) << " 入度(" << (Int32)getVexInDegree(vex) << ") 出度(" << (Int32)getVexOutDegree(vex) << ") 对应的邻接顶点： ";
        cur_arc = adjArc(vex, NULL);
        while (cur_arc) {
            cur_vex = vexs + cur_arc->hidx;
            cout << "   " << getVexData(cur_vex) << "(" << getArcValue(cur_arc) << ")";
            cur_arc = cur_arc->tlink;
        }
        cout << endl;
    }
}

void DGraph::visit(VexType &data) {
    //do some operation
    cout << " " << data;
}

UInt8 DGraph::getDataIndex(VexType data) {
    UInt8 index;
    for (index = 0; index < vex_nums; ++index) {
        if (vexs[index].data == data)   break;
    }
    if (index >= vex_nums)  return -1;
    else    return index;
}

UInt8 DGraph::getVexIndex(DVex* vex) {
    if (vex) {
        UInt8 index = vex - vexs;
        if (index >= 0 && index < vex_nums) return index;
        else return -1;
    } else {
        ferr << "无效的操作顶点！" << endl;
        exit(ERROR);
    }
}

DVex* DGraph::getIndexVex(UInt8 index) {
    if (index < 0 || index >= vex_nums) {
        ferr << "不合法的索引下标！" << endl;
        exit(ERROR);
    }
    return vexs + index;
}

DGraph* DGraph::complementGraph() {
    DGraph  *graph = new DGraph;
    UInt32 vex_nums = getVexNums(), arc_nums = getArcNums();
    GType graph_type = getType();
    DArc *old_hlist, **new_tlist;
    graph->setType(graph_type);
    graph->setVexNums(vex_nums);
    graph->setArcNums(arc_nums);
    DVex *new_vex, *old_vex, *ner_vex;
    for (UInt32 i = 0; i < vex_nums; ++i) {
        old_vex = getIndexVex(i);
        old_hlist = old_vex->h_list;
        new_vex = graph->getIndexVex(i);
        new_tlist = &new_vex->t_list;
        graph->setVexData(new_vex, old_vex->data);
        while (old_hlist) {
            (*new_tlist) = new DArc(old_hlist->value, old_hlist->hidx, old_hlist->tidx);
            ner_vex = graph->getIndexVex(old_hlist->tidx);
            (*new_tlist)->hlink = ner_vex->h_list;
            ner_vex->h_list = (*new_tlist);
            new_tlist = &(*new_tlist)->tlink;
            old_hlist = old_hlist->hlink;
        }
    }
    return graph;
}

UInt32 DGraph::weaklyConnectedCompnent(){
    stack<DVex*> stack;
    UInt32 vex_nums = getVexNums();
    UInt32 index, idx;
    UInt32 connected_count = 0;
    DVex *cur_vex, *ner_vex, **pre_vex = new DVex*[vex_nums];
    bool *visited = new bool[vex_nums];
    memset(visited, 0, sizeof(bool)* vex_nums);
    memset(pre_vex, 0, sizeof(DVex*)* vex_nums);
    cout << "有向图的弱连通分量如下：" << endl;
    for (UInt32 i = 0; i < vex_nums; ++i) {
        if (!visited[i]) {
            ++connected_count;
            cout << "第" << connected_count << "个弱连通分量：";
            cur_vex = getIndexVex(i);
            cout << " " << cur_vex->data << " ";
            visited[i] = true;
            stack.push(cur_vex);
            while (!stack.empty()) {
                cur_vex = stack.top();
                index = getVexIndex(cur_vex);
                ner_vex = pre_vex[index];
                while (ner_vex = adjVex(cur_vex, ner_vex)) {
                    idx = getVexIndex(ner_vex);
                    if (!visited[idx]) {
                        cout << " " << ner_vex->data << " ";
                        visited[idx] = true;
                        pre_vex[index] = ner_vex;
                        stack.push(ner_vex);
                        break;
                    }
                }
                if (!ner_vex) {
                    stack.pop();
                }
            }
            cout << endl;
        }
    }
    delete visited;
    return connected_count;
}

UInt32 DGraph::strongConnectedCompnent(){
    DGraph *c_graph = complementGraph();
    c_graph->show();
    stack<DVex*> stack;
    UInt32 index, idx, count = 0, weakly_cnt = 0, strong_cnt = 0 , vex_nums = getVexNums();
    DVex *cur_vex, *ner_vex, **pre_vex = new DVex*[vex_nums];
    bool *visited = new bool[vex_nums];
    UInt32 *finished = new UInt32[vex_nums + 1];
    UInt32 *new_finished = finished;
    memset(visited, 0, sizeof(bool)* vex_nums);
    memset(pre_vex, 0, sizeof(DVex*)* vex_nums);
    cout << "有向图的强连通分量测试：" << endl;
    for (UInt32 i = 0; i < vex_nums; ++i) {
        if (!visited[i]) {
            count = 0;
            cur_vex = getIndexVex(i);
            visited[i] = true;
            stack.push(cur_vex);
            while (!stack.empty()) {
                cur_vex = stack.top();
                index = getVexIndex(cur_vex);
                ner_vex = pre_vex[index];
                while (ner_vex = adjVex(cur_vex, ner_vex)) {
                    idx = getVexIndex(ner_vex);
                    if (!visited[idx]) {
                        visited[idx] = true;
                        pre_vex[index] = ner_vex;
                        stack.push(ner_vex);
                        break;
                    }
                }
                if (!ner_vex) {
                    ++count;
                    *(++new_finished) = getVexIndex(stack.top());
                    stack.pop();
                }
            }
            strong_cnt = c_graph->strongConnectedCompnentResult(new_finished - count, count, strong_cnt);
        }
    }
    delete visited;
    delete c_graph;
    delete finished;
    return strong_cnt;
}

UInt32 DGraph::strongConnectedCompnentResult(UInt32 *finished, UInt32 vex_cnt, UInt32 strong_cnt){
    UInt32 vex_nums = getVexNums(),index, idx;
    stack<DVex*> stack;
    DVex *cur_vex, *ner_vex, **pre_vex = new DVex*[vex_nums];
    bool *visited = new bool[vex_nums];
    memset(pre_vex, 0, sizeof(DVex*)* vex_nums);
    for (UInt32 i = 0; i < vex_nums; ++i)   visited[i] = true;
    for (UInt32 i = 1; i <= vex_cnt; ++i)    visited[finished[i]] = false;
    for (UInt32 i = vex_cnt; i > 0; --i) {
        UInt32 j = finished[i];
        if (!visited[j]) {
            ++strong_cnt;
            cout << "第" << strong_cnt << "个强连通分量：";
            cur_vex = getIndexVex(j);
            cout << " " << cur_vex->data << " ";
            visited[j] = true;
            stack.push(cur_vex);
            while (!stack.empty()) {
                cur_vex = stack.top();
                index = getVexIndex(cur_vex);
                ner_vex = pre_vex[index];
                while (ner_vex = adjVex(cur_vex, ner_vex)) {
                    idx = getVexIndex(ner_vex);
                    if (!visited[idx]) {
                        cout << " " << ner_vex->data << " ";
                        visited[idx] = true;
                        pre_vex[index] = ner_vex;
                        stack.push(ner_vex);
                        break;
                    }
                }
                if (!ner_vex) {
                    stack.pop();
                }
            }
            cout << endl;
        }
    }
    delete visited;
    return strong_cnt;
}

//AOV网络(activity on vertex network)，有向无环图
VexType*   DGraph::topoLogicalSort(){
    UInt32 vex_nums = getVexNums(), count = 0;
    UInt32 *in_degree = new UInt32[vex_nums];
    VexType *topo_order = new VexType[vex_nums];
    stack<DVex*> stack;
    DVex *cur_vex, *ner_vex;
    UInt32 cur_idx, ner_idx;
    for (UInt32 i = 0; i < vex_nums; ++i) {
        cur_vex = getIndexVex(i);
        in_degree[i] = getVexInDegree(cur_vex);
        if (!in_degree[i])  stack.push(cur_vex);
    }
    while (!stack.empty()) {
        cur_vex = stack.top();
        cur_idx = getVexIndex(cur_vex);
        stack.pop();
        topo_order[count++] = cur_vex->data;
        ner_vex = NULL;
        while (ner_vex = adjVex(cur_vex, ner_vex)) {
            ner_idx = getVexIndex(ner_vex);
            if (!(--in_degree[ner_idx]))   stack.push(ner_vex);
        }
    }
    delete in_degree;
    if (count < vex_nums) {
        delete topo_order;
        ferr << "有向图不能求拓扑排序" << endl;
        return NULL;
    } else {
        return topo_order;
    }
}

//AOE网络(activity on edge network)，有向无环带权图，且只有一个入度为0和一个出度为0的点
VexType*   DGraph::topoLogicalOrder(UInt32 *ve){
    UInt32 vex_nums = getVexNums(), count = 0;
    UInt32 *in_degree = new UInt32[vex_nums], out_degree;
    VexType *topo_order = new VexType[vex_nums];
    stack<DVex*> stack;
    DVex *cur_vex, *ner_vex;
    DArc *ner_arc;
    UInt32 cur_idx, ner_idx;
    Int32 in_vex = -1, out_vex = -1;
    for (UInt32 i = 0; i < vex_nums; ++i) {
        ve[i] = 0;
        cur_vex = getIndexVex(i);
        in_degree[i] = getVexInDegree(cur_vex);
        if (!in_degree[i]) {
            if (in_vex >= 0) {
                delete in_degree;
                delete topo_order;
                return NULL;
            }
            in_vex = i;
            stack.push(cur_vex);
        }
        out_degree = getVexOutDegree(cur_vex);
        if (!out_degree) {
            if (out_vex >= 0) {
                delete in_degree;
                delete topo_order;
                return NULL;
            }
            out_vex = i;
        }
    }
    if (out_vex < 0) {
        delete in_degree;
        delete topo_order;
        return NULL;
    }
    while (!stack.empty()) {
        cur_vex = stack.top();
        cur_idx = getVexIndex(cur_vex);
        stack.pop();
        topo_order[count++] = cur_vex->data;
        ner_arc = NULL;
        while (ner_arc = adjArc(cur_vex, ner_arc)) {
            ner_idx = ner_arc->hidx;
            ner_vex = getIndexVex(ner_idx);
            if (!(--in_degree[ner_idx]))   stack.push(ner_vex);
            if (ve[cur_idx] + ner_arc->value > ve[ner_idx]) ve[ner_idx] = ve[cur_idx] + ner_arc->value;
        }
    }
    delete in_degree;
    if (count < vex_nums) {
        delete topo_order;
        return NULL;
    } else {
        return topo_order;
    }
}

typedef struct{
    DArc    *arc;
    UInt32  ae;
    UInt32  al;
}ArcValue;

DArc*   DGraph::criticalPath(){
    UInt32 vex_nums = getVexNums(), arc_nums = getArcNums();
    UInt32 cur_idx, ner_idx, arc_cnt = 0;
    UInt32 *ve = new UInt32[vex_nums], *vl = new UInt32[vex_nums];
    ArcValue *arc_value = new ArcValue[arc_nums];
    VexType *topo_order = topoLogicalOrder(ve);
    DVex *cur_vex;
    DArc *ner_arc, *critial_arc = NULL, *pre_arc = NULL;
    if (!topo_order) {
        ferr << "有向图不能求关键路径" << endl;
        delete ve;
        delete vl;
        delete arc_value;
        delete topo_order;
        return NULL;
    }
    vl[vex_nums - 1] = ve[vex_nums - 1];
    for (Int32 i = vex_nums - 2; i >= 0; --i) {
        cur_vex = locateVex(topo_order[i]);
        cur_idx = getVexIndex(cur_vex);
        ner_arc = NULL;
        while (ner_arc = adjArc(cur_vex, ner_arc)) {
            ner_idx = ner_arc->hidx;
            if (vl[ner_idx] - ner_arc->value < vl[cur_idx]) vl[cur_idx] = vl[ner_idx] - ner_arc->value;
        }
    }
    for (UInt32 i = 0; i < vex_nums; ++i) {
        cur_vex = getIndexVex(i);
        ner_arc = cur_vex->t_list;
        while (ner_arc) {
            arc_value[arc_cnt].arc = ner_arc;
            arc_value[arc_cnt].ae = ve[i];
            arc_value[arc_cnt].al = vl[ner_arc->hidx] - ner_arc->value;
            ++arc_cnt;
            ner_arc = ner_arc->tlink;
        }
    }
    for (UInt32 i = 0; i < arc_nums; ++i) {
        if (arc_value[i].ae == arc_value[i].al) {
            if (!critial_arc) {
                critial_arc = new DArc(arc_value[i].arc->value, arc_value[i].arc->tidx, arc_value[i].arc->hidx);
                pre_arc = critial_arc;
            } else {
                pre_arc->tlink = new DArc(arc_value[i].arc->value, arc_value[i].arc->tidx, arc_value[i].arc->hidx);
                pre_arc = pre_arc->tlink;
            }
        }
    }
    delete ve;
    delete vl;
    delete arc_value;
    delete topo_order;
    return critial_arc;
}

UInt32**   DGraph::dijkstraShortestPath(VexType vex_data){
    UInt32 ver_nums = getVexNums();
    DVex *s_vex = locateVex(vex_data), *cur_vex;
    if (!s_vex) {
        ferr << "源顶点不存在！" << endl;
        exit(ERROR);
    }
    UInt32 s_idx = getVexIndex(s_vex), cur_idx, cur_min;
    DArc *s_arc = s_vex->t_list;
    UInt32 **path_len = new UInt32*[2];
    bool   *vex_set = new bool[vex_nums];
    path_len[0] = new UInt32[vex_nums];
    path_len[1] = new UInt32[vex_nums];
    for (UInt32 i = 0; i < vex_nums; ++i) {
        path_len[0][i] = NULL_ARC;
        path_len[1][i] = s_idx;
        vex_set[i] = 0;
    }
    while (s_arc) {
        path_len[0][s_arc->hidx] = s_arc->value;
        s_arc = s_arc->tlink;
    }
    path_len[0][s_idx] = 0;
    vex_set[s_idx] = true;
    for (UInt32 i = 1; i < vex_nums; ++i) {
        cur_min = NULL_ARC;
        for (UInt32 j = 0; j < vex_nums; ++j) {
            if (!vex_set[j]) {
                if (path_len[0][j] < cur_min) {
                    cur_min = path_len[0][j];
                    cur_idx = j;
                }
            }
        }
        vex_set[cur_idx] = true;
        cur_vex = getIndexVex(cur_idx);
        s_arc = cur_vex->t_list;
        while (s_arc) {
            if (!vex_set[s_arc->hidx]) {
                if (path_len[0][cur_idx] + s_arc->value < path_len[0][s_arc->hidx]) {
                    path_len[0][s_arc->hidx] = path_len[0][cur_idx] + s_arc->value;
                    path_len[1][s_arc->hidx] = cur_idx;
                }
            }
            s_arc = s_arc->tlink;
        }
    }
    return path_len;
}

UInt32***  DGraph::floydShortestPath() {
    UInt32 vex_nums = getVexNums();
    UInt32 ***path = new UInt32**[2];
    DVex *cur_vex;
    DArc *ner_arc;
    path[0] = new UInt32*[vex_nums];
    path[1] = new UInt32*[vex_nums];
    for (UInt32 i = 0; i < vex_nums; ++i) {
        path[0][i] = new UInt32[vex_nums];  //最短路径
        path[1][i] = new UInt32[vex_nums];  //中间结点
        for (UInt32 j = 0; j < vex_nums; ++j) {
            path[0][i][j] = NULL_ARC;
            path[1][i][j] = i;
        }
    }
    for (UInt32 i = 0; i < vex_nums; ++i) {
        cur_vex = getIndexVex(i);
        ner_arc = cur_vex->t_list;
        path[0][i][i] = 0;
        while (ner_arc) {
            path[0][i][ner_arc->hidx] = ner_arc->value;
            ner_arc = ner_arc->tlink;
        }
    }
    for (UInt32 k = 0; k < vex_nums; ++k) {
        for (UInt32 u = 0; u < vex_nums; ++u) {
            for (UInt32 v = 0; v < vex_nums; ++v) {
                if (path[0][u][k] + path[0][k][v] < path[0][u][v]) {
                    path[0][u][v] = path[0][u][k] + path[0][k][v];
                    path[1][u][v] = k;
                }
            }
        }
    }
    return path;
}
