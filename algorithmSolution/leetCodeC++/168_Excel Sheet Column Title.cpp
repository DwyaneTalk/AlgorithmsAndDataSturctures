/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Excel Sheet Column Title
 *					: https://leetcode.com/problems/excel-sheet-column-title/
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
	string convertToTitle(int n) {
		string ansStr;
		while(n > 0) {
			ansStr += ('A' + (n - 1) % 26);
			n = (n - 1) / 26;
		}
		reverse(ansStr.begin(), ansStr.end());
		return ansStr;
	}
};