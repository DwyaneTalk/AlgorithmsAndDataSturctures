/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Letter Combinations of a Phone Number 
 *					: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		int sSize = digits.size();
		vector<string> finalAns;
		string table[10] = {"", "",	"abc", "def" , "ghi", "jkl","mno", "pqrs", "tuv", "wxyz"};
		if(sSize <= 0)	return finalAns;
		finalAns.push_back("");
		for(int i = 0; i < sSize; ++i) {
			int ch = digits[i] - '0';
			if(ch < 0 || ch > 9)	continue;
			int tSize = table[ch].size(), fSize = finalAns.size();
			vector<string> tmpAns;
;			for(int j = 0; j < fSize; ++j) {
				for(int k = 0; k < tSize; ++k) {
					tmpAns.push_back(finalAns[j] + table[ch][k]);
				}
			}
			finalAns.swap(tmpAns);
		}
		return finalAns;
	}
};