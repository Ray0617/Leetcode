# Definition for a  binary tree node
# class TreeNode:
#	 def __init__(self, x):
#		 self.val = x
#		 self.left = None
#		 self.right = None
#		 self.next = None

class Solution:
	# @param root, a tree node
	# @return nothing
	def connect(self, root):
		if (not root):
			return
		preLevel = root
		curLevel = root.left
		while (curLevel):
			prev = None
			node = preLevel
			while (node):
				if (node.left):
					if (prev):
						prev.next = node.left
					prev = node.left
					if (node.right):
						prev.next = node.right
						prev = node.right
				node = node.next
			preLevel = curLevel
			curLevel = curLevel.left