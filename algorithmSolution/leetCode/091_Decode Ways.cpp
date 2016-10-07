/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode91   : Decode Ways
*                : https://leetcode.com/problems/decode-ways/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <algorithm>


//int numDecodings(char* s) {
//    int nums, num_end;
//    if (!s || !(nums = strlen(s)))  return 0;
//    int *ways = (int*)malloc(sizeof(int)* (nums + 1));
//    ways[0] = 1;
//    ways[1] = '0' != s[0];
//    num_end = (*s != '0' ? 0 : -1);
//    for (int i = 1; i < nums; ++i) {
//        if (s[i] == '0') {
//            if (i - num_end > 1) {
//                ways[i + 1] = 0;
//            } else {
//                if (s[num_end] <= '2') {
//                    ways[i + 1] = ways[i - 1];
//                } else {
//                    ways[i + 1] = 0;
//                }
//            }
//        } else {
//            if (i - num_end > 1) {
//                if (s[num_end] <= '2') {
//                    ways[i + 1] = ways[num_end + 1] + ways[num_end + 2];
//                } else {
//                    ways[i + 1] = ways[num_end + 1];
//                }
//            } else {
//                if (10 * (s[i - 1] - '0') + (s[i] - '0') <= 26) {
//                    ways[i + 1] = ways[i] + ways[i - 1];
//                } else {
//                    ways[i + 1] = ways[i];
//                }
//            }
//            num_end = i;
//        }
//    }
//    int ans = ways[nums];
//    free(ways);
//    return ans;
//}

int numDecodings(char* s) {
    int nums, num_end;
    if (!s || !(nums = strlen(s)) || *s == '0')  return 0;
    int *ways = (int*)malloc(sizeof(int)* (nums + 1));
    ways[0] = ways[1] = 1;
    num_end = 0;
    for (int i = 1; i < nums; ++i) {
        if (s[i] == '0') {
            if (i - num_end > 1)    
                ways[i] = 0;
            else if (s[num_end] <= '2')
                ways[i + 1] = ways[i - 1];
            else   
                ways[i + 1] = 0;
        } else {
            if (i - num_end > 2)    
                ways[i + 1] = 0;
            else if (i - num_end > 1) {
                if (s[num_end] <= '2')  
                    ways[i + 1] = ways[num_end + 2];
                else    
                    ways[i + 1] = 0;
            } else {
                if (10 * (s[i - 1] - '0') + (s[i] - '0') <= 26)
                    ways[i + 1] = ways[i] + ways[i - 1];
                else
                    ways[i + 1] = ways[i];
            }
            num_end = i;
        }
    }
    int ans = ways[nums];
    free(ways);
    return ans;
}

int main() {
    char s[] = "201";
    int ans = numDecodings(s);
    printf("%d\n", ans);
    system("pause");
    return 0;
}
