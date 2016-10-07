/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Length of Last Word
 *             : https://leetcode.com/problems/length-of-last-word/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int lengthOfLastWord(char* s) {
    int len = strlen(s);
    if(!s || !len)    return 0;
    char *e = s + len - 1, *ee;
    while(*e == ' ' && e >= s) --e;
    ee = e;
    while(*e != ' ' && e >= s)    --e;
    if(e < s)   return ee - e;
    else return ee - e;
}

int main() {
    char s[] = "Hello wor ld";
    int ans = lengthOfLastWord(s);
    printf("%d\n", ans);
    return 0;
}
