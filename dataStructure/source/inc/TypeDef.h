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
//ͼ
enum GType {
    DG  = 0,    //������Ȩͼ
    DN  = 1,    //�����Ȩͼ(��)
    UDG = 2,    //������Ȩͼ
    UDN = 3     //�����Ȩͼ
};
//��̬����
enum StaFindType {
    SEQ = 0,    //˳�����
    BIN = 1,    //�۰����
    FIB = 2,    //쳲���������
    INT = 3,    //��ֵ����
    STR = 4,    //��̬������
    IDX = 5    //��������
};
//��̬����
enum DynFindType {
    BST = 0,    //����������
    BBT = 1,    //ƽ�������
};

//ƽ����
enum Balance {
    LH = -1,         //���
    EH = 0,         //�ȸ�
    RH = 1        //�Ҹ�
};

//������Trie�������ֲ�����
enum TrieNodeType {
    BRANCH  = 0,    //  ��֧���
    LEAF    = 1     //  Ҷ�ӽ��
};

//��ϣ��
enum HashFun {
    LMOD = 0,     //����ȡģ
    SQRT = 1,    //ƽ��ȡ��
    FOLD = 2    //�۵���
};

enum CollFun {
    LINE = 0,   //������ɢ��
    DOUB = 1,   //������ɢ��
    LINK = 2    //����ַ��
};

enum HashStatus {
    EMP = 0,    //Ϊ�գ�û�д洢������
    USE = 1,    //��ǰ�洢������
    USD = 2,    //֮ǰ�洢���ݣ���ɾ��
};


//������Ϣ����������չͼ�Ĺ���
typedef struct VexInfo {   //����ĸ�����Ϣ

} VexInfo;

typedef struct ArcInfo {    //���ĸ�����Ϣ

} ArcInfo;

typedef struct Record{
    //������Ϣ
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

//��״̬
#define		OK				0
#define		OVER    		1
#define		ERROR			2


//�����
#define     MAX(a, b)       ((a) > (b) ? (a) : (b))
#define     MIN(a, b)       ((a) < (b) ? (a) : (b))
#define     ABS(a)          ((a) > 0 ? (a) : (0 - (a)))
#endif