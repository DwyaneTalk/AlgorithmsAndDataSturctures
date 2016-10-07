/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Candy
 *					: https://leetcode.com/problems/candy/
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
#include <hash_map>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int candy(vector<int>& ratings) {
		int childNums = ratings.size();
		if(childNums < 2)	return childNums;
		vector<int> candyNums(childNums, 1);
		int sumCandy = 0;
		for(int i = 1; i < childNums; ++i) {
			if(ratings[i] > ratings[i - 1])	candyNums[i] = candyNums[i - 1] + 1;
		}
		for(int i = childNums - 1; i > 0; --i) {
			if(ratings[i - 1] > ratings[i])	candyNums[i - 1] = max(candyNums[i - 1], candyNums[i] + 1);
			sumCandy += candyNums[i - 1];
		}
		return sumCandy + candyNums[childNums - 1];
	}
};