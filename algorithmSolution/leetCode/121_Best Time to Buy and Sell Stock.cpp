/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode121  : Best Time to Buy and Sell Stock
*                : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int maxProfit(int* prices, int pricesSize) {
    if(!prices || pricesSize < 2)
        return 0;
    int max_ans = 0, pre_min = prices[0];
    for(int i = 1; i < pricesSize; ++i) {
        if(prices[i] - pre_min > max_ans) {
            max_ans = prices[i] - pre_min;
        }
        if(prices[i] < pre_min) {
            pre_min = prices[i];
        }
    }
    return max_ans;
}

int main() {
    int prices[] = {1, 2, 3, 5};
    int profit = maxProfit(prices, 4);
    printf("ans :%d\n", profit);
    system("pause");
    return 0;
}
