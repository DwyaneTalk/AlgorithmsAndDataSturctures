/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Permutations
 *					: https://leetcode.com/problems/permutations/
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;


class Solution {
public:
	void backTracking(vector<vector<int>>& finalAns, vector<int>& path, vector<int>& nums, vector<int>& visited) {
		if(path.size() == nums.size()) {
			finalAns.push_back(path);
		} else {
			for(int i = 0; i < nums.size(); ++i) {
				if(visited[i] == 0) {
					visited[i] = 1;
					path.push_back(nums[i]);
					backTracking(finalAns, path, nums, visited);
					path.pop_back();
					visited[i] = 0;
				}
			}
		}
	}

	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> finalAns;
		vector<int> path, visited(nums.size(), 0);
		if(nums.empty() == false)	backTracking(finalAns, path, nums, visited);
		return finalAns;
	}

	vector<vector<int>> permute_queue(vector<int>& nums) {
		int numSize = nums.size();
		queue<vector<int>>	pathQueue, visitQueue;
		vector<vector<int>> finalAns;
		vector<int> path, visit;
		if(numSize == 0)	return finalAns;
		pathQueue.push(vector<int>());
		visitQueue.push(vector<int>(numSize, 0));
		while(pathQueue.empty() == false) {
			path	= pathQueue.front();
			visit	= visitQueue.front();
			pathQueue.pop();
			visitQueue.pop();
			if(path.size() == numSize)	{
				finalAns.push_back(path);
				continue;
			}
			for(int i = 0; i < numSize; ++i) {
				if(visit[i] == 0) {
					path.push_back(nums[i]);
					visit[i] = 1;
					pathQueue.push(path);
					visitQueue.push(visit);
					visit[i] = 0;
					path.pop_back();
				}
			}
		}
		return finalAns;
	}
};