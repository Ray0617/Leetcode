# Definition for a  binary tree node
# class TreeNode:
#	 def __init__(self, x):
#		 self.val = x
#		 self.left = None
#		 self.right = None

class Solution:
	def traverse(self, level, root, result):
		if (root == None):
			return
		while (len(result) < level + 1):
			result.append([])
		result[level].append(root.val)
		self.traverse(level + 1, root.left, result)
		self.traverse(level + 1, root.right, result)
	# @param root, a tree node
	# @return a list of lists of integers
	def levelOrder(self, root):
		level = 0
		result = []
		self.traverse(level, root, result)
		return result