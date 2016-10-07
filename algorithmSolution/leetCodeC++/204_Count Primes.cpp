/*   DwyaneTalk@gmail.co_m
 *   by lutao
 *   leetCodeC++	: Count Primes
 *					: https://leetcode.com/problems/count-primes/
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
	bool isPrime(int n) {
		for(int i = 2; i * i <= n; ++i) {
			if(n % i == 0)	return false;
		}
		return true;
	}
	int countPrimes(int n) {
		int ansCount = 0;
		if(0) {	//Time Limit Exceeded when n larger than 1500000
			for(int i = 2; i < n; ++i)	if(isPrime(i))	++ansCount;
		} else {
			vector<bool> fPrime(n, true);
			for(int i = 2; i * i < n; ++i) {
				if(fPrime[i] == false)	continue;
				for(int j = i << 1; j < n; j += i)	fPrime[j] = false;
			}
			for(int i = 2; i < n; ++i)	if(fPrime[i])	++ansCount;
		}
		return ansCount;
	}
};