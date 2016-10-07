/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Palindrome Number
 *					: https://leetcode.com/problems/palindrome-number/
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if(x < 0)	return false;
		int xx = 0, tx = x;
		while(tx) {
			int newxx = xx * 10 + (tx % 10);
			if(newxx / 10 != xx)	return false;
			xx = newxx;
			tx /= 10;
		}
		return x == xx;
	}
};