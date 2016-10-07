/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Find Minimum in Rotated Sorted Array
 *					: https://leetcode.com/problems/clone-graph/
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
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
private:
	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>	nodeMap;

public:
	UndirectedGraphNode *cloneGraph_DFS(UndirectedGraphNode *node) {
		if(!node)	return NULL;
		UndirectedGraphNode *mapedNode = NULL;
		if(mapedNode = nodeMap[node])	return mapedNode;
		UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
		nodeMap[node] = newNode;
		int size = node->neighbors.size();
		for(int i = 0; i < size; ++i) {
			newNode->neighbors.push_back(cloneGraph_DFS(node->neighbors[i]));
		}
		return newNode;
	}
	UndirectedGraphNode *cloneGraph_BFS(UndirectedGraphNode *node) {
		UndirectedGraphNode* clonedGraph = NULL;
		queue<UndirectedGraphNode*> nodeQueue;
		if(node) {
			clonedGraph = new UndirectedGraphNode(node->label);
			nodeQueue.push(node);
			nodeMap[node] = clonedGraph;
		}
		while(!nodeQueue.empty()) {
			UndirectedGraphNode *currNode = nodeQueue.front(), *clonedNode = nodeMap[currNode], *neighborNode;
			nodeQueue.pop();
			int nSize = currNode->neighbors.size();
			for(int i = 0; i < nSize; ++i) {
				if(neighborNode = nodeMap[currNode->neighbors[i]]) {
					clonedNode->neighbors.push_back(neighborNode);
				} else {
					UndirectedGraphNode* newClonedNode = new UndirectedGraphNode(currNode->neighbors[i]->label);
					clonedNode->neighbors.push_back(newClonedNode);
					nodeMap[currNode->neighbors[i]] = newClonedNode;
					nodeQueue.push(currNode->neighbors[i]);
				}
			}
		}
		return clonedGraph;
	}
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		nodeMap.clear();
		return cloneGraph_BFS(node);
		return cloneGraph_DFS(node);
	}
};
