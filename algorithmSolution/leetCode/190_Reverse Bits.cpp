/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Reverse Bits
 *             : https://leetcode.com/problems/reverse-bits/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef unsigned int uint32_t;

uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0, i = 0;
    while(i++ < 32) {
        ans = (ans << 1) + (n & 1);
        n = (n >> 1);
    }
    return ans;
}

int main() {
    uint32_t n = 43261596  ;
    uint32_t ans = reverseBits(n);
    printf("%u\n", ans);
    return 0;
}
















/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Substring with Concatenation of All Words
 *             : https://leetcode.com/problems/substring-with-concatenation-of-all-words/
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {

}

int main() {
    char *s = "123";
    char *words[] = {
        "abc",
        "def"
    };
    int wordsSize = 3;
    int returnSize = 0;
    int *ans= findSubstring(s, words, wordsSize, &returnSize);
    int i;
    for(i = 0; i < returnSize; ++i)
        printf("%d\t", ans[i]);
    return 0;
}*/
