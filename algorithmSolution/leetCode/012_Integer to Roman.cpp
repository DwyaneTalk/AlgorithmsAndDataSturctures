/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Integer to Roman
 *             : https://leetcode.com/problems/integer-to-roman/
*/

#include <stdio.h>
#include <stdlib.h>

int writeChar(int num, int ptr, char ans[], char b[]) {
    int i;
    if(num <= 3) {
        for(i = 0; i < num; i++) {
            ans[ptr++] = b[0];
        }
    } else if(num == 4) {
        ans[ptr++] = b[1];
        ans[ptr++] = b[0];
    } else if(num <=8) {
        for(i = 5; i < num; i++) {
            ans[ptr++] = b[0];
        }
        ans[ptr++] = b[1];
    } else {
        ans[ptr++] = b[2];
        ans[ptr++] = b[0];
    }
    return ptr;
}

char* intToRoman(int num) {
    char symbol[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    char *ans = (char *)malloc(50 * sizeof(char));
    char tmp[50];
    int ptr = 0, b = 0, n, i;
    while(num) {
        n = num % 10;
        ptr = writeChar(n, ptr, tmp, &symbol[b]);
        num = num / 10;
        b = b + 2;
    }
    for(i = 0; i < ptr; i++)
        ans[i] = tmp[ptr - i - 1];
    ans[ptr] = '\0';
    return ans;
}

int main() {
    int in = 1;
    while(in) {
        char *ans = intToRoman(in);
        printf("%s\n", ans);
        scanf("%d", &in);
    }
    return 0;
}
