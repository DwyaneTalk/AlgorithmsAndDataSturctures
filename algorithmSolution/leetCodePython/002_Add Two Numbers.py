'''
DwyaneTalk@gmail.com
https://leetcode.com/problems/add-two-numbers/
'''

def initList(nums):
	size = len(nums)
	listNode = None
	if size < 1:
		return listNode
	else:
		listNode = ListNode(nums[0])
	curNode = listNode
	for x in range(1, size):
		curNode.next = ListNode(nums[x])
		curNode = curNode.next
	return listNode

def showList(listNode):
	while listNode is not None:
		print(listNode.val, end=' -> ')
		listNode = listNode.next
	print('NULL')

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
	def addTwoNumbers(self, l1, l2):
		carry = 0
		newList = None
		curList = None
		while l1 is not None and l2 is not None:
			val = l1.val + l2.val + carry
			if newList is None:
				newList = ListNode(val % 10)
				curList = newList
			else:
				curList.next = ListNode(val % 10)
				curList = curList.next
			carry = int(val >= 10)
			l1 = l1.next
			l2 = l2.next
		while l1 is not None:
			val = l1.val + carry
			curList.next = ListNode(val % 10)
			curList = curList.next
			carry = int(val >= 10)
			l1 = l1.next
		while l2 is not None:
			val = l2.val + carry
			curList.next = ListNode(val % 10)
			curList = curList.next
			carry = int(val >= 10)
			l2 = l2.next
		if carry:
			curList.next = ListNode(1)
		return newList

if __name__ == '__main__':
	solution = Solution()
	listNode1 = initList([2, 4, 3])
	listNode2 = initList([5, 6, 4])
	showList(listNode1)
	showList(solution.addTwoNumbers(listNode1, listNode2))