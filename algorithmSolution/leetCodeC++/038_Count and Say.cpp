/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Count and Say
 *					: https://leetcode.com/problems/count-and-say/
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
	string countAndSay(int n) {
		vector<int> intAns(1, 1);
		for(int i = 2; i <= n; ++i) {
			int size = intAns.size(), idx = 0, j = 1;
			vector<int> tmpAns;
			for(j = 1; j < size; ++j) {
				if(intAns[j] != intAns[j - 1]) {
					tmpAns.push_back(j - idx);
					tmpAns.push_back(intAns[idx]);
					idx = j;
				}
			}
			tmpAns.push_back(j - idx);
			tmpAns.push_back(intAns[idx]);
			intAns.swap(tmpAns);
		}
		string strAns = "";
		for(int i = 0; i < intAns.size(); ++i)	strAns += (intAns[i] + '0');
		return strAns;
	}
};