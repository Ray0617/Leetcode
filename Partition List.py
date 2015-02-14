# Definition for singly-linked list.
# class ListNode:
#	 def __init__(self, x):
#		 self.val = x
#		 self.next = None

class Solution:
	# @param head, a ListNode
	# @param x, an integer
	# @return a ListNode
	def partition(self, head, x):
		lHead = None
		lTail = None
		geHead = None
		geTail = None
		node = head
		while (node):
			if (node.val < x):
				if (not lHead):
					lHead = lTail = node
				else:
					lTail.next = node
					lTail = node
			else:
				if (not geHead):
					geHead = geTail = node
				else:
					geTail.next = node
					geTail = node
			temp = node
			node = node.next
			temp.next = None
		if (not lHead):
			return geHead
		lTail.next = geHead
		return lHead