/*   DwyaneTalk@gmail.co_m
 *   by lutao
 *   leetCodeC++	: Repeated DNA Sequences
 *					: https://leetcode.com/problems/repeated-dna-sequences/
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
	int compressStatus(string& s, int idx) {
		int status = 0;
		for(int i = 0; i < 10; ++i) {
			switch(s[idx + i]) {
			case 'A':	status |= 0;	break;
			case 'C':	status |= 1;	break;
			case 'G':	status |= 2;	break;
			case 'T':	status |= 3;	break;
			}
			status <<= 2;
		}
		return status;
	}

	string depressStatus(int status) {
		string str;
		for(int i = 0; i < 10; ++i) {
			switch(status & 3) {
			case 0:	str += 'A';	break;
			case 1:	str += 'C';	break;
			case 2:	str += 'G';	break;
			case 3:	str += 'T';	break;
			}
			status >>= 2;
		}
		reverse(str.begin(), str.end());
		return str;
	}

	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> strAns;
		int sSize = s.size();
		unordered_set<int> hashSet;
		unordered_set<int> ansSet;
		for(int i = 0; i + 10 <= sSize; ++i) {
			int status = compressStatus(s, i);
			if(hashSet.find(status) == hashSet.end())	hashSet.insert(status);
			else if(ansSet.find(status) == ansSet.end()){
				strAns.push_back(s.substr(i, 10));
				ansSet.insert(status);
			}
		}
		return strAns;
	}
};