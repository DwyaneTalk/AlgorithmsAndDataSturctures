/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Roman to Integer
 *             : https://leetcode.com/problems/roman-to-integer/
*/

#include <stdio.h>
#include <string.h>


int romanToInt(char* s) {
    int table[26] = {0};
    int ans = 0, ptr = 0, ptr2 = 0;
    table['I' - 'A'] = 1;
    table['V' - 'A'] = 5;
    table['X' - 'A'] = 10;
    table['L' - 'A'] = 50;
    table['C' - 'A'] = 100;
    table['D' - 'A'] = 500;
    table['M' - 'A'] = 1000;
    while(s[ptr] != '\0') {
        ptr2 = ptr;
        while(s[ptr2] != '\0' && s[ptr2] == s[ptr]) {
            ptr2++;
        }
        if(s[ptr2] != '\0' && table[s[ptr2] - 'A'] > table[s[ptr] - 'A']) {
            ans = ans - table[s[ptr] - 'A'] * (ptr2 - ptr);
        } else {
            ans = ans + table[s[ptr] - 'A'] * (ptr2 - ptr);
        }
        ptr = ptr2;
    }
    return ans;
}

int main() {
    int ans;
    char in[100];
    scanf("%s", in);
    while(in[0] != 'q') {
        ans = romanToInt(in);
        printf("%s\n", in);
        printf("%d\n", ans);
        scanf("%s", in);
    }
    return 0;
}
