'''
DwyaneTalk@gmail.com
https://leetcode.com/problems/3sum/
'''
class Solution(object):
	def threeSum(self, nums):
		nums = sorted(nums)
		size = len(nums)
		ans = []
		for idx, num in enumerate(nums):
			lo = idx + 1
			hi = size - 1
			while lo < hi:
				if(nums[lo] + nums[hi] + num == 0):
					one = [num, nums[lo], nums[hi]]
					if one not in ans:
						ans.append(one)
					lo = lo + 1
					hi = hi - 1
				elif(nums[lo] + nums[hi] + num < 0):
					lo = lo + 1
				else:
					hi = hi - 1
		return ans

nums = [-1, 0, 1, 2, -1, -4]
solution  = Solution()
print(solution.threeSum(nums))