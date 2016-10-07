'''
DwyaneTalk@gmail.com
https://leetcode.com/problems/two-sum/
'''
class Solution(object):
	def __init__(self):
		self.lo = 0
		self.maxlen = 0
	def longestPalindrome(self, s):
		ans = ""
		for i in range(len(s)):
			self.helper(s, i, i)
			self.helper(s, i, i + 1)
		return s[self.lo : self.lo + self.maxlen]

	def helper(self, s, lo, hi):
		sLen = len(s)
		while lo >=0 and hi < sLen and s[lo] == s[hi]:
			lo = lo - 1
			hi = hi + 1
		if hi - lo - 1 > self.maxlen:
			self.maxlen = hi - lo - 1
			self.lo = lo + 1

solution = Solution()
print(solution.longestPalindrome("bb"))