#ifndef TYPEDEF_H
#define TYPEDEF_H
#include <limits.h>

typedef     signed char         Int8;
typedef     unsigned char       UInt8;
typedef     signed  short       Int16;
typedef     unsigned short      UInt16;
typedef     signed  int         Int32;
typedef     unsigned int        UInt32;
typedef     signed long         Int64;
typedef     unsigned long       UInt64;
typedef     bool                Bool;

/*
	define the elemtype
*/
typedef		int		SqListElemType;
typedef		int		LinkListElemType;
typedef     int     StackElemType;
typedef     int     QueueElemType;
typedef     int     BiTreeElemType;
typedef     char    TreeElemType;
typedef     char    VexType;
typedef     int     ArcType;
typedef     int     SearchType;
typedef     int     BTreeType;
typedef     char    TrieType;
typedef     int     HashKeyType;
typedef     int     SortKeyType;
typedef     int     HeapKeyType;

enum LR {
    LEFT = 0,
    RIGHT = 1
};
//图
enum GType {
    DG  = 0,    //有向无权图
    DN  = 1,    //有向带权图(网)
    UDG = 2,    //无向无权图
    UDN = 3     //无向带权图
};
//静态查找
enum StaFindType {
    SEQ = 0,    //顺序查找
    BIN = 1,    //折半查找
    FIB = 2,    //斐波那契查找
    INT = 3,    //插值查找
    STR = 4,    //静态树查找
    IDX = 5    //索引查找
};
//动态查找
enum DynFindType {
    BST = 0,    //二叉排序树
    BBT = 1,    //平衡二叉树
};

//平衡树
enum Balance {
    LH = -1,         //左高
    EH = 0,         //等高
    RH = 1        //右高
};

//键树、Trie树、数字查找树
enum TrieNodeType {
    BRANCH  = 0,    //  分支结点
    LEAF    = 1     //  叶子结点
};

//哈希表
enum HashFun {
    LMOD = 0,     //线性取模
    SQRT = 1,    //平方取中
    FOLD = 2    //折叠法
};

enum CollFun {
    LINE = 0,   //线性再散列
    DOUB = 1,   //二次再散列
    LINK = 2    //链地址法
};

enum HashStatus {
    EMP = 0,    //为空，没有存储过数据
    USE = 1,    //当前存储着数据
    USD = 2,    //之前存储数据，后被删除
};


//附加信息可以用来扩展图的功能
typedef struct VexInfo {   //顶点的附加信息

} VexInfo;

typedef struct ArcInfo {    //弧的附加信息

} ArcInfo;

typedef struct Record{
    //附加信息
} Record;
/*
	define the MACRO
*/
#define		INIT_SIZE	    100
#define		INCREMENT	    10
#define     MAXELEMNUM      200

#define     NULL_ARC        INT_MAX
#define     MIN_ARC         INT_MIN
#define     NULL_DATA       INT_MIN

//宏状态
#define		OK				0
#define		OVER    		1
#define		ERROR			2


//宏操作
#define     MAX(a, b)       ((a) > (b) ? (a) : (b))
#define     MIN(a, b)       ((a) < (b) ? (a) : (b))
#define     ABS(a)          ((a) > 0 ? (a) : (0 - (a)))
#endif