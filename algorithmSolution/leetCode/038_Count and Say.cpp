/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Count and Say
*             : https://leetcode.com/problems/count-and-say/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_SIZE 1000
#define RENEW_SIZE 100

typedef struct String{
    int size;
    int max_size;
    char *elem;
} String;

void initString(String *string) {
    if (string->elem = (char *)malloc(sizeof(char)* INIT_SIZE)) {
        string->size = 0;
        string->max_size = INIT_SIZE;
    }
}

void addChar(String *string, char ch) {
    if (string->size < string->max_size) {
        string->elem[string->size] = ch;
        if (ch) (string->size)++;
    } else {
        string->max_size += RENEW_SIZE;
        string->elem = (char *)realloc(string->elem, sizeof(char)* string->max_size);
        string->elem[string->size] = ch;
        if (ch) (string->size)++;
    }
}

void addInt(String *string, int n) {
    if (n < 10) {
        addChar(string, '0' + n);
    } else {
        addInt(string, n / 10);
        addInt(string, n % 10);
    }
}

char* countAndSay(int n) {
    if (n <= 0) {
        return NULL;
    }
    String str1, str2;
    String *ptr1 = &str1, *ptr2 = &str2;
    initString(ptr1);
    initString(ptr2);
    addChar(ptr1, '1');
    addChar(ptr1, 0);
    int i = 1, pos = 0, last_pos = 0;
    char val;
    while (++i <= n) {
        if (i & 1) {
            ptr1->size = 0;
            last_pos = 0;
            val = ptr2->elem[0];
            pos = 1;
            while (ptr2->elem[pos]) {
                if (ptr2->elem[pos] != val) {
                    addInt(ptr1, pos - last_pos);
                    addChar(ptr1, val);
                    val = ptr2->elem[pos];
                    last_pos = pos;
                }
                pos++;
            }
            addInt(ptr1, pos - last_pos);
            addChar(ptr1, val);
            addChar(ptr1, 0);
        } else {
            ptr2->size = 0;
            last_pos = 0;
            val = ptr1->elem[0];
            pos = 1;
            while (ptr1->elem[pos]) {
                if (ptr1->elem[pos] != val) {
                    addInt(ptr2, pos - last_pos);
                    addChar(ptr2, val);
                    val = ptr1->elem[pos];
                    last_pos = pos;
                }
                pos++;
            }
            addInt(ptr2, pos - last_pos);
            addChar(ptr2, val);
            addChar(ptr2, 0);
        }
    }
    if (n & 1) {
        free(ptr2->elem);
        return ptr1->elem;
    } else {
        free(ptr1->elem);
        return ptr2->elem;
    }
}

int main() {
    int n = 4;
    char *ans;
    for (n = 1; n < 20; n++) {
        ans = countAndSay(n);
        printf("%d\n%s\n\n", n, ans);
    }
    system("pause");
    return 0;
}
