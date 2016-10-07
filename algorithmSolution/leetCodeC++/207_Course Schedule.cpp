/*   DwyaneTalk@gmail.co_m
 *   by lutao
 *   leetCodeC++	: Course Schedule
 *					: https://leetcode.com/problems/course-schedule/
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
	bool canFinish_bfs(vector<unordered_set<int>>& graph) {
		int numCourses = graph.size(), i = 0, j = 0;
		vector<int>		inDegree(numCourses, 0);
		for(i = 0; i < numCourses; ++i) {
			for(unordered_set<int>::iterator itr = graph[i].begin(); itr != graph[i].end(); ++itr) {
				inDegree[*itr] += 1;
			}
		}
		while(j++ < numCourses) {
			i = 0;
			while(i < numCourses && inDegree[i])	++i;
			if(i == numCourses)	return false;
			inDegree[i] = -1;
			for(unordered_set<int>::iterator itr = graph[i].begin(); itr != graph[i].end(); ++itr) {
				inDegree[*itr] -= 1;
			}
		}
		return true;
	}

	bool hasCircle(vector<unordered_set<int>>& graph, vector<bool>& visited, vector<bool>& onpath, int curr) {
		visited[curr] = onpath[curr] = true;
		for(unordered_set<int>::iterator itr = graph[curr].begin(); itr != graph[curr].end(); ++itr) {
			if(onpath[*itr])	return true;
			if(!visited[*itr] && hasCircle(graph, visited, onpath, *itr))	return true;
		}
		onpath[curr] = false;
		return false;
	}

	bool canFinish_dfs(vector<unordered_set<int>>& graph) {
		int numCourses = graph.size(), i = 0, j = 0;
		vector<bool>	visited(numCourses, false);
		for(int i = 0; i < numCourses; ++i) {
			vector<bool>	onpath(numCourses, false);
			if(!visited[i] && hasCircle(graph, visited, onpath, i))	return false;
		}
		return true;
	}

	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		if(numCourses <= 0)	return false;
		vector<unordered_set<int>> graph(numCourses);
		for(int i = 0; i < prerequisites.size(); ++i) {
			graph[prerequisites[i].second].insert(prerequisites[i].first);
		}
		//return canFinish_bfs(graph);
		return canFinish_dfs(graph);
	}
};