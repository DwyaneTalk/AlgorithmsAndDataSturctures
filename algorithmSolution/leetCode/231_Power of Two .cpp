/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode231  : Power of Two 
*                : https://leetcode.com/problems/power-of-two/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


bool isPowerOfTwo(int n) {
    if (n <= 0) {
        return false;
    } else {
        while (n) {
            if (n & 1) {
                n = n & (~ 1);
                break;
            } else {
                n = n >> 1;
            }
        }
        if (n)  return false;
        else    return true;
    }
}

int main() {
    int n = 0;
    bool ans = isPowerOfTwo(n);
    printf("%d\n", ans);
    system("pause");
    return 0;
}
