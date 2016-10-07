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

//  KMP�μ���http://note.youdao.com/share/?id=f6fb2232ecaa9bd9089c5044a1573d7d&type=note
//  next[j] = k ������s[0 ���� k-1] = s[j-k ���� j-1]
void getNext(char *s, int *next) {
    int len = strlen(s);
    int i = 1, j = -1; //��ʼ�� j = -1 = next[0]������next[0] = -1�������ԣ�KMP�н��ܣ��� j����next[i-1]
    next[0] = -1;
    while(i < len) {    // i = 1 ���� len - 1
        while (j != -1 && s[j] != s[i - 1]) { //��ǰһֱj = next[j]ֱ��s[j] == s[i-1]��˵��next[i] = j + 1������j == -1��˵��s[0] != s[i-1]����next[i]=0��
            j = next[j];
        }
        if (true) {
            if (s[j + 1] == s[i])   //���ֲ��ԣ�next�ĺ������в�ͬ��������KMP�У����м���
                next[i++] = next[++j];
            else
                next[i++] = ++j;
        } else {
            next[i++] = ++j;        // next[i] = ��j + 1����++j��֤����i++��j = next[i-1]
        }
    }
}

int KMP(char* str_s, char* str_p) {
    int len_p = strlen(str_p);
    int len_s = strlen(str_s);
    int end_pos = len_s - len_p;  
    int *next = (int *)malloc(sizeof(int)* len_p);
    int is = 0, ip = 0;   // is ָ��str_s�� ipָ��str_p
    getNext(str_p, next);
    while (is - ip <= end_pos && ip < len_p) { // ��is - ip > end_posʱ(len_s - is < len_p - ip)��is����֮��Ĵ�û��str_p�������Բ�ƥ��;
        if (str_s[is] == str_p[ip]) {
            is++;
            ip++;
        } else {
            ip = next[ip];
            if (ip == -1) { // ����str_p��û��û��str_s[is]������is++��ip=0������ƥ��
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


//  BM�μ���http://note.youdao.com/share/?id=0ec7e12480558021864781cc7b8a792a&type=note
//  bmBc[s]��ʾ�ַ�s��ģʽ���������ֵ�λ��
void buildBmBc(char *s, int bmBc[], int n){
    int len = strlen(s);
    int i;
    for (i = 0; i < n; ++i)
        bmBc[i] = len;  //��ʼ��Ϊlen����ʾ��ģʽ����û�г���
    for (i = 0; i < len; ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            bmBc[s[i] - '0'] = i;           // 0~9��ӦbmBc[0~9]
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            bmBc[s[i] - 'A' + 10] = i;      // A~Z��ӦbmBc[11~35]
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            bmBc[s[i] - 'a' + 10 + 26] = i; // a~z��ӦbmBc[36~61]
        } else {
            printf("unsupported char set\n");
        }
    }
}
//  suffix[i]��ʾģʽ���У���iλ��(����)��ʼ��ǰ���Ժ�ģʽ�������ʼƥ��������
void buildSuffix(char *s, int suffix[]) {
    int i, j;
    int len = strlen(s);
    suffix[len - 1] = len;      //��ʼsuffix[len - 1] = len����ʾ�����һ��λ�ú�ģʽ�������ʼƥ��������Ϊ����ģʽ��,�����ȷ���ģ����ԾͲ�����for loop�м���
    for (i = len - 2; i >= 0; --i) {
        j = i;
        while (j >= 0 && s[j] == s[len - 1 - (i - j)]) {
            --j;
        }
        suffix[i] = i - j;
    }
}
//  bmGs[i]��ʾ����ģʽ��iλ�ô����ֲ�ƥ���ǣ����ݺú�׺����iӦ����ǰ�ƶ��ľ��루ģʽ�����Ƶ�λ�ã���ģʽ���ȽϵĶ�Ӧ��ƥ�䴮�±����ӣ�
void buildBmGs(char *s, int bmGs[]){
    int len = strlen(s);
    int *suffix = (int *)malloc(sizeof(int)* len);
    int i, j = 0;
    buildSuffix(s, suffix);
    // ��ʼ��ģʽ����û���ҵ��ִ�ƥ��ú�׺��Ҳû���ҵ�һ�����ǰ׺�����ǰ׺Ҫ��ģʽ����ʼ����
    for (i = 0; i < len; ++i) {
        bmGs[i] = len;              //��ʼ��Ϊlen������bmGs[len - 1]�����ս��һ����len����Ϊ��len-1����ƥ�䣬��û�кú�׺������ģʽ��Ӧ�ú���len
    }
    // û���ҵ��ִ�ƥ��ú�׺�������ҵ������ǰ׺
    for (i = len - 1; i >= 0; i--) {    //i�Ӵ�Сѭ������Ϊ�˱�֤�ҵ��������ǰ׺
        if (suffix[i] == i + 1) {       //��ʾ��ǰ׺
            for (; j < len - 1 - i; j++) {
                if (bmGs[j] == len) {   //˵��֮ǰû���ҵ�ǰ׺������ҵ�����֮ǰ��һ�������ǰ׺������Ҫ���¸�ֵ��
                    bmGs[j] = len - 1 - i;
                }
            }
        }
    }
    // �ҵ��ַ���ƥ��ú�׺
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
    i = len_p - 1;  //�Ӻ���ǰƥ�䣬����i = len_p - 1�ǵ�һ���ǵ�һ�����ܵ�λ��
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
    // BM�㷨��O(n/m), n = strlen(haystack), m = strlen(need)��
    //  return BM(haystack, needle);

    // KMP�㷨��O(n), n=strlen(haystack)��
    //  return KMP(haystack, needle);

    // �����������
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
