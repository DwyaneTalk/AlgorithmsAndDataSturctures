/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode123   : Best Time to Buy and Sell Stock III
*                : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxProfitOneTransaction(int* lo, int* hi, int dir) {
    if (lo >= hi)   return 0;
    int *lo_ptr, *hi_ptr;
    if (dir > 0) {
        lo_ptr = lo;
        hi_ptr = hi;
    } else {
        lo_ptr = hi;
        hi_ptr = lo;
    }
    int minPrice = INT_MAX, maxProfit = 0;
    while ((hi_ptr - lo_ptr) * dir >= 0) {
        if (*lo_ptr < minPrice) minPrice = *lo_ptr;
        if (*lo_ptr - minPrice > maxProfit) maxProfit = *lo_ptr - minPrice;
        lo_ptr += dir;
    }
    return maxProfit;
}

int maxProfitDPSolution(int* prices, int pricesSize) {
    int minPrice1 = INT_MAX, minPrice2 = INT_MAX, maxProfit1 = 0, maxProfit2 = 0;
    for (int i = 0; i < pricesSize; ++i) {
        minPrice1 = MIN(prices[i], minPrice1);
        maxProfit1 = MAX(prices[i] - minPrice1, maxProfit1);
        minPrice2 = MIN(prices[i] - maxProfit1, minPrice2);
        maxProfit2 = MAX(prices[i] - minPrice2, maxProfit2);
    }
    return maxProfit2;
}

int maxProfitReverseSolution(int* prices, int pricesSize) {
    int loIndx = 0, hiIndex = 0, maxProfit = 0, minPrice = prices[0], minPriceIndex = 0;
    for (int i = 1; i < pricesSize; ++i) {
        if (prices[i] < minPrice) {
            minPrice        = prices[i];
            minPriceIndex = i;
        }
        if (prices[i] - minPrice > maxProfit) {
            maxProfit   = prices[i] - minPrice;
            loIndx      = minPriceIndex;
            hiIndex = i;
        }
    }
    int leftMaxProfit = maxProfitOneTransaction(prices, prices + loIndx - 1, 1);
    int rightMaxProfit = maxProfitOneTransaction(prices + hiIndex + 1, prices + pricesSize - 1, 1);
    int midMaxProfit = maxProfitOneTransaction(prices + loIndx + 1, prices + hiIndex - 1, -1);
    return maxProfit + MAX(MAX(leftMaxProfit, rightMaxProfit), midMaxProfit);
}

int maxProfit(int* prices, int pricesSize) {
    if (!prices || pricesSize < 2)     return 0;
    if (rand() % 2)  return maxProfitReverseSolution(prices, pricesSize);
    else    return maxProfitDPSolution(prices, pricesSize);
}

int main() {
    int prices[] = { 2, 3, 4, 5, 3, 1, 5, 8, 6, 3, 10, 6, 4, 5, 7};
    printf("ans : %d\n", maxProfit(prices, sizeof(prices) / sizeof(int)));
    system("pause");
    return 0;
}
