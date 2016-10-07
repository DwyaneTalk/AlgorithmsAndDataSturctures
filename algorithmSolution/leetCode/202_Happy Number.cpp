/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Happy Number
 *             : https://leetcode.com/problems/happy-number/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

bool isHappy(int n) {
    bool flags[200];
    memset(flags, 0, sizeof(bool) * 200);
    if(n <= 0)  return false;
    int sum, r;
    while(n > 99) {
        sum = 0 ;
        while(n) {
            r = (n % 10);
            sum += r * r;
            n = n / 10;
        }
        n = sum;
    }
    while(n != 1) {
       flags[n] = 1;
       sum = 0;
        while(n) {
            r = (n % 10);
            sum += r * r;
            n = n / 10;
        }
        n = sum;
        if(flags[n]){
            break;
        }
    }
    if(n == 1)  return true;
    else return false;
}

int main() {
    int n = 19;
    bool f = isHappy(n);
    if(f) {
        printf("YES!\n");
    } else {
        printf("NO!\n");
    }
    return 0;
}
