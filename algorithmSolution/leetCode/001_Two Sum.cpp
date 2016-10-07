/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCode : Two Sum
 *            : https://leetcode.com/problems/two-sum/
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compare(const void *p1, const void *p2){
    return *(int *)p1 - *(int *)p2;
}

int bi_search(int numbers[], int b_n, int e_n, int val) {
    if (b_n > e_n)
        return 0;
    int mid = (b_n + e_n) / 2;
    if (numbers[mid] == val) {
        return 1;
    }
    // 这里二分查找明显不是最优，因为numbers已经排好序，所以下面只需要查找一侧即可
    if (bi_search(numbers, b_n, mid-1, val) || bi_search(numbers, mid+1, e_n, val)) {
        return 1;
    }
    return 0;
}

int *twoSum(int numbers[], int n, int target) {
    int i = 0, j = n -1, k, sub_val;
    int ans[2];
    int *tmp = (int *)malloc(n * sizeof(int));
    memcpy(tmp, numbers, n * sizeof(int));
    qsort((void *)numbers, n, sizeof(int), compare);
    if(false) {
        //通过二分查找确定
        for (i = 0; i < n; ++i) {
            sub_val = target - numbers[i];
            if (bi_search(numbers, i+1, n-1, sub_val)) {
                break;
            }
        }
    } else {
        //通过两端遍历查找确定
        while(i < j) {
            if(numbers[i] + numbers[j] == target) {
                sub_val = numbers[j];
                break;
            } else if(numbers[i] + numbers[j] < target) {
                i++;
            } else {
                j--;
            }
        }
    }
    for (j = 0; j < n; ++j) {
        if(tmp[j] == numbers[i] || tmp[j] == sub_val) {
            ans[0] = j+1;
            break;
        }
    }
    for (j++; j < n; ++j) {
        if(tmp[j] == numbers[i] || tmp[j] == sub_val) {
            ans[1] = j+1;
            break;
        }
    }
    return ans;
}

int main() {
    int n = 4;
    int target = 9;
    int numbers[4] = {2, 7, 11, 15};
    int *ans = twoSum(numbers, n, target);
    printf("index1=%d, index2=%d", ans[0], ans[1]);
    return 0;
}

