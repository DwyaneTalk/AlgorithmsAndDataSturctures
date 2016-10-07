/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Generate Parentheses
 *             : https://leetcode.com/problems/generate-parentheses/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct StringArray {
    char** elements;
    int size;
};
typedef struct StringArray StringArray;

void addOneToAns(long long track, int len, StringArray *ans) {
    char *ptr = ans->elements[(ans->size)++] = (char *)malloc(sizeof(char) * (len + 1));
    while(len--) {
        if(track & 1)
            *ptr++ = '(';
        else
            *ptr++ = ')';
        track >>= 1;
    }
    *ptr = '\0';
}

int getBits(long long track, int len) {
    int ans = 0;
    while(track && len--){
        if(track & 1)
            ans++;
        track >>= 1;
    }
    return ans;
}

void DFS(long long track, int curr, int len, StringArray *ans) {
    if(curr == len) {
        addOneToAns(track, len, ans);
        return;
    }
    int bits = getBits(track, curr);//get current number of '(';
    if(bits + 1 <= len / 2){
        track |=  (1 << curr);  // set '(' at the curr-th place
        DFS(track, curr + 1, len, ans);
    }
    if(2 * bits >= curr + 1 && curr + 1 - bits <= len / 2){
        track &= ~(1 << curr);
        DFS(track, curr + 1, len, ans);
    }
}

StringArray* generateParenthesis(int n) {
    StringArray *ans = (StringArray *)malloc(sizeof(StringArray));
    ans->size = 0;
    ans->elements = (char **) malloc(sizeof(char *) * 10000);
    if(n)
        DFS(0, 0, n * 2, ans);
    return ans;
}
int main() {
    int n = 0, i;
    StringArray * ans = generateParenthesis(n);
    for( i = 0; i < ans->size; ++i) {
        printf("%s\n", ans->elements[i]);
    }
    return 0;
}
