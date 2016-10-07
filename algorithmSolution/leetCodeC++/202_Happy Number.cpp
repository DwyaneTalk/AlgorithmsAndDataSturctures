/*   DwyaneTalk@gmail.co_m
 *   by lutao
 *   leetCodeC++	: Happy Number
 *					: https://leetcode.com/problems/happy-number/
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
	int newNumber(int n) {
		int sum = 0;
		while(n) {
			sum += (n % 10) * (n % 10);
			n = n / 10;
		}
		return sum;
	}

	bool isHappy(int n) {
		unordered_set<int> hashMap;
		while(hashMap.find(n) == hashMap.end() && n != 1) {
			hashMap.insert(n);
			n = newNumber(n);
		}
		return n == 1;
	}
};