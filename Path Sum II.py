# Definition for a  binary tree node
# class TreeNode:
#	 def __init__(self, x):
#		 self.val = x
#		 self.left = None
#		 self.right = None

class Solution:
	def findPath(self, root, target, path, result):
		if (not root):
			return
		if (not root.left and not root.right and target == root.val):
			result.append(path + [root.val])
			return
		path.append(root.val)
		self.findPath(root.left, target - root.val, path, result)
		self.findPath(root.right, target - root.val, path, result)
		path.pop()
	# @param root, a tree node
	# @param sum, an integer
	# @return a list of lists of integers
	def pathSum(self, root, sum):
		path = []
		result = []
		self.findPath(root, sum, path, result)
		return result