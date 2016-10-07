/*   DwyaneTalk@gmail.co_m
 *   by lutao
 *   leetCodeC++	: Ugly Number
 *					: https://leetcode.com/problems/ugly-number/
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
	bool isUgly(int num) {
		if(num < 1)	return false;
		while(num % 2 == 0)	num /= 2;
		while(num % 3 == 0)	num /= 3;
		while(num % 5 == 0)	num /= 5;
		return num == 1;
	}
};