/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Rotate Image
 *					: https://leetcode.com/problems/rotate-image/
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
	void rotate(vector<vector<int>>& matrix) {
		int size = matrix.size();
		for(int i = 0; i < size - 1; ++i){
			for(int j = i + 1; j < size; ++j) {
				matrix[i][j] = matrix[i][j] ^ matrix[j][i];
				matrix[j][i] = matrix[i][j] ^ matrix[j][i];
				matrix[i][j] = matrix[i][j] ^ matrix[j][i];
			}
		}
		for(int i = 0; i < size; ++i) {
			for(int j = 0; j < size / 2; ++j) {
				matrix[i][j] = matrix[i][j] ^ matrix[i][size - 1 - j];
				matrix[i][size - 1 - j] = matrix[i][j] ^ matrix[i][size - 1 - j];
				matrix[i][j] = matrix[i][j] ^ matrix[i][size - 1 - j];
			}
		}
	}
};