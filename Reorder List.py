# Definition for singly-linked list.
# class ListNode:
#	 def __init__(self, x):
#		 self.val = x
#		 self.next = None

class Solution:
	# @param head, a ListNode
	# @return nothing
	def reorderList(self, head):
		buf = []
		node = head
		while (node != None):
			buf.append(node)
			node = node.next
		sz = len(buf)
		if (sz <= 2):
			return
		for i in xrange(sz):
			if (i < sz / 2):
				buf[i].next = buf[sz - 1 - i]
			else:
				buf[i].next = buf[sz - i]   # i != 0 => sz >= 2
		buf[sz / 2].next = None;