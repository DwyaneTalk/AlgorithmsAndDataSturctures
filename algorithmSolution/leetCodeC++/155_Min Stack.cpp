/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Min Stack
 *					: https://leetcode.com/problems/min-stack/
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

class MinStack {
private:
	stack<long> myStack;
	long minVal;
public:
	/** initialize your data structure here. */
	MinStack() {
	}

	void push(int x) {
		if(myStack.empty()) {
			minVal = x;
			myStack.push(x - minVal);
		} else {
			myStack.push(x - minVal);
			if(x < minVal)	minVal = x;
		}
	}

	void pop() {
		long topVal = myStack.top();
		myStack.pop();
		if(topVal < 0)	minVal = minVal - topVal;
	}

	int top() {
		long topVal = myStack.top();
		if(topVal > 0)	return int(topVal + minVal);
		else			return int(minVal);
	}

	int getMin() {
		return int(minVal);
	}
};