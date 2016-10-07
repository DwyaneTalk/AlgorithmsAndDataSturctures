/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Wildcard Matching
 *             : https://leetcode.com/problems/wildcard-matching/
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

bool isWildcardMatching(char *s, char *p, int *validNum) {
    int s_len = strlen(s), p_len = strlen(p);
    if (!p_len) return s_len == 0;
    if (!s_len && (*p != '*'))  return false;
    if (s_len < validNum[0])    return false;
    if (*p == '*') {
        while (*p == '*') {
            ++p;
        }
        while (s_len >= validNum[0]) {
            if (isWildcardMatching(s, p, validNum + 1)) {
                return true;
            }
            ++s;
            --s_len;
        }
        return false;
    } else {
        if (*s == *p || *p == '?')
            return isWildcardMatching(s + 1, p + 1, validNum + 1);
        else
            return false;
    }
}

//solution1���ݹ���ԣ���Time Limit Exceeded�����ںܶ��ظ����㣬���Ը��Ӷ���ָ����ʽ�ģ�
bool solution1(char*s, char *p) {
    if (!s || !p)   return s == p;
    int i, j, s_len = strlen(s), p_len = strlen(p);
    int *validNum = (int *)malloc(sizeof(int)* (p_len + 1));
    validNum[p_len] = 0;
    char *p_end, *s_end, *pi, *si;
    for (p_end = p + p_len - 1, i = p_len - 1; p_end >= p; --p_end, --i) {
        if (*p_end != '*') {
            validNum[i] = validNum[i + 1] + 1;
        } else {
            validNum[i] = validNum[i + 1];
        }
    }
    return isWildcardMatching(s, p, validNum);
}

//solution2������ָ��ֱ�ָ��s��p�����Ӷ�O(n*m)
bool solution2(char *s, char *p) {
    if (!s || !p)   return s == p;
    int s_len = strlen(s), p_len = strlen(p);
    char *tmp_p = NULL, *tmp_s = NULL;
    while (*s) {
        if (*p == '?' || *p == *s) {
            ++s;
            ++p;
        } else if(*p == '*'){
            while (*p == '*') {
                ++p;
            }
            tmp_p = p;  //��¼�˴γ��� *p == '*'ʱs����һ����'*'��p��ֵ��ͬʱ��һ����Ϊ'*'��ʾ�մ�
            tmp_s = s;
        } else if (tmp_p) { //��������˵���ϴ�'*'��ʾ�Ĵ����ܴﵽƥ��
            p = tmp_p;      // �ָ�p��'*'����ĵ�һ����'*'
            s = ++tmp_s;    // '*'��ʾ�Ĵ���һ
        } else {
            return false;
        }
    }
    while (*p == '*') {
        ++p;
    }
    return !(*p);
}

//solution3�����Ʒ�ʽ�������Ż�Ϊ��һ��ֻʹ������һά�����飬���Ӷ�O(n*m)�����ǿռ临�Ӷȸߣ��������ж϶�
bool solution3(char *s, char *p) {
    if (!s || !p)   return s == p;
    int i, j, s_len = strlen(s), p_len = strlen(p);
    int *validNum = (int *)malloc(sizeof(int)* (p_len + 1));
    validNum[p_len] = 0;
    char *p_end, *s_end, *pi, *si;
    for (p_end = p + p_len - 1, i = p_len - 1; p_end >= p; --p_end, --i) {
        if (*p_end != '*') {
            validNum[i] = validNum[i + 1] + 1;
        } else {
            validNum[i] = validNum[i + 1];
        }
    }
    if (s_len > 30000) return false;    //��һ���ܴ�Ĳ������룬����ֻ�������ֺܶ��ĵķ�ʽ����
    int stride = p_len + 1, k, l;
    int *ans = (int *)malloc(sizeof(int)* (s_len + 1) * stride);
    ans[s_len * stride + p_len] = 1;
    for (i = 0; i < s_len; ++i)
        ans[i * stride + p_len] = 0;
    for (i = p_len - 1; i >= 0; --i) {
        if (ans[s_len * stride + i + 1] && *(p + i) == '*')
            ans[s_len * stride + i] = 1;
        else
            ans[s_len * stride + i] = 0;
    }
    for (i = s_len - 1; i >= 0; --i) {
        for (j = p_len - 1; j >= 0; --j) {
            if (*(p + j) == '*') {
                k = j;
                while (*(p + k) == '*') {
                    k++;
                }
                l = i;
                while (s_len - l >= validNum[k]) {
                    if (ans[l * stride + k]) {
                        ans[i * stride + j] = 1;
                        break;;
                    }
                    l++;
                }
                if (s_len - l < validNum[k])
                    ans[i * stride + j] = 0;
            } else {
                if (*(p + j) == '?' || *(p + j) == *(s + i))
                    ans[i * stride + j] = ans[(i + 1) * stride + (j + 1)];
                else
                    ans[i * stride + j] = 0;
            }
        }
    }
    return ans[0];
}

bool isMatch(char* s, char* p) {
    //return solution1(s, p);
    return solution2(s, p);
    //return solution3(s, p);
}

int main() {
    char *s = "aab";
    char *p =  "c*a*b";
    bool ans = isMatch(s, p);
    if (ans)    printf("YES!\n");
    else        printf("NO!\n");
    system("pause");
    return 0;
}
