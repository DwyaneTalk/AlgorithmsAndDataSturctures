/*   DwyaneTalk@gmail.co_m
 *   by lutao
 *   leetCodeC++	: Minimum Height Trees
 *					: https://leetcode.com/problems/minimum-height-trees/
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
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		vector<unordered_set<int>> graph(n);
		vector<int> ansRoot;
		int eSize = edges.size(), aSize = 0;
		if(n != eSize + 1)	return ansRoot;
		if(n == 1)	return vector<int>(1, 0);
		for(int i = 0; i < eSize; ++i) {
			graph[edges[i].first].insert(edges[i].second);
			graph[edges[i].second].insert(edges[i].first);
		}
		for(int i = 0; i < n; ++i) {
			if(graph[i].size() == 1)	ansRoot.push_back(i);
		}
		while (n > 2) {
			aSize = ansRoot.size();
			n -= aSize;
			vector<int> newRoot;
			for(int i = 0; i < aSize; ++i) {
				int k = *graph[ansRoot[i]].begin();
				graph[k].erase(ansRoot[i]);
				if(graph[k].size() == 1)	newRoot.push_back(k);
				graph[ansRoot[i]].clear();
			}
			ansRoot = newRoot;
		}
		return ansRoot;
	}
};