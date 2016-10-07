'''
DwyaneTalk@gmail.com
https://leetcode.com/problems/two-sum/
'''
class Solution(object):
    def reverse(self, x):
		flags = 1
		if x < 0:
			flags = -1
			x = -x
		ans = 0
		while x :
			ans = ans * 10 + x % 10
			x = x / 10
		if (flags > 0 and ans > (1 << 32) - 1) or (flags < 0 and ans > (1 << 32)):
			return 0
		return  ans * flags