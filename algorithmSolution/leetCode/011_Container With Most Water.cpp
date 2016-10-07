/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : Container With Most Water
 *             : https://leetcode.com/problems/container-with-most-water/
*/

#include <stdio.h>


struct IntArray {
    int* elements;
    int size;
};

#define MIN(x, y) (x > y ? y : x)
int maxArea(struct IntArray* height) {
    //  通过双指针(O(n))
    int *elem = height->elements;
    int size = height->size;
    int left = 0, right = size - 1;
    int max_area= 0,cur_area, cur_h;
    while(left < right) {
        cur_h = MIN(elem[left], elem[right]);
        cur_area  =cur_h * (right - left);
        if (cur_area > max_area) max_area = cur_area;
        if(elem[left] < elem[right])    left++;
        else    right--;
    }
    return max_area;
    //  暴力搜索O(n^2)，会超时
//    int max_area = 0, area;
//    int *elem = height->elements;
//    int size = height->size;
//    int i, j, h;
//    for (i = 1; i < size; i++) {
//        for (j = 0; j < i; j++) {
//            h = MIN(elem[i], elem[j]);
//            area = h * (i - j);
//            if(area > max_area)
//                max_area = area;
//        }
//    }
//    return max_area;
}

int main() {
    int arr[] = {1, 2, 4, 3};
    IntArray Arr;
    Arr.elements = arr;
    Arr.size = sizeof(arr) / sizeof(int);
    int ans = maxArea(&Arr);
    printf("%d\n", ans);
    return 0;
}
