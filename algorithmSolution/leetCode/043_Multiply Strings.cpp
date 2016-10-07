/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Multiply Strings 
*             : https://leetcode.com/problems/multiply-strings/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

char* singleMultiply(char* num, char ch) {
    int len = strlen(num);
    char *ans = (char *)calloc(len + 2, sizeof(char));
    int i, carry = 0, j, val = ch - '0';
    for (i = len - 1, j = 0; i >= 0; i--, j++) {
        carry = (num[i] - '0') * val + carry;
        ans[j] = carry % 10 + '0';
        carry = carry / 10;
    }
    if (carry)
        ans[j] = carry + '0';
    return ans;
}

void addition(char* num1, char* num2) {
    int i, val, carry = 0, len = strlen(num2);
    for (i = 0; i < len; ++i) {
        val = num1[i] - '0' + num2[i] - '0' + carry;
        if (val >= 10) {
            carry = 1;
            num1[i] = val - 10 + '0';
        } else {
            carry = 0;
            num1[i] = val + '0';
        }
    }
    while (num1[i] - '0' + carry >= 10) {
        num1[i] = 0;
    }
    num1[i] = num1[i] + carry;
}

char* multiply(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    char *ans = (char *)malloc(sizeof(char)* (len1 + len2 + 1));
    char *tmp[10] = {NULL};
    int i, j = 0;
    char ex_tmp;
    for (i = 0; i <= len1 + len2; ++i) {
        ans[i] = '0';
    }
    for (i = len2 - 1; i >= 0; --i, ++j) {
        if (!tmp[num2[i] - '0']) {
            tmp[num2[i] - '0'] = singleMultiply(num1, num2[i]);
        }
        addition(ans + j, tmp[num2[i] - '0']);
    }
    i = len1 + len2;
    j = 0;
    while (i >= 0 && ans[i] == '0') --i;
    if (i >= 0) {
        ans[i + 1] = '\0';
        while (i > j) {
            ex_tmp = ans[i];
            ans[i] = ans[j];
            ans[j] = ex_tmp;
            --i;
            ++j;
        }
    } else {
        ans[1] = '\0';
    }
    for (i = 0; i <= 9; ++i) {
        if (tmp[i]) free(tmp[i]);
    }
    return ans;
}

int main() {
    char *num1 = "0";
    char *num2 = "0";
    char *ans = multiply(num1, num2);
    printf("%s\n", ans);
    system("pause");
    return 0;
}
