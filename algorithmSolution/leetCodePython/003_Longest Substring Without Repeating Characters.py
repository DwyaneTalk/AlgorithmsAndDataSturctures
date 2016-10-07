'''
DwyaneTalk@gmail.com
https://leetcode.com/problems/two-sum/
'''
class Solution(object):
    def lengthOfLongestSubstring(self, s):
		start = maxLen = 0
		charPos = {}
		for i in range(len(s)):
			if s[i] in charPos and charPos[s[i]] >= start:
				start = charPos[s[i]] + 1
			else:
				maxLen = max(maxLen, i - start + 1)
			charPos[s[i]] = i
		return maxLen