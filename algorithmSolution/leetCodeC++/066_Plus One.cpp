/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Plus One
 *					: https://leetcode.com/problems/plus-one/
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int numSize = digits.size(), iStart = 0, carry = 1;
		vector<int> ans;
		while(iStart < numSize && digits[iStart] == 0)	++iStart;
		for(int i = numSize - 1; i >= iStart; --i) {
			int sum = digits[i] + carry;
			carry = sum >= 10;
			ans.push_back(sum % 10);
		}
		if(carry)	ans.push_back(1);
		reverse(ans.begin(), ans.end());
		return ans;
	}
};
