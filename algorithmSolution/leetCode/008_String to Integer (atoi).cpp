/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCode : String to Integer (atoi)
 *            : https://leetcode.com/problems/string-to-integer-atoi/
*/

#include<stdio.h>
#include<limits.h>
#include<string.h>


int myAtoi(char* str) {
    long long ans = 0;
    int i = 0, j;
    if(str[0]){
        while(str[i] == ' ') i++;
        j = i;
        if(str[i] == '-' || str[i] == '+')  {
            i++;
        }
        while(str[i]) {
            if(str[i] > '9' || str[i] < '0')
                break;
            ans = ans * 10 + str[i++] - '0';
            if(ans > INT_MAX) break;
        }
        if (str[j] == '-') {
            ans = - ans;
            ans = ans < INT_MIN ? INT_MIN : ans;
        }else{
            ans = ans > INT_MAX ? INT_MAX : ans;
        }
    }
    return (int)(ans);
}

int main() {
    char str[] = "9223372036854775809";
    int ans = myAtoi(str);
    printf("%d\n", ans);
    return 0;
}
