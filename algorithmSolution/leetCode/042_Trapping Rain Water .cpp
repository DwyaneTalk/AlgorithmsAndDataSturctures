/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Trapping Rain Water 
*             : https://leetcode.com/problems/trapping-rain-water/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int getMaxIndex(int *height, int lo, int hi) {
    int i = lo + 1,val = height[lo], ans = lo;
    for (; i <= hi; ++i) {
        if (height[i] > val) {
            val = height[i];
            ans = i;
        }
    }
    return ans;
}

void getMaxTwoIndex(int *height, int lo, int hi, int *left, int *right) {
    int index, l_index = -1, r_index = -1;
    index = getMaxIndex(height, lo, hi);
    if (index > lo) {
        l_index = getMaxIndex(height, lo, index - 1);
    }
    if (index < hi) {
        r_index = getMaxIndex(height, index + 1, hi);
    }
    if (l_index == -1) {
        *left = index;
        *right = r_index;
    } else if (r_index == -1) {
        *left = l_index;
        *right = index;
    } else {
        if (height[l_index] > height[r_index]) {
            *left = l_index;
            *right = index;
        } else {
            *left = index;
            *right = r_index;
        }
    }
}

// solution2: 分值策略（根据当前范围内的两个最高点，分成3部分）
int solution2(int *height, int lo, int hi) {
    int ans, left, right, i;
    if (hi - lo < 2)    return 0;
    getMaxTwoIndex(height, lo, hi, &left, &right);
    ans = (right - left - 1) * MIN(height[left], height[right]);
    for (i = left + 1; i < right; ++i)
        ans -= height[i];
    ans += solution2(height, lo, left);
    ans += solution2(height, right, hi);
    return ans;
}

// solution1：双指针
int solution1(int *height, int lo, int hi) {
    int lo_max = height[lo], hi_max = height[hi], ans = 0;
    while (lo <= hi) {
        lo_max = MAX(lo_max, height[lo]);
        hi_max = MAX(hi_max, height[hi]);
        if (lo_max < hi_max) {
            ans += lo_max - height[lo];
            lo++;
        } else {
            ans += hi_max - height[hi];
            hi--;
        }
    }
    return ans;
}

int trap(int* height, int heightSize) {
    return solution1(height, 0, heightSize-1);
    //return solution2(height, 0, heightSize - 1);
}

int main() {
    int nums[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    int ans = trap(nums, sizeof(nums) / sizeof(int));
    printf("%d\n", ans);
    system("pause");
    return 0;
}
