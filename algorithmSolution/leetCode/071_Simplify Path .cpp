/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Simplify Path 
*             : https://leetcode.com/problems/simplify-path/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct Stack{
    char *elem;
    int *pos;
    int top;
} Stack;

void initStack(Stack *stack, int size) {
    if (stack->elem = (char *)malloc(sizeof(char)* size)) {
        if (stack->pos = (int *)malloc(sizeof(int)* size)) {
            stack->top = 0;
            stack->pos[stack->top] = 0;
        }
    }
}

void pushStack(Stack *stack, char *str) {
    int pos = stack->pos[stack->top];
    while (*str) {
        stack->elem[pos++] = *str++;
    }
    stack->top += 1;
    stack->pos[stack->top] = pos;
}

void popStack(Stack *stack) {
    if (!stack->top)    return;
    stack->top--;
    stack->elem[stack->pos[stack->top]] = '\0';
}

int judgeStatus(char *str) {
    if (!strcmp(str, "/") || !strcmp(str, "/."))     return 3;
    if (!strcmp(str, "/.."))        return 2;
    return 1;
}

int getElem(char **path, char *str) {
    if (!(**path))  return 0;   //ÅÐ¶Ï½áÊø
    char *ptr = str;
    *ptr++ = *(*path)++;
    while (**path && **path != '/') {
        *ptr++ = *(*path)++;
    }
    *ptr = '\0';
    return judgeStatus(str);
}

char* simplifyPath(char* path) {
    int len = strlen(path);
    if (!path || len < 2)   return path;
    Stack stack;
    if (*(path + len - 1) == '/') {
        len--;
        *(path + len) = '\0';
    }
    char *str = (char *)malloc(sizeof(char)* (len + 1));
    initStack(&stack, len);
    int status;
    while (status = getElem(&path, str)) {
        if (status == 1) {
            pushStack(&stack, str);
        } else if(status == 2){
            popStack(&stack);
        }
    }
    if (stack.top == 0) {
        stack.elem[0] = '/';
        stack.top = 1;
        stack.pos[stack.top] = 1;
    }
    stack.elem[stack.pos[stack.top]] = '\0';
    return stack.elem;
}

int main() {
    char s[] = "/.../../";
    char *ans = simplifyPath(s);
    printf("%s\n", ans);
    system("pause");
    return 0;
}
