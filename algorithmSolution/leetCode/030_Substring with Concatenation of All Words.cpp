/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Substring with Concatenation of All Words
 *             : https://leetcode.com/problems/substring-with-concatenation-of-all-words/
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    int size;
    int max_size;
    int *elem;
} List;

typedef struct {
    int size;
    int max_size;
    int word_size;
    char** words;
    int* sum_num;
    int* cur_num;
} Map;

void initList(List* list, int max_size) {
    if(list->elem = (int *)malloc(sizeof(int) * max_size)){
        list->size = 0;
        list->max_size = max_size;
    }
}

void addOneToList(List* list, int elem) {
    if(list->size < list->max_size) {
        list->elem[(list->size)++] = elem;
    } else {
        printf("error!");
        exit(-1);
    }
}

void initMap(Map* map, int max_size, int word_size) {
    if(map->words = (char**)malloc(sizeof(char*) * max_size)) {
        if(map->sum_num = (int*)calloc(sizeof(int), max_size)) {
            if(map->cur_num = (int *)calloc(sizeof(int), max_size)) {
                map->size = 0;
                map->max_size = max_size;
                map->word_size = word_size;
            }
        }
    }
}

void resetMap(Map* map) {
    memset(map->cur_num, 0, sizeof(int) * map->size);
}

void addOneToMap(Map* map, char* s) {
    int i;
    for(i = 0; i < map->size; ++i) {
        if(!memcmp(map->words[i], s, map->word_size)) {
            map->sum_num[i]++;
            return;
        }
    }
    map->words[map->size] = s;
    map->sum_num[(map->size)++] = 1;
}

void destroyMap(Map* map) {
    free(map->sum_num);
    free(map->cur_num);
    free(map->words);
}

int existInMap(Map* map, char* s) {
    int i;
    for(i = 0; i < map->size; ++i) {
        if(!memcmp(map->words[i], s, map->word_size))
            return i;
    }
    return -1;
}

// wordsSize means the word number
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    if (!s || !words || !wordsSize || !words[0] || !strlen(words[0])) {
        *returnSize = 0;
        return NULL;
    }
    int i, j, s_len = strlen(s), w_len = strlen(words[0]);
    List list;
    initList(&list, s_len);
    Map map;
    initMap(&map, wordsSize, w_len);
    for(i = 0; i < wordsSize; ++i) {
        addOneToMap(&map, words[i]);
    }
    int pos, pos2, count = 0, left = 0;
    for(i = 0; i < w_len; ++i) {
        left = i;
        resetMap(&map);
        count = 0;
        for(j = i; j <= s_len - w_len; j += w_len) {
            if((pos = existInMap(&map, s + j)) >= 0) {
                map.cur_num[pos]++;
                if(map.cur_num[pos] <= map.sum_num[pos])
                    ++count;
                else {
                    while(map.cur_num[pos] > map.sum_num[pos]) {
                        pos2 = existInMap(&map, s + left);
                        map.cur_num[pos2]--;
                        left += w_len;
                        if(map.cur_num[pos2] < map.sum_num[pos2])
                            count--;
                    }
                }
                if(count == wordsSize) {
                    addOneToList(&list, left);
                    pos = existInMap(&map, s + left);
                    map.cur_num[pos]--;
                    count--;
                    left += w_len;
                }
            } else {
                left = j + w_len;
                resetMap(&map);
                count = 0;
            }
        }
    }
    destroyMap(&map);
    *returnSize = list.size;
    return list.elem;
}

int main() {
    char *s = "aaa";
    char *words[] = {
        "aa",
        "aa"
    };
    int wordsSize = 2;
    int returnSize = 0;
    int *ans = findSubstring(s, words, wordsSize, &returnSize);
    int i;
    for(i = 0; i < returnSize; ++i)
        printf("%d\t", ans[i]);
    system("pause");
    return 0;
}
