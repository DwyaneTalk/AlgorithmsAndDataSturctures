#ifndef HASH_H
#define HASH_H

/*
说明：哈希表包含下面4个部分：
    1、一组关键字集合（n个元素）
    2、一个长度为m的数据表(一般 m << n)
    3、哈希函数
    4、冲突解决方法

哈希函数：尽可能将每个关键字随机散列到数据表的各个位置，常见的方法如下：
    1、直接地址法：
        H(key) = a * key + b  (a != 0)
        a与b的选择，应根据表厂、关键字特点确定
    2、数字分析法：
        根据关键字每个位上出现的数字的分布，选择出现相对随机的位组成哈希函数值
    3、平方取中法：
        将关键字平方后，取中间某几位（也可以求余的方式），这样保证关键字中每位数都参与哈希函数值生成
    4、折叠法：
        将关键字分成位数相同的几部分（最后一部分可以短些），然后用几部分的叠加和（舍去进位）作为哈希函数值
    5、除留余数法：
        H(key) = key MOD p   (p <= m)
        p的选取很重要。若p>m，造成数据表的浪费。另外，p尽量选择合适的质数，可以降低冲突

冲突解决：
    1、开放地址法：
        Hi = (H(key) + di) MOD m    (i = 1, 2, 3……k)
        线性探测再散列：di = 1, 2, 3, 4,……
            可以保证数据表中每个数据项都能够使用，但是会添加非同义词的冲突（二次聚集）
        二次探测再散列：di = 1, -1, 4, -4, 9, -9,……
            可以降低二次聚集，但是必须满足m = 4 * k + 3（k为整数），且m为质数时，才能保证所有数据项被使用
        随即探测再散列：di = rand()
    2、再哈希法
        Hi = RHi(key) i = 1, 2, ……,所有的RHi都不一样
    3、链地址法
        将关键字散列值相同的数据项，存储在一个链表中
    4、建立公共溢出区
        为所有从冲突的数据项，建立公共存储区
*/
#include "Util.h"
#include "LinkList.h"

#define HASHSIZE    100
#define HASHA       7
#define HASHB       50

//说明：0 <= k < 10000
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
    UInt32  size;   //最大存储空间
    UInt32  count;  //当前记录数

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
