/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Largest Rectangle in Histogram
*             : https://leetcode.com/problems/largest-rectangle-in-histogram/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int getMinIndex(int *height, int size) {
    int ans = 0, min = height[0], lo = 1;
    while (lo < size) {
        if (height[lo] < min) {
            ans = lo;
            min = height[lo];
        }
        ++lo;
    }
    return ans;
}

// 分治，当所有元素都相等时，复杂度会比较大，产生超时……
// 复杂度：若getMinIndex采用O(n)，则整体复杂度为O(n^2)；
//         若getMinIndex通过degment tree实现O(logn)，则整体复杂度为O(nlogn)
int solution1(int *height, int heightSize) {
    if (heightSize < 1) return 0;
    int minIndex = getMinIndex(height, heightSize);
    int ans1 = heightSize * height[minIndex];
    int ans2 = solution1(height, minIndex);
    int ans3 = solution1(height + minIndex + 1, heightSize - minIndex - 1);
    return MAX(MAX(ans1, ans2), ans3);

}

// 使用stack, ref::http://www.geeksforgeeks.org/largest-rectangle-under-histogram/
typedef struct {
    int *elem;
    int top;
    int size;
} Stack;

void initStack(Stack *stack, int size) {
    if (stack->elem = (int *)malloc(sizeof(int)* size)) {
        stack->size = size;
        stack->top = 0;
    }
}

int solution2(int *height, int heightSize) {
    int ans = 0, i = 0, top = 0, pre, val;
    Stack stack;
    initStack(&stack, heightSize + 1);
    stack.elem[stack.top++] = -1;
    while (i < heightSize) {
        if (stack.top <= 1 || height[i] >= height[top]) {
            stack.elem[stack.top++] = i;
            top = i++;
        } else {
            stack.top--;
            pre = stack.elem[stack.top - 1];
            val = height[top] * (i - pre - 1);
            if (ans < val)  ans = val;
            top = pre;
        }
    }
    while (stack.top > 1) {
        top = stack.elem[--stack.top];
        pre = stack.elem[stack.top - 1];
        val = height[top] * (heightSize - pre - 1);
        if (ans < val)  ans = val;
    }
    return ans;
}

int largestRectangleArea(int* height, int heightSize) {
    // return solution1(height, heightSize);
    return solution2(height, heightSize);
}

int main() {
    int height[] = {4, 7, 6, 8, 5, 9, 1, 25};
    int heightSize = sizeof(height) / sizeof(int);
    int ans = largestRectangleArea(height, heightSize);
    printf("%d\n", ans);
    system("pause");
    return 0;
}
