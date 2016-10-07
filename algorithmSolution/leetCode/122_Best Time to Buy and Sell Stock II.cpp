/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCode : Best Time to Buy and Sell Stock II
 *            : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int maxProfit(int* prices, int pricesSize) {
    if(!prices || pricesSize < 2)   return 0;
    int sum_profit = 0, min_pre = prices[0];
    int i =1;
    while(i < pricesSize) {
        if(prices[i] > prices[i - 1]) {
            sum_profit += prices[i] - prices[i - 1];
        }
        ++i;
    }
    return sum_profit;
}

int main() {
    int numbers[] = {1, 3,5,7,2,7,98,23,54};
    int ans = maxProfit(numbers, sizeof(numbers) / sizeof(int));
    printf("max profit: %d\n", ans);
    return 0;
}
