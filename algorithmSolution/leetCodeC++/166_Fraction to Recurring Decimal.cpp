/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Fraction to Recurring Decimal
 *					: https://leetcode.com/problems/fraction-to-recurring-decimal/
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
using namespace std;

class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		if(numerator == 0)	return "0";
		long long lNumerator = abs(long(numerator)), lDenominator = abs(long(denominator));
		string ansStr;
		if((numerator < 0) ^ (denominator < 0))	ansStr += "-";
		ansStr += to_string(lNumerator / lDenominator);
		lNumerator = lNumerator % lDenominator;
		if(lNumerator)	ansStr += ".";
		map<int, int> hashMap;
		int idx = ansStr.size();
		while(lNumerator) {
			if(hashMap[lNumerator]) {
				ansStr += ")";
				ansStr.insert(hashMap[lNumerator], "(");
				break;
			} else {
				hashMap[lNumerator] = idx++;
				ansStr += to_string(10 * lNumerator / lDenominator);
				lNumerator = (lNumerator * 10) % lDenominator;
			}
		}
		return ansStr;
	}
};