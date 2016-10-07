/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Pow(x, n)
 *					: https://leetcode.com/problems/powx-n/
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <hash_set>
using namespace std;

class Solution {
public:
	double dfsPow(double x, int n) {
		if(n == 0)	return 1.0f;
		else if(n == 1)	return x;
		else {
			double tmpVal = myPow(x, n / 2);
			tmpVal = tmpVal * tmpVal;
			return (n % 2) ? (tmpVal * x) : tmpVal; 
		}
	}
	double myPow(double x, int n) {
		if(n == INT_MIN) {
			return 1 / (dfsPow(x, INT_MAX) * x);
		} else if(n < 0) {
			return 1 / dfsPow(x, -n);
		} else {
			return dfsPow(x, n);
		}
	}
};