/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Word Ladder
 *					: https://leetcode.com/problems/word-ladder/
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
#include <hash_set>
#include <unordered_set>
using namespace std;

class Solution {
public:

	void candidateWord(string& currWord, unordered_set<string>& wordList, queue<string>& wordQueue) {
		int wordSize = currWord.size();
		for(int i = 0; i < wordSize; ++i) {
			char wordCh = currWord[i];
			for(char ch = 'a'; ch <= 'z'; ++ch) {
				currWord[i] = ch;
				if(wordList.find(currWord) != wordList.end()) {
					wordList.erase(currWord);
					wordQueue.push(currWord);
				}
			}
			currWord[i] = wordCh;
		}
	}

	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
		queue<string>	wordQueue;
		int ans = 1;
		wordList.insert(endWord);
		wordList.erase(beginWord);
		candidateWord(beginWord, wordList, wordQueue);
		while(!wordQueue.empty()) {
			int queueCnt = wordQueue.size();
			++ans;
			while(queueCnt-- > 0) {
				string currWord = wordQueue.front();
				wordQueue.pop();
				if(currWord == endWord)	return ans;
				candidateWord(currWord, wordList, wordQueue);
			}
		}
		return 0;
	}
};