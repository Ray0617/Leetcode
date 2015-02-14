# Definition for singly-linked list.
# class ListNode:
#	 def __init__(self, x):
#		 self.val = x
#		 self.next = None

class Solution:
	# @param head, a ListNode
	# @return a ListNode
	def deleteDuplicates(self, head):
		if (not head):
			return None
		node = head
		prev = None
		result = None
		preval = head.val - 1
		while (node):
			if (node.val == preval or node.next and node.next.val == node.val):
				# this node should be removed
				preval = node.val
				if (prev):
					prev.next = node.next
			else:
				# this node should be preserved (due to uniqueness)
				prev = node
				if (not result):
					result = node
			node = node.next
		return result
		