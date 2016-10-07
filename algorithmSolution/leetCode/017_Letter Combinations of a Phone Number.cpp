/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Letter Combinations of a Phone Number
 *             : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char *map[10] = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

struct StringArray {
    char** elements;
    int size;
};
typedef struct StringArray  StringArray;

void BFS(int offset, char *digits, StringArray *ans){
    int val, num, i, j, size;
    val = digits[offset] - '0';
    num = strlen(map[val]);
    for(i = 0; i < num; i++) {
        ans->elements[ans->size++][offset] = map[val][i];
    }
    offset++;
    while(digits[offset] != '\0') {
        size = ans->size;
        val = digits[offset] - '0';
        num = strlen(map[val]);
        for(i = 1; i < num; i++) {
            for(j = 0; j < size; j++) {
                strcpy(ans->elements[ans->size], ans->elements[j]);
                ans->elements[ans->size++][offset] = map[val][i];
            }
        }
        for(j = 0; j < size; j++) {
            ans->elements[j][offset] = map[val][0];
        }
        offset++;
    }
}

void DFS(char *prefix, char *digits, StringArray *ans) {
    int len = strlen(prefix);
    int i, num, val;
    if(len == strlen(digits)) {
        strcpy(ans->elements[ans->size++], prefix);
    } else {
        val = digits[len] - '0';
        num = strlen(map[val]);
        for(i = 0; i < num; i++) {
            prefix[len] = map[val][i];
            prefix[len + 1] = '\0';
            DFS(prefix, digits, ans);
        }
    }
}

struct StringArray* letterCombinations(char* digits) {
    StringArray* ansStrArr = (StringArray *)malloc(sizeof(StringArray));
    int i = 0, size = 1, val, len = strlen(digits);
    char *prefix = (char *)malloc(sizeof(char) * (len + 1));
    memset(prefix, 0, sizeof(char) * (len + 1));
    while(digits[i]) {
        val = digits[i++] - '0';
        size *= strlen(map[val]);
    }
    ansStrArr->elements = (char **)malloc(sizeof(char *) * size);
    for(i = 0; i < size; i++){
        ansStrArr->elements[i] = (char *)malloc(sizeof(char) * (len + 1));
        memset(ansStrArr->elements[i], 0, sizeof(char) * (len + 1));
    }
    ansStrArr->size = 0;
    if(strlen(digits)){
        //DFS(prefix, digits, ansStrArr);
        BFS(0, digits, ansStrArr);
    }
    return ansStrArr;
}
int main() {
    char str[] = "29";
    StringArray* ans = letterCombinations(str);
    int i = 0;
    for(; i< ans->size; i++) {
        printf("%s\n", ans->elements[i]);
    }
    return 0;
}
