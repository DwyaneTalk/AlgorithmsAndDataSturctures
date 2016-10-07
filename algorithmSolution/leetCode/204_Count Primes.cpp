/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Count Primes 
*             : https://leetcode.com/problems/count-primes/
*       tips  : https://primes.utm.edu/howmany.html
*             : http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    int *elem;
    int size;
} primesList;

#define MAX(x, y) ((x) > (y) ? (x) : (y))



int countPrimes(int n) {
    int count = 0;
    char *lists = (char *)malloc(sizeof(char) * n);
    int sqrt_n = sqrt((double)(n));
    int i = 3, j, next_i;
    memset(lists, 0, sizeof(char)* n);
    while (i <= sqrt_n) {
        j = i * i;
        while (j < n) {
            lists[j] = 1;
            j += i;
        }
        next_i = i + 1;
        while (lists[next_i])   next_i++;
        i = next_i;
    }
    for (i = 3; i < n; i += 2) {
        if (!lists[i]) {
         //   printf("%d\t", i);
            count++;
        }
    }
    free(lists);
    return n > 2 ? (count + 1) : 0;
}


int main() {
    int n = 30;
    int ans = countPrimes(n);
    printf("%d\n", ans);
    system("pause");
    return 0;
}
