/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Valid Parentheses
 *             : https://leetcode.com/problems/valid-parentheses/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

bool isMatch(char a, char b){
    if(a == ')')        return b == '(';
    else if(a == ']')   return b == '[';
    else                return b == '{';
}

bool isValid(char* s) {
    int len = strlen(s);
    char *stack = (char *) malloc(sizeof(char) * len);
    char *ptr = s;
    int top = 0;
    bool ans = true;
    while(*ptr) {
        if(*ptr == '(' || *ptr == '{' || *ptr == '[') {
            stack[top++] = *ptr;
        } else {
            if(top > 0 && isMatch(*ptr, stack[top - 1])) {
                top--;
            } else {
                ans = false;
                break;
            }
        }
        ptr++;
    }
    if(top != 0)    ans = false;
    free(stack);
    return ans;
}

int main() {
    char in[] = "()";
    int ans = isValid(in);
    printf("%d\n", ans);
    return 0;
}
