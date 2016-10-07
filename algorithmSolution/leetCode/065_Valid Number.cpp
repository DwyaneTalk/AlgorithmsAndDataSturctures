/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Valid Number 
*             : https://leetcode.com/problems/valid-number/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


bool isNumber(char* s) {
    int len = strlen(s);
    char *e = s + len - 1;
    bool ans = true;
    while (s <= e && *s == ' ') {
        ++s;
    }
    while (s <= e && *e == ' ') {
        --e;
    }
    if (s > e)  return false;
    else        *(e + 1) = '\0';
    int sign = 0, pow = 0, point = 0, num1 = 0, num2 = 0, pnum1 = 0, pnum2 = 0;
    if (*s == '-' || *s == '+') {
        sign = *s == '-' ? -1 : 1;
        ++s;
    }
    if (*s == '.') {
        point = 1;
        ++s;
    }
    while (*s != '\0') {
        if (*s == '+' || *s == '-') {
            if (*(s - 1) != 'e')   return false;
        } else if (*s == '.') {
            if (point || pow)  return false;
            else        point = 1;
        } else if (*s == 'e'){
            if (pow || !num1)    return false;
            else        pow = 1;
        } else if (*s >= '0' && *s <= '9') {
            if (pow)    num2 = 1;
            else        num1 = 1;
            if (point)  pnum2 = 1;
            else        pnum1 = 1;
        } else {
            return false;
        }
        ++s;
    }
    if (pow)    ans = num2 == 1;
    if (point)  ans = ans && (pnum2 == 1 || pnum1 == 1);
    return ans;
}

int main() {
    char s[] = "005047e+6";
    bool ans = isNumber(s);
    if (ans)    printf("Yes!\n");
    else        printf("No!\n");
    system("pause");
    return 0;
}
