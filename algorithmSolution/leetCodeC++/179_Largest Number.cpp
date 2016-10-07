/*   DwyaneTalk@gmail.co_m
 *   by lutao
 *   leetCodeC++	: Largest Number
 *					: https://leetcode.com/problems/largest-number/
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
#include <time.h>
using namespace std;

class Solution {
public:
	static int compare(const void* a, const void* b) {
		int iA = *(int*)a, iB = *(int*)b;
		string strA = to_string((long long)(*(int*)a));
		string strB = to_string((long long)(*(int*)b));
		string strAB = strA + strB;
		string strBA = strB + strA;
		int size = strAB.size();
		for(int i = 0; i < size; ++i) {
			if(strAB[i] > strBA[i])		return -1;
			else if(strAB[i] < strBA[i]) return 1;
		}
		return 0;
	}

	string largestNumber(vector<int>& nums) {
		string ansStr;
		int numSize = nums.size();
		if(numSize > 0) {
			qsort((void*)&nums[0], numSize, sizeof(int), compare);
			int i = 0;
			while(nums[i] == 0 && i < numSize - 1) ++i;
			for(; i < numSize; ++i)	ansStr += to_string((long long)nums[i]);
		}
		return ansStr;
	}
};