/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Add Binary
*             : https://leetcode.com/problems/add-binary/
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

char* addBinary(char* a, char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    if (!len_a || !a)   return b;
    if (!len_b || !b)   return a;
    int len_max = MAX(len_a, len_b) + 1;
    char *ans = (char *)malloc(sizeof(char)* (len_max + 1));
    ans += len_max - 1;
    *(ans + 1) = '\0';
    int carry = 0;
    char *ptr_a = a + len_a - 1;
    char *ptr_b = b + len_b - 1;
    while (ptr_a >= a && ptr_b >= b) {
        *ans = (carry ^ (*ptr_a - '0') ^ (*ptr_b - '0')) + '0';
        carry = (carry + *ptr_a - '0' + *ptr_b - '0') >= 2;
        --ptr_a;
        --ptr_b;
        --ans;
    }
    while (ptr_a >= a) {
        *ans = (carry ^ (*ptr_a - '0')) + '0';
        carry = (carry + *ptr_a - '0') >= 2;
        --ptr_a;
        --ans;
    }
    while (ptr_b >= b) {
        *ans = (carry ^ (*ptr_b - '0')) + '0';
        carry = (carry + *ptr_b - '0') >= 2;
        --ptr_b;
        --ans;
    }
    if (carry)  *ans = '1';
    else        ++ans;
    return ans;
}

int main() {
    char a[] = "101";
    char b[] = "101";
    char *ans = addBinary(a, b);
    printf("%s", ans);
    system("pause");
    return 0;
}
