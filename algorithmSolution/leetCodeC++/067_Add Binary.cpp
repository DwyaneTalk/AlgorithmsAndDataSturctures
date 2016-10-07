/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Add Binary
 *					: https://leetcode.com/problems/add-binary/
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		int aSize = a.size(), bSize = b.size(), ia = aSize - 1, ib = bSize - 1, carry = 0, sum = 0, sa = 0, sb = 0;
		string ans;
		while(sa < aSize && a[sa] == '0')	++sa;
		while(sb < bSize && b[sb] == '0')	++sb;
		while(ia >= sa || ib >= sb) {
			sum = (ia >= sa ? a[ia] : '0') + (ib >= sb ? b[ib] : '0') + carry;
			carry = sum > 97; // '0' + '0' + 1
			ans += sum % 2 + '0';
			--ia;
			--ib;
		}
		if(carry)	ans += "1";
		if(ans.empty())	ans = "0";
		reverse(ans.begin(), ans.end());
		return ans;
	}
};
