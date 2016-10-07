#include "../inc/StaticSrhTable.h"

StaticSrhTable::StaticSrhTable() {
    fin >> size;
    if (data = new SearchType[size]) {
        for (UInt32 i = 0; i < size; ++i) {
            fin >> data[i];
        }
        seq_data = NULL;
        sta_srh_tree = NULL;
        idx_table.items = NULL;
        weight = NULL;
    } else {
        ferr << "æ≤Ã¨≤È’“±Ìƒ⁄¥Ê…Í«Î ß∞‹" << endl;
        exit(OVER);
    }
}

StaticSrhTable::~StaticSrhTable() {
    delete data;
    if (seq_data) delete seq_data;
    if (sta_srh_tree) delete sta_srh_tree;
    if(idx_table.items) delete idx_table.items;
    if(weight) delete weight;
    size = 0;
}

Int32 StaticSrhTable::search(StaFindType f_type, SearchType key) {
    switch (f_type) {
    case SEQ:   
        return seqSearch(key);
    case BIN:   
        sortData();
        return binSearch(key);
    case FIB:   
        sortData();
        return fibSearch(key);
    case INT:   
        sortData();
        return intSearch(key);
    case STR:   
        initTree();
        return strSearch(key);
    case IDX:   
        initIdx();
        return idxSearch(key);
    }
    return -1;
}

Int32 StaticSrhTable::seqSearch(SearchType key) {
    UInt32 i = 0;
    for (; i < size; ++i) {
        if (data[i] == key) {
            return i;
        }
    }
    return -1;
}

Int32 StaticSrhTable::binSearch(SearchType key) {
    UInt32 low = 0, high = size - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (seq_data[mid] == key)   return mid;
        else if (seq_data[mid] < key)   low = mid + 1;
        else    high = mid - 1;
    }
    return -1;
}

Int32 StaticSrhTable::fibSearch(SearchType key) {
    UInt32 low = 0, high = size - 1, mid, fib_num = MAX(5, size);
    UInt32 *fib = new UInt32[fib_num];
    fib[0] = 0;
    fib[1] = 1;
    UInt32 i = 2, u = 0;
    while (i < fib_num) {
        fib[i] = fib[i - 1] + fib[i - 2];
        ++i;
    }
    while (size >= fib[u]) {
        ++u;
    }
    SearchType *data_ext = new SearchType[fib[u] - 1];
    memcpy(data_ext, seq_data, sizeof(SearchType)* size);
    for (i = size; i < fib[u] - 2; ++i)
        data_ext[i] = seq_data[size - 1];
    while (low <= high) {
        mid =low + fib[u - 1] - 1;
        if (data_ext[mid] == key) {
            delete fib;
            delete data_ext;
            return MIN(mid, size);
        } else if (data_ext[mid] < key) {
            low = mid + 1;
            u = u - 2;
        } else {
            high = mid - 1;
            u = u - 1;
        }
    }
    delete fib;
    delete data_ext;
    return -1;
}

Int32 StaticSrhTable::intSearch(SearchType key) {
    SearchType min, max;
    UInt32 low = 0, high = size - 1, mid;
    while (low <= high) {
        max = seq_data[high];
        min = seq_data[low];
        if (min > key || max < key) return -1;
        mid = low + (key - min) * (high - low) / (max - min);
        if (seq_data[mid] == key) {
            return mid;
        } else if (seq_data[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

Int32 StaticSrhTable::strSearch(SearchType key) {
    BiNode *node = sta_srh_tree->getRoot();
    while (node) {
        if (seq_data[node->data] == key) {
            return node->data;
        } else if(seq_data[node->data] < key) {
            node = node->rchild;
        } else {
            node = node->lchild;
        }
    }
    return -1;
}

Int32 StaticSrhTable::idxSearch(SearchType key) {
    UInt32 low = 0, high = idx_table.nums - 1, mid;
    UInt32 block_idx;
    if (key > idx_table.items[idx_table.nums - 1].key)  return -1;
    while (low < high) {
        mid = (low + high) / 2;
        if (key > idx_table.items[mid].key) {
            low = mid + 1;
        } else if (key < idx_table.items[mid].key) {
            high = mid;
        } else {
            break;
        }
    }
    if (low < high) block_idx = mid;
    else            block_idx = low;
    for (UInt32 i = idx_table.items[block_idx].start; i <= idx_table.items[block_idx].end; ++i) {
        if (key == data[i]) return i;
    }
    return -1;
}

void  StaticSrhTable::sortData() {
    if (!seq_data) {
        seq_data = new SearchType[size];
        if (!seq_data) {
            ferr << "…Í«Îƒ⁄¥Ê ß∞‹£°" << endl;
            exit(OVER);
        }
        memcpy(seq_data, data, sizeof(SearchType)* size);
        sort(seq_data, seq_data + size);
        cout << "≈≈–Ú∫Û£∫";
        for (UInt32 i = 0; i < size; ++i)
            cout << seq_data[i] << " ";
        cout << endl;
    }
}

void  StaticSrhTable::initIdx() {
    if (!idx_table.nums) {
        idx_table.items = new IdxItem[size];
        SearchType *min_data = new SearchType[size];
        SearchType *max_data = new SearchType[size];
        SearchType cur_min = INT_MAX, cur_max = INT_MIN;
        if (!idx_table.items || !min_data || !max_data) {
            ferr << "Œ™À˜“˝±Ì…Í«Îƒ⁄¥Ê ß∞‹£°" << endl;
            exit(OVER);
        }
        for (Int32 i = size - 1; i >= 0; i--) {
            min_data[i] = cur_min;
            cur_min = MIN(cur_min, data[i]);
        }
        for (UInt32 i = 0; i < size; ++i) {
            cur_max = MAX(cur_max, data[i]);
            max_data[i] = cur_max;
        }
        idx_table.nums = 0;
        UInt32 start = 0;
        for (UInt32 i = 0; i < size; ++i) {
            if (min_data[i] >= max_data[i]) {
                idx_table.items[idx_table.nums].start = start;
                idx_table.items[idx_table.nums].end = i;
                idx_table.items[idx_table.nums].key = max_data[i];
                ++idx_table.nums;
                start = i + 1;
            }
        }
        delete min_data;
        delete max_data;
    }
}

void  StaticSrhTable::initTree() {
    sortData();
    if (!sta_srh_tree) {
        UInt32 *weight = new UInt32[size];
        UInt32 *sw = new UInt32[size];
        sta_srh_tree = new BinaryTree;
        //  ‰»Î»®÷µ
        for (UInt32 i = 0; i < size; ++i) {
            fin >> weight[i];
        }
        if (!sw || !sta_srh_tree) {
            ferr << "¥Œ”≈≤È’“ ˜ƒ⁄¥Ê…Í«Î ß∞‹£°" << endl;
            exit(OVER);
        }
        sw[0] = weight[0];
        for (UInt32 i = 1; i < size; ++i) {
            sw[i] = sw[i - 1] + weight[i];
        }
        (*sta_srh_tree->getRootPoint()) = createTree(sw, seq_data, 0, size - 1);
        delete sw;
    }
}

BiNode* StaticSrhTable::createTree(UInt32 *sw, SearchType *seq_data, UInt32 low, UInt32 high) {
    UInt32 min = ABS(sw[high] - sw[low]);
    Int32 dw;
    UInt32 idx = low;
    UInt32 tmp_value;
    if (low) dw = sw[high] + sw[low - 1];
    else dw = sw[high];
    for (UInt32 i = low + 1; i <= high; ++i) {
        if ((tmp_value = ABS(Int32(dw - sw[i] - sw[i - 1]))) < min) {
            min = tmp_value;
            idx = i;
        }
    }
    BiNode *node = new BiNode(idx);
    if (idx == low) node->lchild = NULL;
    else {
        node->lchild = createTree(sw, seq_data, low, idx - 1);
    }
    if (idx == high) node->rchild = NULL;
    else {
        node->rchild = createTree(sw, seq_data, idx + 1, high);
    }
    return node;
}

void StaticSrhTable::traverse(void(*visit)(SearchType &e)) {
    for (UInt32 i = 0; i < size; ++i) {
        visit(data[i]);
    }
    cout << endl;
}

void StaticSrhTable::visit(SearchType &e) {
    cout << e << "  ";
}
