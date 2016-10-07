/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Permutation Sequence
 *					: https://leetcode.com/problems/permutation-sequence/
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;


class Solution {
public:
	string getPermutation(int n, int k) {
		vector<int> factNum(n, 1), visit(n ,0);
		string ans = "";
		for(int i = 1; i < n; ++i)	factNum[i] = i * factNum[i - 1];
		k = k - 1;
		for(int i = n - 1; i >= 0; --i) {
			int val1 = k / factNum[i] + 1, val2 = 0, val3 = 0;
			k = k % factNum[i];
			for(; val2 < n; ++val2) {
				if(visit[val2] == 0)	++val3;
				if(val3 == val1)	break;
			}
			ans += '0' + val2 + 1;
			visit[val2] = 1;
		}
		return ans;
	}
};