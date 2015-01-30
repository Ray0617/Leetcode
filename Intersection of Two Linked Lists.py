# Definition for singly-linked list.
# class ListNode:
#	 def __init__(self, x):
#		 self.val = x
#		 self.next = None

class Solution:
	countB = 0
	retNode = None
	
	def forAllNode(self, node, fnx):
		while (node != None):
			fnx(node)
			node = node.next
		
	def sum(self, node):
		ret = 0
		while (node != None):
			ret = ret + node.val
			node = node.next
		return ret
	
	def addValAndCount(self, node):
		self.countB = self.countB + 1
		node.val = node.val + 1
		
	def decValAndCount(self, node):
		if (self.countB == 0):
			self.retNode = node
		self.countB = self.countB - 1
		node.val = node.val - 1
		
	# @param two ListNodes
	# @return the intersected ListNode
	def getIntersectionNode(self, headA, headB):
		sumA = self.sum(headA)
		
		self.countB = 0
		self.forAllNode(headB, self.addValAndCount)

		sharedNode = self.sum(headA) - sumA
		self.countB = self.countB - sharedNode
		self.retNode = None
		self.forAllNode(headB, self.decValAndCount)
		
		return self.retNode