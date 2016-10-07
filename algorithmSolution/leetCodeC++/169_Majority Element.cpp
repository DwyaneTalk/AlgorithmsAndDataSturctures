/*   DwyaneTalk@gmail.co_m
 *   by lutao
 *   leetCodeC++	: Majority Element
 *					: https://leetcode.com/problems/majority-element/
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
	int majorityElement_sort(vector<int>& nums) {
		int numSize = nums.size();
		nth_element(nums.begin(), nums.begin() + numSize / 2, nums.end());
		return nums[numSize / 2];
	}

	int majorityElement_bucket(vector<int>& nums) {
		unordered_map<int, int> mapCounter;
		int ansNum = 0, numSize = nums.size();
		for(int i = 0; i < numSize; ++i) {
			if(++mapCounter[nums[i]] > numSize / 2){
				ansNum = nums[i];
				break;
			}
		}
		return ansNum;
	}

	int majorityElement_random(vector<int>& nums) {
		int numSize = nums.size(), ans;
		srand(unsigned(time(0)));
		while(true) {
			int candidate = nums[rand() % numSize], counter = 0;
			for(int i = 0; i < numSize; ++i) {
				if(nums[i] == candidate)	counter++;
			}
			if(counter > numSize / 2){
				ans = candidate;
				break;
			}
		}
		return ans;
	}

	int majorityElement_voting(vector<int>& nums) {
		int counter = 0, ans = 0, numSize = nums.size();
		for(int i = 0; i < numSize; ++i) {
			if(counter == 0) {
				ans = nums[i];
				counter = 1;
			} else {
				counter += (nums[i] == ans ? 1 : -1);
			}
		}
		return ans;
	}

	int majorityElement_bitMan(vector<int>& nums) {
		int numSize = nums.size(), ans = 0;
		for(int mask = 1; mask != 0; mask <<= 1) {
			int counter = 0;
			for(int i = 0; i < numSize; ++i) {
				int a = nums[i] & mask;
				if(nums[i] & mask)	++counter;
				if(counter > numSize / 2) {
					ans |= mask;
					break;
				}
			}
		}
		return ans;
	}

	int majorityElement_divide(vector<int>& nums, int lo, int hi) {
		if(lo == hi)	return nums[lo];
		int mid = lo + ((hi - lo) >> 1);
		int lMaj = majorityElement_divide(nums, lo, mid);
		int rMaj = majorityElement_divide(nums, mid + 1, hi);
		if(lMaj == rMaj)	return lMaj;
		return count(nums.begin() + lo, nums.begin() + hi + 1, lMaj)  > count(nums.begin() + lo, nums.begin() + hi + 1, rMaj) ? lMaj : rMaj;
	}

	int majorityElement(vector<int>& nums) {
		//return majorityElement_sort(nums);	
		//return majorityElement_bucket(nums);
		//return majorityElement_random(nums);
		//return majorityElement_voting(nums);
		return majorityElement_bitMan(nums);
		return majorityElement_divide(nums, 0, nums.size() - 1);
	}
};