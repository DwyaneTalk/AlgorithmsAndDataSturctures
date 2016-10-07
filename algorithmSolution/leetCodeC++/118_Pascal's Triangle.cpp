/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Pascal's Triangle
 *					: https://leetcode.com/problems/pascals-triangle/
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
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ans;
		vector<int>			line;
		int pre_val = 0;
		for(int i = 0; i < numRows; ++i) {
			pre_val = 1;
			for(int j = 1; j < i; ++j) {
				pre_val = pre_val + line[j];
				pre_val = pre_val ^ line[j];
				line[j] = pre_val ^ line[j];
				pre_val = pre_val ^ line[j];
			}
			line.push_back(1);
			ans.push_back(line);
		}
		return ans;
	}
};