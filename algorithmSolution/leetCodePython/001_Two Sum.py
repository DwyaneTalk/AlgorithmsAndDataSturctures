'''
DwyaneTalk@gmail.com
https://leetcode.com/problems/two-sum/
'''
class Solution(object):
	def twoSum(self, nums, target):
		dict = {}
		for idx, num in enumerate(nums):
			if num in dict:
				return [dict[num], idx]
			else:
				dict[target - num] = idx


nums = [3, 2, 4]
target = 6
solution = Solution()
print(solution.twoSum(nums, target))