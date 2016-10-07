/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Longest Valid Parentheses
*             : https://leetcode.com/problems/longest-valid-parentheses/
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    int *elem;
    int max_size;
    int top;
} Stack;

void initStack(Stack *pStack, int max_size) {
    if (!(pStack->elem = (int *)malloc(sizeof(int)* max_size))) {
        printf("fail to allocate memory for stack!");
        exit(-1);
    }
    pStack->top = 0;
    pStack->max_size = max_size;
}

void pushStack(Stack *pStack, int elem) {
    if (pStack->top == pStack->max_size) {
        printf("no space for new elem!");
        exit(-1);
    }
    pStack->elem[(pStack->top)++] = elem;
}

int popStack(Stack *pStack) {
    if (!pStack->top) {
        printf("stack is empty, can not pop!");
        exit(-1);
    }
    return pStack->elem[--(pStack->top)];
}

int getStackTop(Stack *pstack) {
    return pstack->elem[pstack->top - 1];
}

int isEmptyStack(Stack *pstack) {
    return !pstack->top;
}
// 通过维护stack记录距离当前i位置向左不匹配的位置（记录位置，不记录括号）
int solution1(char* s) {
    int len = strlen(s), ans = 0, i, val;
    Stack stack, *pstack = &stack;
    initStack(pstack, len);
    for (i = 0; i < len; ++i) {
        if (s[i] == '(')    pushStack(pstack ,i);
        else {
            if (!isEmptyStack(pstack) && s[getStackTop(pstack)] == '(') {
                popStack(pstack);
                if (!isEmptyStack(pstack))
                    val = getStackTop(pstack);
                else
                    val = -1;
                if (i - val > ans) {
                    ans = i - val;
                }
            } else {
                pushStack(pstack, i);
            }
        }
    }
    return ans;
}

// 构造数组suffix，记录各个位置左边最长可能的匹配长度
int solution2(char *s) {
    int len = strlen(s);
    int *suffix = (int *)malloc(sizeof(int)* len);
    int i, ans = 0;
    memset(suffix, 0, sizeof(int)* len);
    for (i = 0; i < len; i++) {
        if (s[i] == ')') {
            if (i >= 1 && i - suffix[i - 1] - 1 >= 0 && s[i - suffix[i - 1] - 1] == '(') {
                suffix[i] = suffix[i - 1] + 2 + ((i - suffix[i - 1] - 2) >= 0 ? suffix[i - suffix[i - 1] - 2] : 0);
                if (suffix[i] > ans)
                    ans = suffix[i];
            }
        }
    }
    return ans;
}

int longestValidParentheses(char* s) {
    if (false)
        return solution1(s);
    else
        return solution2(s);
}
int main() {
    char str[] = "()()())";
    int ans = longestValidParentheses(str);
    printf("%d\n", ans);
    system("pause");
    return 0;
}
