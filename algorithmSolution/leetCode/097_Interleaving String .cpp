/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode97   : Interleaving String 
*                : https://leetcode.com/problems/interleaving-string/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

bool solution1(char* s1, char* s2, char* s3) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len3 = strlen(s3);
    if (len1 + len2 != len3)    return false;
    bool **is_ans = (bool**)malloc(sizeof(bool*)* (len1 + 1));
    for (int i = 0; i <= len1; ++i) {
        is_ans[i] = (bool*)malloc(sizeof(bool)* (len2 + 1));
    }
    char ch1, ch2, ch3;
    is_ans[0][0] = true;
    for (int i = 1; i <= len1; ++i) {
        is_ans[i][0] = ((s1[i - 1] == s3[i - 1]) && is_ans[i - 1][0]);
    }
    for (int i = 1; i <= len2; ++i) {
        is_ans[0][i] = ((s2[i - 1] == s3[i - 1]) && is_ans[0][i - 1]);
    }
    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            ch1 = s1[i - 1];
            ch2 = s2[j - 1];
            ch3 = s3[i + j - 1];
            if (ch1 == ch2) {
                if (ch1 == ch3)
                    is_ans[i][j] = (is_ans[i - 1][j] || is_ans[i][j - 1]);
                else
                    is_ans[i][j] = false;
            } else {
                if (ch1 == ch3)
                    is_ans[i][j] = is_ans[i - 1][j];
                else if (ch2 == ch3)
                    is_ans[i][j] = is_ans[i][j - 1];
                else
                    is_ans[i][j] = false;
            }
        }
    }
    bool ans = is_ans[len1][len2];
    for (int i = 0; i <= len1; ++i)
        free(is_ans[i]);
    free((is_ans));
    return ans;
}

bool solution2(char* s1, char* s2, char* s3) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len3 = strlen(s3);
    if (len1 + len2 != len3)    return false;
    char ch1, ch2, ch3;
    bool* cur_row = (bool*)malloc(sizeof(bool)* (len2 + 1));
    bool* pre_row = (bool*)malloc(sizeof(bool)* (len2 + 1));
    pre_row[0] = true;
    for (int i = 1; i <= len2; ++i) {
        pre_row[i] = ((s2[i - 1] == s3[i - 1]) && pre_row[i - 1]);
    }
    for (int i = 1; i <= len1; ++i) {
        cur_row[0] = ((s1[i - 1] == s3[i - 1]) && pre_row[0]);
        for (int j = 1; j <= len2; ++j) {
            ch1 = s1[i - 1];
            ch2 = s2[j - 1];
            ch3 = s3[i + j - 1];
            if (ch1 == ch2) {
                if (ch1 == ch3)
                    cur_row[j] = (pre_row[j] || cur_row[j - 1]);
                else
                    cur_row[j] = false;
            } else {
                if (ch1 == ch3)
                    cur_row[j] = pre_row[j];
                else if (ch2 == ch3)
                    cur_row[j] = cur_row[j - 1];
                else
                    cur_row[j] = false;
            }

        }
        memcpy(pre_row, cur_row, sizeof(bool)* (len2 + 1));
    }
    bool ans = pre_row[len2];
    free(cur_row);
    free(pre_row);
    return ans;
}

bool solution3(char* s1, char* s2, char* s3, int l1, int l2) {
    if (!l1 && !l2) return true;
    else if (!l2) {
        return !memcmp(s1, s3, l1);
    } else if (!l1) {
        return !memcmp(s2, s3, l2);
    } else {
        char ch1 = s1[l1 - 1];
        char ch2 = s2[l2 - 1];
        char ch3 = s3[l1 + l2 - 1];
        if (ch1 == ch2) {
            if (ch1 == ch3)
                return solution3(s1, s2, s3, l1 - 1, l2) || solution3(s1, s2, s3, l1, l2 - 1);
            else
                return false;
        } else {
            if (ch1 == ch3)
                return solution3(s1, s2, s3, l1 - 1, l2);
            else if (ch2 == ch3)
                return solution3(s1, s2, s3, l1, l2 - 1);
            else
                return false;
        }
    }
}

bool isInterleave(char* s1, char* s2, char* s3) {
    return solution3(s1, s2, s3, strlen(s1), strlen(s2));
    if (rand() % 2) return solution1(s1, s2, s3);
    else            return solution2(s1, s2, s3);
    //solution3当s1和s2中存在很多相同字符时，会超时
}

int main() {
    char s1[] = "baababbabbababbaaababbbbbbbbbbbaabaabaaaabaaabbaaabaaaababaabaaabaabbbbaabbaabaabbbbabbbababbaaaabab";
    char s2[] = "aababaaabbbababababaabbbababaababbababbbbabbbbbababbbabaaaaabaaabbabbaaabbababbaaaababaababbbbabbbbb";
    char s3[] = "babbabbabbababbaaababbbbaababbaabbbbabbbbbaaabbabaababaabaaabaabbbaaaabbabbaaaaabbabbaabaaaabbbbababbbababbabaabababbababaaaaaabbababaaabbaabbbbaaaaabbbaaabbbabbbbaaabaababbaabababbbbababbaaabbbabbbab";
    if (isInterleave(s1, s2, s3)) {
        printf("Yes!\n");
    } else {
        printf("No!\n");
    }
    system("pause");
    return 0;
}
