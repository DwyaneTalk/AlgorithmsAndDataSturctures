/*   DwyaneTalk@gmail.co_m
 *   by lutao
 *   leetCodeC++	: Course Schedule II
 *					: https://leetcode.com/problems/course-schedule-ii/
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
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<unordered_set<int>> graph(numCourses);
		vector<int>		inDegree(numCourses, 0);
		vector<int>		ansOrder;
		int i = 0, j = 0;
		for(i = 0; i < prerequisites.size(); ++i) {
			if(graph[prerequisites[i].second].find(prerequisites[i].first) == graph[prerequisites[i].second].end()) {
				graph[prerequisites[i].second].insert(prerequisites[i].first);
				inDegree[prerequisites[i].first] += 1;
			}
		}
		while(j++ < numCourses) {
			i = 0;
			while(i < numCourses && inDegree[i])	++i;
			if(i == numCourses)	break;
			inDegree[i] = -1;
			ansOrder.push_back(i);
			for(unordered_set<int>::iterator itr = graph[i].begin(); itr != graph[i].end(); ++itr) {
				inDegree[*itr] -= 1;
			}
		}
		if(j - 1 < numCourses)	return vector<int>();
		else	return ansOrder;
	}
};