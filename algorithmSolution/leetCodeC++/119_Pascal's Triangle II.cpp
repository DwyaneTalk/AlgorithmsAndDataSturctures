/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Pascal's Triangle II
 *					: https://leetcode.com/problems/pascals-triangle-ii/
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
#include <hash_set>
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> ans;
		for(int i = 0; i <= rowIndex; ++i) {
			int pre_val = 1;
			for (int j = 1; j < i; ++j)	{
				pre_val = ans[j] + pre_val;
				pre_val = ans[j] ^ pre_val;
				ans[j]  = ans[j] ^ pre_val;
				pre_val = ans[j] ^ pre_val;
			}
			ans.push_back(1);
		}
		return ans;
	}
};