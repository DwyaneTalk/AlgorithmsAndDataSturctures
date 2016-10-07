#ifndef UDGRAPH_H
#define UDGRAPH_H

#include "Util.h"
#include "Tree.h"
#include<stack>
#include<queue>

typedef struct UVex{
    VexType   data;
    VexInfo*       info;   //顶点的附加信息
    UVex(VexInfo* info = NULL) {
        this->info = info;
    }
} UVex;

typedef struct UArc {
    ArcType   value;
    ArcInfo*        info;   //弧的附加信息
    UArc(ArcType value = NULL_ARC, ArcInfo* info = NULL) {
        this->value = value;
        this->info = info;
    }
} UArc;

class UDGraph{   //无向图
private:
    GType   graph_type;
    UInt32  vex_nums;
    UInt32  arc_nums;
    UVex*    vexs;   //顶点集
    UArc**   arcs;   //邻接矩阵

    UInt8   getDataIndex(VexType data);
    UInt8   getVexIndex(UVex* vex);
    UVex*   getIndexVex(UInt8 index);
public:
    UDGraph();
    ~UDGraph();
    void    init();
    void    createGraph();
    GType   getType()       { return graph_type; }
    UInt32  getVexNums()    { return vex_nums; }
    UInt32  getArcNums()    { return arc_nums; }
    bool    isEmpty()       { return !vex_nums; }
    UVex*   locateVex(VexType data);
    UArc*   locateArc(UVex* vex1, UVex* vex2);
    VexType getVexData(UVex* vex);
    void    setVexData(UVex* vex, VexType data);
    UInt8   getVexDegree(UVex *vex);
    UVex*   firstVex(UVex* vex);
    UVex*   nextVex(UVex* vex, UVex* cur_vex);
    UVex*   insertVex(VexType data);
    VexType deleteVex(UVex* vex);
    void    insertArc(UVex* t_vex, UVex* h_vex, ArcType arc);
    ArcType deleteArc(UVex* t_vex, UVex* h_vex);
    void    DFSTraverse(void(*visit)(VexType &data));
    void    BFSTraverse(void(*visit)(VexType &data));
    void    show();
    void    static visit(VexType &data);
    UInt32  connectedCompnent();
    Tree*   SpanTree();
    Tree*   primMinSpanTree();
    Tree*   KruskalMinSpanTree();
    void   articulationPoint();
};

#endif // !UDGRAPH_H
