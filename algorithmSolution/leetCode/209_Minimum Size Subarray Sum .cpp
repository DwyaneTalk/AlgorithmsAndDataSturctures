/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Minimum Size Subarray Sum
 *             : https://leetcode.com/problems/minimum-size-subarray-sum/
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MIN(a, b) ((a) > (b) ? (b) : (a))

// 暴力搜索+分支限界
int solution1(int s, int *nums, int numsSize) {
    int *last_max = (int *)malloc(sizeof(int)* numsSize);
    int i, j, max_val = 0;
    for (i = numsSize - 1; i >= 0; --i) {
        if (nums[i] > max_val)  max_val = nums[i];
        last_max[i] = max_val;
    }
    int min_len = INT_MAX, sum = 0;
    for (i = 0; i < numsSize; ++i) {
        sum = 0;
        for (j = i; j < numsSize; ++j) {
            if (j - i + 1 >= min_len)   break;
            if (sum + (numsSize - j) * last_max[j] < s)    break;
            sum = sum + nums[j];
            if (sum >= s) { 
                min_len = j - i + 1; 
                break;
            }
        }
    }
    return min_len == INT_MAX ? 0 : min_len;
}

// DP
int solution2(int s, int *nums, int numsSize) {
    int i, j, min_len = INT_MAX, sum = 0;
    for (i = 0; i < numsSize; ++i) {
            sum = sum + nums[i];
            if (sum >= s) {
                min_len = i + 1;
                break;
            }
    }
    if (i == numsSize)  return 0;
    j = i - min_len + 2;
    sum = sum - nums[j - 1];
    while (sum >= s) {
        sum -= nums[j++];
    }
    if (j > i - min_len + 1) {
        min_len = i - j + 2;
        sum += nums[j - 1];
    }
    for (++i; i < numsSize; ++i) {
        j = i - min_len + 1;
        sum = sum - nums[j - 1] + nums[i];
        while (sum >= s) {
            sum -= nums[j++];
        }
        if (j > i - min_len + 1) {
            min_len = i - j + 2;
            sum += nums[j - 1];
        }
    }
    return min_len == INT_MAX ? 0 : min_len;
}

// two pointer
int solution3(int s, int *nums, int numsSize) {
    int sum = nums[0], min_len = INT_MAX;
    int p1 = 0, p2 = 0;
    while (p1 < numsSize && p2 <= p1) {
        if (sum < s) {
            if (++p1 < numsSize)
                sum += nums[p1];
        } else {
            min_len = MIN(min_len, p1 - p2 + 1);
            sum -= nums[p2++];
        }
    }
    return min_len == INT_MAX ? 0 : min_len;
}

int minSubArrayLen(int s, int* nums, int numsSize) {
    if (!nums || !numsSize) return 0;
    //return solution1(s, nums, numsSize);
    //return solution2(s, nums, numsSize);
    return solution3(s, nums, numsSize);
}

int main() {
    int nums[] = { 1, 1};
    int s = 3;
    int ans = minSubArrayLen(s, nums, sizeof(nums) / sizeof(int));
    printf("%d\n", ans);
    system("pause");
    return 0;
}
