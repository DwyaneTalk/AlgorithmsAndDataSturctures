/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Climbing Stairs
 *					: https://leetcode.com/problems/climbing-stairs/
*/
#include <iostream>
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
	int climbStairs(int n) {
		return climbStairs_2(n);
		return climbStairs_1(n);
	}

	int climbStairs_2(int n) {
		if(n < 3)	return n;
		int pre1 = 2, pre2 = 1, ans;
		for(int i = 2; i < n; ++i) {
			ans = pre1 + pre2;
			pre2 = pre1;
			pre1 = ans;
		}
		return ans;
	}
	int climbStairs_1(int n) {
		if(n < 3)	return n;
		vector<int> ans(n, 1);
		ans[1] = 2;
		for(int i = 2; i < n; ++i)	ans[i] = ans[i - 1] + ans[i - 2];
		return ans[n - 1];
	}
};