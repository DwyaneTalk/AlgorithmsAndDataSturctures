/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Gray Code
 *					: https://leetcode.com/problems/gray-code/
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
	vector<int> grayCode(int n) {
		vector<int> ans;
		ans.push_back(0);
		for(int i = 0; i < n; ++i) {
			int ansSize = ans.size();
			for(int j = ansSize - 1; j >= 0; --j){
				ans.push_back(ans[j] | (1 << i));
			}
		}
		return ans;
	}
};