/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Gas Station
 *					: https://leetcode.com/problems/gas-station/
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
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int curSum = 0, minSum = INT_MAX, minSumIdx = -1, size = gas.size();
		for(int i = 0; i < size; ++i) {
			curSum += (gas[i] - cost[i]);
			if(curSum < minSum) {
				minSum = curSum;
				minSumIdx = i;
			}
		}
		return curSum < 0 ? -1 : minSumIdx;
	}
};