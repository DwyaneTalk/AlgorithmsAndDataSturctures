/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Sqrt(x)
*             : https://leetcode.com/problems/sqrtx/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    int size;   // number of string lines
    int width;  // valid width for a string line
    char **strLine;
} StrLines;

void initStrLines(StrLines *strLines, int nums, int width) {
    if (strLines->strLine = (char **)malloc(sizeof(char *) * nums)) {
        strLines->size = 0;
        strLines->width = width;
    }
}

int getOneLines(char **words, int wordsSize, int width, int *len, int lo, int *hi, int *sumLens) {
    if (lo >= wordsSize)    return 0;
    int count = 0;
    while (*hi + 1 < wordsSize && count + len[*hi + 1] <= width) {
        *hi = *hi + 1;
        count = count + len[*hi] + 1;
        *sumLens = *sumLens + len[*hi];
    }
    return *hi + 1 == wordsSize ? 2 : 1;    //2表示最后一行
}

void setOneLines(char **words, int *len, int lo, int hi, int sumLens, StrLines *strLines, int status) {
    int slotSum = strLines->width - sumLens;
    int slotCount = hi - lo;
    int i = 0, j, a, b;
    char *ptr;
    if (status == 2) {  //最后一行
        a = slotSum - slotCount;
    } else {
        if (slotCount) {    //多个words
            a = slotSum / slotCount;
            b = slotSum % slotCount;
        } else {    //只有一个word
            a = slotSum;
        }
    }
    strLines->strLine[strLines->size] = ptr = (char *)malloc(sizeof(char) * (strLines->width + 1));
    ptr[strLines->width] = '\0';
    while (lo < hi) {
        memcpy(ptr, words[lo], len[lo] * sizeof(char));
        ptr += len[lo];
        if (status == 2) {
            *ptr++ = ' ';
        } else {
            if (i++ < b) {
                memset(ptr, ' ', sizeof(char)* (a + 1));
                ptr += a + 1;
            } else {
                memset(ptr, ' ', sizeof(char)* a);
                ptr += a;
            }
        }
        ++lo;
    }
    memcpy(ptr, words[lo], len[lo] * sizeof(char));
    if (status == 2 || !slotCount) {
        ptr += len[lo];
        memset(ptr, ' ', sizeof(char)* a);
    }
    strLines->size = strLines->size + 1;
}

char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    if (!words || !wordsSize)   return NULL;
    StrLines strLines;
    initStrLines(&strLines, wordsSize, maxWidth);
    int i, *lens = (int *)malloc(sizeof(int)* wordsSize);
    for (i = 0; i < wordsSize; ++i) {
        if (!words[i])  return NULL;
        lens[i] = strlen(words[i]);
        if (lens[i] > maxWidth) return NULL;
    }
    int lo = 0, hi = -1, sumLens = 0, status;
    while (status = getOneLines(words, wordsSize, maxWidth, lens, lo, &hi, &sumLens)) {
        setOneLines(words, lens, lo, hi, sumLens, &strLines, status);
        lo = hi + 1;
        sumLens = 0;
    }
    *returnSize = strLines.size;
    return strLines.strLine;
}

int main() {
    char *words[] = {
        "This",
        "is",
        "an",
        "example",
        "of",
        "text",
        "justion.",
    };
    int wordsSize = 5;
    int maxWidth = 10;
    int returnSize;
    char **ans = fullJustify(words, wordsSize, maxWidth, &returnSize);
    for (int i = 0; i < returnSize; ++i)
        printf("%s\n", ans[i]);
    system("pause");
    return 0;
}
