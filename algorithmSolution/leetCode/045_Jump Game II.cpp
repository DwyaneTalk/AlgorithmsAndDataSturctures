/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Jump Game II
 *             : https://leetcode.com/problems/jump-game-ii/
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
// greedy(Time Limit Exceed¡­¡­)
int solution1(int *nums, int numsSize) {
    int i, t = numsSize - 1, ans = 0;
    while(t) {
        i = 0;
        while(nums[i] + i < t)  ++i;//Ñ°ÕÒÌ°ÐÄµãÌ«ºÄÊ±¡­¡­
        ++ans;
        t = i;
    }
    return ans;
}

// BFS(refer:https://leetcode.com/discuss/10588/o-n-bfs-solution)
int solution2(int *nums, int numsSize) {
    int level = 0, curr_max = 0, next_max = 0, i = 0;
    if(numsSize < 2)    return 0;
    while(curr_max - i + 1 > 0) { // exist elem in curren
        for(; i <= curr_max; ++i) {
            next_max = MAX(next_max, nums[i] + i);
            if(next_max >= numsSize - 1)   return (level + 1);
        }
        curr_max = next_max;
        level++;
    }
    return INT_MAX;
}

// greedy(refer:https://leetcode.com/discuss/30647/single-loop-simple-java-solution)
int solution3(int *nums, int numsSize) {
    int i, step = 0, curr_max = 0, curr_end = 0;
    for(i = 0; i < numsSize - 1; ++i) {
        curr_max = MAX(curr_max, nums[i] + i);
        if(i == curr_end) {
            curr_end = curr_max;
            ++step;
        } else if(i > curr_end) {
            return INT_MAX;
        }
    }
    return step;
}

int jump(int* nums, int numsSize) {
    return solution3(nums, numsSize);
//    return solution2(nums, numsSize);
}

int main() {
    int nums[] = {0};
    int ans = jump(nums, sizeof(nums) / sizeof(int));
    printf("%d\n", ans);
    return 0;
}
