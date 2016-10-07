/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Sum of Two Integers
 *					: https://leetcode.com/problems/sum-of-two-integers/
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
	int getSum(int a, int b) {
		int carry = 0, sum = 0, ansSum = 0, bit = 0;
		while(bit < 32) {
			sum = (a & 1) ^ (b & 1) ^ carry;
			carry = (((a & 1) && (b & 1)) ||  (((a & 1) || (b & 1)) && carry));
			a = a >> 1;
			b = b >> 1;
			ansSum = ansSum | (sum << bit++);
		}
		return ansSum;
	}
	int getSum2(int a, int b) {
		return b == 0 ? a : getSum2(a ^ b, (a & b) << 1);
	}
};