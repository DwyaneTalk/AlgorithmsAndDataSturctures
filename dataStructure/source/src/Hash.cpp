#include "../inc/Hash.h"


Hash::Hash(HashFun hash_type, CollFun coll_type) {
    if (elem = new HashElem[HASHSIZE]) {
        size = HASHSIZE;
        count = 0;
        this->hash_type = hash_type;
        this->coll_type = coll_type;

        switch (hash_type) {
        case LMOD:  hash_fun = lmodHashFun;
            break;
        case SQRT:  hash_fun = sqrtHashFun;
            break;
        case FOLD:  hash_fun = foldHashFun;
            break;
        }

        switch (coll_type) {
        case LINE:  coll_fun = lineCollFun; 
            break;
        case DOUB:  coll_fun = doubCollFun;
            break;
        case LINK:  coll_fun = NULL;
            break;
        }
    } else {
        ferr << "哈希数据表申请空间失败" << endl;
        exit(OVER);
    }
}

Hash::~Hash() {
    for (UInt32 i = 0; i < size; ++i) {
        if (elem[i].info) {
            delete elem[i].info;
        }
        if (coll_type == LINK && elem[i].key_list) {
            delete elem[i].key_list;
        }
    }
    delete elem;
}

Bool Hash::searchKey(HashKeyType key, Int32 &index, UInt32 &count) {
    Int32 value = index = hash_fun(key);
    count = 0;
    if (coll_type == LINK) {
        if (elem[index].key_list && elem[index].key_list->getIndex(key) >= 0)    return true;
        else    return false;
    } else {
        while (elem[index].status == USE && elem[index].key != key) {
            if (count >= size) {
                index = -1;
                return false;
            } else {
                index = coll_fun(value, ++count);
            }
        }
        if (elem[index].status == USE)  return true;
        else    return false;
    }
}

Bool Hash::insertKey(HashKeyType key, Record* info) {
    UInt32 count;
    Int32  index;
    if (searchKey(key, index, count)) {
        //cout << "该关键字已存在哈希表中" << endl;
        return true;
    } else {
        if (index < 0) {
            //cout << "哈希表空间已无法插入该关键字" << endl;
            return false;
        } else {
            if (coll_type == LINK) {
                if (!elem[index].key_list)
                    elem[index].key_list = new LinkList;
                elem[index].key_list->insertHeadElem(key);
            } else {
                UInt32 new_idx = index, new_cnt = 0;
                while (elem[index].status == USE) {
                    index = coll_fun(new_idx, ++new_cnt);
                }
                elem[index].status = USE;
                elem[index].key = key;
                elem[index].info = info;
            }
            ++(this->count);
            return true;
        }
    }
}

Bool Hash::deleteKey(HashKeyType key) {
    UInt32 count;
    Int32  index;
    if (searchKey(key, index, count)) {
        if (coll_type == LINK) {
            UInt32 loc;
            if (!elem[index].key_list || (loc = elem[index].key_list->getIndex(key) < 0)) {
                ferr << "哈希表内部结构出错" << endl;
                exit(ERROR);
            }
            elem[index].key_list->deleteElem(loc);
        } else {
            elem[index].status = USD;
            if (elem[index].info)   
                delete elem[index].info;
        }
        --(this->count);
        return true;
    } else {
        //cout << "该关键字不在哈希表中" << endl;
        return false;
    }
}

UInt32 lmodHashFun(HashKeyType key) {
    return (key * HASHA + HASHB) % HASHSIZE;
}

UInt32 sqrtHashFun(HashKeyType key) {
    UInt32 sqrt = key * key;
    return ((sqrt / 10) % HASHSIZE + (sqrt / 100000) % HASHSIZE) % HASHSIZE;
}

UInt32 foldHashFun(HashKeyType key) {
    return ((key / 100) + 10 * (key % 10) + (key / 10) % 10) % HASHSIZE;
}

UInt32 lineCollFun(Int32 index, UInt32 count) {
    return (index + count) % HASHSIZE;
}

UInt32 doubCollFun(Int32 index, UInt32 count) {
    Int8 sign = (count % 2) ? 1 : (-1);
    return (index + ((count + 1) / 2 * (count + 1) / 2) * sign) % HASHSIZE;
}

