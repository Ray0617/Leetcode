# Definition for singly-linked list with a random pointer.
# class RandomListNode:
#     def __init__(self, x):
#         self.label = x
#         self.next = None
#         self.random = None
class Solution:
	# @param head, a RandomListNode
	# @return a RandomListNode
	def copyRandomList(self, head):
		node = head
		while (node != None):
			clone = RandomListNode(node.label)
			clone.next = node.next
			node.next = clone
			node = clone.next
		node = head
		while (node != None):
			if (node.random != None):
				clone = node.next
				clonerandom = node.random.next
				clone.random = clonerandom
			node = node.next.next
		if (head == None):
			return None
		clonehead = head.next
		node = head
		clone = clonehead
		while (node != None):
			node.next = clone.next
			if (clone.next != None):
				clone.next = clone.next.next
			node = node.next
			clone = clone.next
		return clonehead
