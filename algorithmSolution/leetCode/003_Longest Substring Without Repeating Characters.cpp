/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCode : Longest Substring Without Repeating Characters
 *            : https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

#include<stdio.h>
#include<string.h>

//  O(n^2)的复杂度
//int lengthOfLongestSubstring(char* s) {
//    int ans = 1, low = 0, i = 1, k;
//    if (s[0] == '\0') {
//        return 0;
//    }
//    while(s[i] != '\0') {
//        for(k = i - 1; k >= low; k--) {
//            if(s[k] == s[i]) {
//                low = k + 1;
//                break;
//            }
//        }
//        if( i - low + 1 > ans) {
//            ans = i - low + 1;
//        }
//        i++;
//    }
//    return ans;
//}

//  O(n)的复杂度
int lengthOfLongestSubstring(char* s) {
    int ans = 1, low = 0, pos ,i = 1;
    int position[255];
    if (s[0] == '\0')   return 0;
    memset(position, -1, 255 * sizeof(int));
    position[s[0]] = 0;
    while(s[i] != '\0') {
        pos = position[s[i]];
        if (pos == -1) {
            if (i - low + 1 > ans)
                ans = i - low + 1;
        } else {
            if (low <= pos) {
                low = pos + 1;
            } else {
                if( i - low + 1 > ans) {
                    ans = i - low + 1;
                }
            }
        }
        position[s[i]] = i;
        i++;
    }
    return ans;
}

int main() {
    char s[] = "askdbadsf";
    int ans = lengthOfLongestSubstring(s);
    printf("ans=%d\n", ans);
    return 0;
}

