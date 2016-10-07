/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Counting Bits
 *					: https://leetcode.com/problems/counting-bits/
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
	vector<int> countBits(int num) {
		vector<int> ans(num + 1, 0);
		for(int i = 1; i <= num; ++i) {
			if(i & 1)	ans[i] = ans[i >> 1] + 1;
			else		ans[i] = ans[i >> 1];
		}
		return ans;
	}
};