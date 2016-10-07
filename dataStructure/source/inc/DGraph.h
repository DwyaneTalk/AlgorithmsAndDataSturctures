#ifndef DGRAPH_H
#define DGRAPH_H

#include "Util.h"
#include<stack>
#include<queue>

typedef struct DArc {
    ArcType   value;
    UInt8           tidx;     //指向尾顶点在顶点集的索引
    UInt8           hidx;     //指向头顶点在顶点集的索引
    struct DArc     *tlink;
    struct DArc     *hlink;
    ArcInfo         *info;
    DArc(ArcType value, UInt8 tidx, UInt8 hidx, ArcInfo* info = NULL) {
        this->value = value;
        this->tidx = tidx;
        this->hidx = hidx;
        this->info = info;
        tlink = NULL;
        hlink = NULL;
    }
} DArc;

typedef struct DVex {
    VexType   data;
    DArc*     h_list;
    DArc*     t_list;
    VexInfo*  info;
    DVex(VexInfo *info = NULL) {
        h_list = NULL;
        t_list = NULL;
        this->info = info;
    }
} DVex;


class DGraph{
private:
    GType   graph_type;
    UInt32  vex_nums;
    UInt32  arc_nums;
    DVex*   vexs;    //十字链表存储

    UInt8   getDataIndex(VexType data);
    UInt8   getVexIndex(DVex* vex);
    DVex*   getIndexVex(UInt8 index);
    VexType* topoLogicalOrder(UInt32 *ve);
public:
    DGraph();
    ~DGraph();
    void    init();
    void    createGraph();
    bool    isEmpty()       { return !vex_nums; }
    GType   getType()       { return graph_type; }
    UInt32  getVexNums()    { return vex_nums; }
    UInt32  getArcNums()    { return arc_nums; }
    void    setType(GType graph_type)       { this->graph_type = graph_type; }
    void    setVexNums(UInt32 vex_nums)    { this->vex_nums = vex_nums; }
    void    setArcNums(UInt32 arc_nums)    { this->arc_nums = arc_nums; }
    DVex*   locateVex(VexType data);
    VexType getVexData(DVex* vex);
    void    setVexData(DVex* vex, VexType data);
    DArc*   locateArc(DVex* t_vex, DVex* h_vex);
    ArcType getArcValue(DArc* arc);
    void    setArcValue(DArc* vex, ArcType value);
    UInt8   getVexInDegree(DVex *vex);
    UInt8   getVexOutDegree(DVex *vex);
    DArc*   adjArc(DVex* vex, DArc* cur_arc);
    DVex*   adjVex(DVex* vex, DVex* cur_vex);
    DArc*   adjReverseArc(DVex* vex, DArc* cur_arc);
    DVex*   adjReverseVex(DVex* vex, DVex* cur_vex);
    DVex*   insertVex(VexType data);
    VexType deleteVex(DVex* vex);
    void    insertArc(DVex* t_vex, DVex* h_vex, ArcType arc);
    ArcType deleteArc(DVex* t_vex, DVex* h_vex);
    void    DFSTraverse(void(*visit)(VexType &data));
    void    BFSTraverse(void(*visit)(VexType &data));
    void    show();
    void static visit(VexType &data);
    DGraph* complementGraph();
    UInt32  weaklyConnectedCompnent();//弱连通分量
    UInt32  strongConnectedCompnent();//强连通分量
    UInt32  strongConnectedCompnentResult(UInt32 *finished, UInt32 vex_cnt, UInt32 strong_cnt);//强连通分量
    VexType* topoLogicalSort();
    DArc*   criticalPath();
    UInt32** dijkstraShortestPath(VexType vex_data);
    UInt32*** floydShortestPath();
};
#endif // !DGRAPH_H
