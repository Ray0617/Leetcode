# Definition for a  binary tree node
# class TreeNode:
#	 def __init__(self, x):
#		 self.val = x
#		 self.left = None
#		 self.right = None

class BSTIterator:
	# @param root, a binary search tree's root node
	def __init__(self, root):
		node = root
		self.nodes = []
		while (node != None):
			self.nodes.append(node)
			node = node.left

	# @return a boolean, whether we have a next smallest number
	def hasNext(self):
		return (len(self.nodes) != 0)

	# @return an integer, the next smallest number
	def next(self):
		last = len(self.nodes)-1
		node = self.nodes.pop(last)
		val = node.val
		if (node.right):
			node = node.right
			self.nodes.append(node)
			while (node.left):
				node = node.left
				self.nodes.append(node)
		return val
		

# Your BSTIterator will be called like this:
# i, v = BSTIterator(root), []
# while i.hasNext(): v.append(i.next())