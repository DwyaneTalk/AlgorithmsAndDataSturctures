/*   DwyaneTalk@gmail.co_m
 *   by lutao
 *   leetCodeC++	: Rectangle Area
 *					: https://leetcode.com/problems/rectangle-area/
*/
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <time.h>
using namespace std;

class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int width = 0, height = 0, left = 0, right = 0;
		if(A >= G || C <= E) {
			width = 0;
		} else {
			width = min(G, C) - max(A, E);
		}
		if(F >= D || H <= B) {
			height = 0;
		} else {
			height = min(D, H) - max(B, F);
		}
		return (D - B) * (C - A) + (H - F) * (G - E) - width * height;
	}
};