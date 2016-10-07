/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : 3Sum Closest
 *             : https://leetcode.com/problems/3sum-closest/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define POSITIVE(x) (((x) > 0) ? (x) : (-(x)))
#define NEGATIVE(x) (((x) < 0) ? (x) : (-(x)))

int compare(const void *p1, const void *p2) {
    return *(int *)p1 - *(int *)p2;
}

int threeSumClosest(int *num, int n, int target) {
    int min_diff = INT_MAX / 2, lo_diff, hi_diff, twoSum, ans;
    int i, lo, hi;
    qsort((void *)num, n, sizeof(int), compare);
    for(i = 0; i < n; i++)
        printf("%d\t", num[i]);
    printf("\n");
    for(i = 0; i < n - 2; i++) {
        lo = i + 1;
        hi = n - 1;
        lo_diff = NEGATIVE(min_diff) - num[i] + target;
        hi_diff = POSITIVE(min_diff) - num[i] + target;
        while(lo < hi) {
            twoSum = num[lo] + num[hi];
            if(twoSum >= hi_diff)
                hi--;
            else if(twoSum <= lo_diff)
                lo++;
            else{
                ans = twoSum + num[i];
                min_diff = POSITIVE(ans - target);
                //while(lo < hi && num[lo] == num[lo + 1])    lo++;
                //while(lo < hi && num[hi] == num[hi - 1])    hi--;
                lo_diff = NEGATIVE(min_diff) - num[i] + target;
                hi_diff = POSITIVE(min_diff) - num[i] + target;
            }
        }
    }
    return ans;
}

int main() {
    int arrIn[] = {13,2,0,-14,-20,19,8,-5,-13,-3,20,15,
    20,5,13,14,-17,-7,12,-6,0,20,-19,-1,-15,-2,8,-2,-9,13,0,-3,-18,
    -9,-9,-19,17,-14,-19,-4,-16,2,0,9,5,-7,-4,20,18,9,0,12,-1,10,-17,
    -11,16,-13,-14,-3,0,2,-18,2,8,20,-15,3,-13,-12,-2,-19,11,11,-10,
    1,1,-10,-2,12,0,17,-19,-7,8,-19,-17,5,-5,-10,8,0,-12,4,19,2,0,12
    ,14,-9,15,7,0,-16,-5,16,-12,0,2,-16,14,18,12,13,5,0,5,6};
    int ans = threeSumClosest(arrIn, sizeof(arrIn) / sizeof(int), -59);
    printf("%d\n", ans);
    return 0;
}
