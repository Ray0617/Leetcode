# Definition for singly-linked list.
# class ListNode:
#	 def __init__(self, x):
#		 self.val = x
#		 self.next = None

class Solution:
	# @param head, a ListNode
	# @return a list node
	def detectCycle(self, head):
		slow = head
		fast = head
		while (slow != None and fast != None):
			slow = slow.next
			fast = fast.next
			if (fast == None):
				return None
			fast = fast.next
			if (slow == fast):
				node = head
				while (node != slow):
					node = node.next
					slow = slow.next
				return node
		return None