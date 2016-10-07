/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Anagrams 
 *             : https://leetcode.com/problems/anagrams/
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    int size;
    int max_size;
    char** ans;
    int *used;
} Vector;

void initVector(Vector *vec, int max_size) {
    if (vec->ans = (char **)calloc(max_size, sizeof(char *))) {
        vec->used = (int *)calloc(max_size, sizeof(int));
        vec->max_size = max_size;
        vec->size = 0;
    }
}

void addOneToVector(Vector *vec, int index, char * str, int strLen) {
    if (index < vec->max_size && !vec->used[index]) {
        vec->ans[index] = (char *)malloc(sizeof(char)* (strLen + 1));
        strcpy(vec->ans[index], str);
        vec->used[index] = 1;
        ++vec->size;
    }
}

void arrangeVector(Vector *vec) {
    int i = 0, j = 0;
    while (j < vec->max_size) {
        if (vec->used[j]) {
            vec->ans[i] = vec->ans[j];
            ++i;
        }
        ++j;
    }
}

char** anagrams(char** strs, int strsSize, int* returnSize) {
    if (!strs || !strsSize) {
        *returnSize = 0;
        return NULL;
    }
    int *count = (int *)calloc(strsSize * (27), sizeof(int));
    int i, j, strLen, cnt_i = 0, cnt_j = 0;
    char *p;
    Vector vec;
    initVector(&vec, strsSize);
    for (i = 0; i < strsSize; ++i, cnt_i += 27) {
        strLen = strlen(strs[i]);
        count[cnt_i] = strLen;
        p = strs[i];
        while (*p) {
            ++count[cnt_i + *(p++) - 96];
        }
    }
    for (i = 0, cnt_i = 0; i < strsSize; ++i, cnt_i += 27) {
        for (j = 0, cnt_j = 0; j < i; ++j, cnt_j += 27) {
            if (count[cnt_i] == count[cnt_j]) {
                if (!memcmp(count + cnt_i + 1, count + cnt_j + 1, sizeof(int)* 26)) {
                    addOneToVector(&vec, i, strs[i], count[cnt_i]);
                    addOneToVector(&vec, j, strs[j], count[cnt_j]);
                    break;
                }
            }
        }
    }
    arrangeVector(&vec);
    *returnSize = vec.size;
    return vec.ans;
}

int main() {
    char *strs[] = {
        "abcde",
        "edcba",
        "",
        "ab",
        "",
        "ba"
    };
    int returnSize;
    char **ans = anagrams(strs, 6, &returnSize);
    int i;
    for (i = 0; i < returnSize; ++i) {
        printf("%s\n", ans[i]);
    }
    system("pause");
    return 0;
}
//  use uthash to get the hash(much better)
//struct countEntry {
//    char* sortedString;
//    int indices[20];
//    UT_hash_handle hh;
//};
//
//void sortHelper(char* in, int s, int e){
//    if (s >= e) return;
//    int m = (s + e) / 2;
//    char mc = in[m];
//    int f = s, b = e;
//    while (f <= b) { // f and b stop at the same position which value equals mc, need to use = here
//        while (in[f]<mc) f++;
//        while (in[b]>mc) b--; // can't use = in quick sort, it might cause ifinite loops
//        if (f>b) break;
//        char te = in[f];
//        in[f++] = in[b];
//        in[b--] = te;
//    }
//    sortHelper(in, s, f - 1);
//    sortHelper(in, f, e);
//}
//
//char* sort(char* f, bool s) { // if s is false, just copy the string
//    char* it = f;
//    int len = strlen(f);
//    char* re = calloc((len + 1), sizeof(char)); // calloc has two arguments
//    strcpy(re, f);
//    if (s == true) sortHelper(re, 0, len - 1); // should not sort the \0 character, sort the string when if the switch is true
//    return re;
//}
//
//char **anagrams(char *strs[], int n, int *outputSize) {
//    char** result = malloc(n*sizeof(char*));
//    struct countEntry *s, *countTable = NULL; // * should go with the variable name
//    int p = 0;
//    for (int i = 0; i<n; i++) {
//        char* tm = sort(strs[i], true);
//        HASH_FIND_STR(countTable, tm, s);
//        if (s == NULL) {
//            s = (struct countEntry*)malloc(sizeof(struct countEntry));
//            s->sortedString = tm;
//            s->indices[0] = i;
//            s->indices[1] = -1; // use -1 to indicate the end of the list
//            HASH_ADD_KEYPTR(hh, countTable, s->sortedString, strlen(s->sortedString), s);
//        } else {
//            int j = 0;
//            while (s->indices[j] != -1) j++;
//            s->indices[j] = i;
//            s->indices[j + 1] = -1;
//        }
//    }
//    for (s = countTable; s != NULL; s = s->hh.next) {
//        if (s->indices[1] != -1) {
//            for (int k = 0; s->indices[k] != -1; k++) {
//                result[p++] = sort(strs[s->indices[k]], false);
//            }
//        }
//    }
//    *outputSize = p;
//    return result;
//}
