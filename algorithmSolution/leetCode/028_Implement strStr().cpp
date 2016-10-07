/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Remove Element
*             : https://leetcode.com/problems/remove-element/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

//  KMP参见：http://note.youdao.com/share/?id=f6fb2232ecaa9bd9089c5044a1573d7d&type=note
//  next[j] = k 表明：s[0 …… k-1] = s[j-k …… j-1]
void getNext(char *s, int *next) {
    int len = strlen(s);
    int i = 1, j = -1; //初始： j = -1 = next[0]（关于next[0] = -1的特殊性，KMP中介绍）， j保存next[i-1]
    next[0] = -1;
    while(i < len) {    // i = 1 …… len - 1
        while (j != -1 && s[j] != s[i - 1]) { //往前一直j = next[j]直到s[j] == s[i-1]（说明next[i] = j + 1）或者j == -1（说明s[0] != s[i-1]，则next[i]=0）
            j = next[j];
        }
        if (true) {
            if (s[j + 1] == s[i])   //这种策略，next的含义略有不同，但是在KMP中，会有加速
                next[i++] = next[++j];
            else
                next[i++] = ++j;
        } else {
            next[i++] = ++j;        // next[i] = （j + 1），++j保证了在i++后j = next[i-1]
        }
    }
}

int KMP(char* str_s, char* str_p) {
    int len_p = strlen(str_p);
    int len_s = strlen(str_s);
    int end_pos = len_s - len_p;  
    int *next = (int *)malloc(sizeof(int)* len_p);
    int is = 0, ip = 0;   // is 指向str_s， ip指向str_p
    getNext(str_p, next);
    while (is - ip <= end_pos && ip < len_p) { // 当is - ip > end_pos时(len_s - is < len_p - ip)，is及其之后的串没有str_p长，所以不匹配;
        if (str_s[is] == str_p[ip]) {
            is++;
            ip++;
        } else {
            ip = next[ip];
            if (ip == -1) { // 表明str_p中没有没有str_s[is]，所以is++，ip=0。继续匹配
                ip = 0;
                is++;
            }
        }
    }
    if (ip == len_p)
        return is - ip;
    else
        return -1;
}


//  BM参见：http://note.youdao.com/share/?id=0ec7e12480558021864781cc7b8a792a&type=note
//  bmBc[s]表示字符s在模式串中最后出现的位置
void buildBmBc(char *s, int bmBc[], int n){
    int len = strlen(s);
    int i;
    for (i = 0; i < n; ++i)
        bmBc[i] = len;  //初始化为len，表示在模式串中没有出现
    for (i = 0; i < len; ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            bmBc[s[i] - '0'] = i;           // 0~9对应bmBc[0~9]
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            bmBc[s[i] - 'A' + 10] = i;      // A~Z对应bmBc[11~35]
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            bmBc[s[i] - 'a' + 10 + 26] = i; // a~z对应bmBc[36~61]
        } else {
            printf("unsupported char set\n");
        }
    }
}
//  suffix[i]表示模式串中，从i位置(包括)开始向前可以和模式串从最后开始匹配的最长长度
void buildSuffix(char *s, int suffix[]) {
    int i, j;
    int len = strlen(s);
    suffix[len - 1] = len;      //初始suffix[len - 1] = len，表示从最后一个位置和模式串从最后开始匹配的最长长度为整个模式串,这个是确定的，所以就不放在for loop中计算
    for (i = len - 2; i >= 0; --i) {
        j = i;
        while (j >= 0 && s[j] == s[len - 1 - (i - j)]) {
            --j;
        }
        suffix[i] = i - j;
    }
}
//  bmGs[i]表示当在模式串i位置处出现不匹配是，根据好后缀规则，i应该向前移动的距离（模式串后移的位置，和模式串比较的对应待匹配串下标增加）
void buildBmGs(char *s, int bmGs[]){
    int len = strlen(s);
    int *suffix = (int *)malloc(sizeof(int)* len);
    int i, j = 0;
    buildSuffix(s, suffix);
    // 初始：模式串中没有找到字串匹配好后缀，也没有找到一个最大前缀（最大前缀要从模式串开始处）
    for (i = 0; i < len; ++i) {
        bmGs[i] = len;              //初始化为len。对于bmGs[len - 1]，最终结果一定是len，因为当len-1出不匹配，则没有好后缀，所以模式串应该后移len
    }
    // 没有找到字串匹配好后缀，但是找到了最大前缀
    for (i = len - 1; i >= 0; i--) {    //i从大到小循环，是为了保证找到的是最大前缀
        if (suffix[i] == i + 1) {       //表示是前缀
            for (; j < len - 1 - i; j++) {
                if (bmGs[j] == len) {   //说明之前没有找到前缀（如果找到，则之前的一定的最大前缀，不需要重新赋值）
                    bmGs[j] = len - 1 - i;
                }
            }
        }
    }
    // 找到字符串匹配好后缀
    for (i = 0; i < len - 1; ++i) {
        bmGs[len - 1 - suffix[i]] = len - 1 - i;
    }

}
int BM(char* str_s, char* str_p) {
    int len_s = strlen(str_s);
    int len_p = strlen(str_p);
    int bmBc[62];
    int *bmGs = (int *)malloc(sizeof(int)* len_p);
    int i, j, val = 0;
    buildBmBc(str_p, bmBc, 62);
    buildBmGs(str_p, bmGs);
    i = len_p - 1;  //从后向前匹配，所以i = len_p - 1是第一个是第一个可能的位置
    j = len_p - 1;
    while (i < len_s) {
        while (j >= 0 && str_s[i] == str_p[j]) {
            j--;
            i--;
        }
        if (j < 0)
            return i + 1;
        else  {
            if (str_s[i] >= '0' && str_s[i] <= '9')
                val = str_s[i] - '0';
            else if (str_s[i] >= 'A' && str_s[i] <= 'Z')
                val = str_s[i] - 'A' + 10;
            else if (str_s[i] >= 'a' && str_s[i] <= 'z')
                val = str_s[i] - 'a' + 10 + 26;
            else
                printf("unsupported char set\n");
            i = len_p - 1 + i - j + MAX(bmGs[j], j - bmBc[val]);
            j = len_p - 1;
        }
    }
    return -1;
}

int strStr(char* haystack, char* needle) {
    // BM算法（O(n/m), n = strlen(haystack), m = strlen(need)）
    //  return BM(haystack, needle);

    // KMP算法（O(n), n=strlen(haystack)）
    //  return KMP(haystack, needle);

    // 暴力搜索解决
    char *ptr1 = haystack, *ptr2 = needle;
    int len1 = strlen(haystack);
    int len2 = strlen(needle);
    char *p_end = ptr1 + (len1 - len2);
    //while (*ptr1) {
    while (ptr1 <= p_end) { // much more efficient when len2 is large
            // if (strncmp(ptr1, ptr2, len) == 0)
        if (memcmp(ptr1, ptr2, len2) == 0)   // more efficient
            return (ptr1 - haystack);
        ptr1++;
    }
    return *ptr2 == '\0' ? 0 : -1;
}

int main() {
    char str1[] = "baaa";
    char str2[] = "aaa";
    int ans1 = strStr(str1, str2);
    int ans2 = KMP(str1, str2);
    int ans3 = BM(str1, str2);
    printf("%d\n", ans1);
    printf("%d\n", ans2);
    printf("%d\n", ans3);
    system("pause");
    return 0;
}
