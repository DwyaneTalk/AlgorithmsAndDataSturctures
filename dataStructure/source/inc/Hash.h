#ifndef HASH_H
#define HASH_H

/*
˵������ϣ���������4�����֣�
    1��һ��ؼ��ּ��ϣ�n��Ԫ�أ�
    2��һ������Ϊm�����ݱ�(һ�� m << n)
    3����ϣ����
    4����ͻ�������

��ϣ�����������ܽ�ÿ���ؼ������ɢ�е����ݱ�ĸ���λ�ã������ķ������£�
    1��ֱ�ӵ�ַ����
        H(key) = a * key + b  (a != 0)
        a��b��ѡ��Ӧ���ݱ����ؼ����ص�ȷ��
    2�����ַ�������
        ���ݹؼ���ÿ��λ�ϳ��ֵ����ֵķֲ���ѡ�������������λ��ɹ�ϣ����ֵ
    3��ƽ��ȡ�з���
        ���ؼ���ƽ����ȡ�м�ĳ��λ��Ҳ��������ķ�ʽ����������֤�ؼ�����ÿλ���������ϣ����ֵ����
    4���۵�����
        ���ؼ��ֳַ�λ����ͬ�ļ����֣����һ���ֿ��Զ�Щ����Ȼ���ü����ֵĵ��Ӻͣ���ȥ��λ����Ϊ��ϣ����ֵ
    5��������������
        H(key) = key MOD p   (p <= m)
        p��ѡȡ����Ҫ����p>m��������ݱ���˷ѡ����⣬p����ѡ����ʵ����������Խ��ͳ�ͻ

��ͻ�����
    1�����ŵ�ַ����
        Hi = (H(key) + di) MOD m    (i = 1, 2, 3����k)
        ����̽����ɢ�У�di = 1, 2, 3, 4,����
            ���Ա�֤���ݱ���ÿ��������ܹ�ʹ�ã����ǻ���ӷ�ͬ��ʵĳ�ͻ�����ξۼ���
        ����̽����ɢ�У�di = 1, -1, 4, -4, 9, -9,����
            ���Խ��Ͷ��ξۼ������Ǳ�������m = 4 * k + 3��kΪ����������mΪ����ʱ�����ܱ�֤���������ʹ��
        �漴̽����ɢ�У�di = rand()
    2���ٹ�ϣ��
        Hi = RHi(key) i = 1, 2, ����,���е�RHi����һ��
    3������ַ��
        ���ؼ���ɢ��ֵ��ͬ��������洢��һ��������
    4���������������
        Ϊ���дӳ�ͻ����������������洢��
*/
#include "Util.h"
#include "LinkList.h"

#define HASHSIZE    100
#define HASHA       7
#define HASHB       50

//˵����0 <= k < 10000
typedef struct HashElem{
    union {
        LinkList    *key_list;
        HashKeyType key;
    };
    HashStatus  status;
    Record      *info;
    HashElem() {
        key = 0;
        status = EMP;
        info = NULL;
    }
} HashElem;

class Hash {
private:
    HashFun hash_type;
    CollFun coll_type;
    HashElem *elem;
    UInt32  size;   //���洢�ռ�
    UInt32  count;  //��ǰ��¼��

    UInt32 (*hash_fun)(HashKeyType key);
    UInt32 (*coll_fun)(Int32 index, UInt32 count);
public:
    Hash(HashFun hash_type = LMOD, CollFun coll_type = LINE);
    ~Hash();
    Bool searchKey(HashKeyType key, Int32 &index, UInt32 &count);
    Bool insertKey(HashKeyType key, Record* info);
    Bool deleteKey(HashKeyType key);
};

UInt32 lmodHashFun(HashKeyType key);
UInt32 sqrtHashFun(HashKeyType key);
UInt32 foldHashFun(HashKeyType key);

UInt32 lineCollFun(Int32 index, UInt32 count);
UInt32 doubCollFun(Int32 index, UInt32 count);
#endif  //HASH_H
