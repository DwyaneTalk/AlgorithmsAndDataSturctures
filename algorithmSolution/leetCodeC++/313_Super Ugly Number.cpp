/*   DwyaneTalk@gmail.co_m
 *   by lutao
 *   leetCodeC++	: Super Ugly Number
 *					: https://leetcode.com/problems/super-ugly-number/
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
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		int nPrime = primes.size();
		vector<int> table(n, 0);
		vector<int> idx(nPrime, 0);
		table[0] = 1;
		for(int i = 1; i < n; ++i) {
			int minVal = INT_MAX, tmpVal;
			for(int j = 0; j < nPrime; ++j) {
				tmpVal = table[idx[j]] * primes[j];
				if(tmpVal > 0 && tmpVal < minVal)	minVal = tmpVal;
			}
			table[i] = minVal;
			for(int j = 0; j < nPrime; ++j) {
				if(table[idx[j]] * primes[j] == table[i])	++idx[j];
			}
		}
		return table[n - 1];
	}
};