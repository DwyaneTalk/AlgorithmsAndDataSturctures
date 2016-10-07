/*   DwyaneTalk@gmail.co_m
 *   by lutao
 *   leetCodeC++	: Add Digits
 *					: https://leetcode.com/problems/add-digits/
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
	int addDigits(int num) {
		return num ? (num - 1) % 9 + 1 : 0;
	}
};