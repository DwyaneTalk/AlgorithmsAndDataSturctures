/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Multiply Strings
 *					: https://leetcode.com/problems/multiply-strings/
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	void addString(string& oriStr, string& addStr) {
		int oriSize = oriStr.size(), addSize = addStr.size(), iOri = 0, iAdd = 0, sum = 0, carry = 0;
		if(oriStr.empty()) {
			oriStr = addStr;
			return;
		}
		while(iAdd < addSize) {
			sum = oriStr[iOri] - '0' + (iAdd < addSize ? addStr[iAdd] - '0' : 0) + carry;
			carry = sum >= 10;
			oriStr[iOri] = sum % 10 + '0';
			++iOri;
			++iAdd;
		}
		if(carry)	{
			while(iOri < oriSize) {
				sum = oriStr[iOri] - '0' + carry;
				carry = sum >= 10;
				oriStr[iOri++] = sum % 10 + '0';
			}
			if(carry) oriStr += '1';
		}
	}

	string multiply(string num1, string num2) {
		int numSize1 = num1.size(), numSize2 = num2.size(), iStart1 = 0, iStart2 = 0, carry = 0, sum = 0;
		if(!num1.compare("0") || !num2.compare("0"))	return "0";
		string ans, ansItem;
		for(int i = 0; i < numSize2; ++i, ans.insert(0, "0")) {
			int val = num2[i] - '0';
			carry = 0;
			ansItem = "";
			for(int j = numSize1 - 1; j >= 0; --j) {
				sum = val * (num1[j] - '0') + carry;
				carry = sum / 10;
				ansItem += sum % 10 + '0';
			}
			if(carry)	ansItem += carry + '0';
			addString(ans, ansItem);
		}
		reverse(ans.begin(), ans.end());
		ans.pop_back();
		return ans;
	}
};