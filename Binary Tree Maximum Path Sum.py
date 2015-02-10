# Definition for a  binary tree node
# class TreeNode:
#	 def __init__(self, x):
#		 self.val = x
#		 self.left = None
#		 self.right = None

class Solution:
	def maxSumEndAt(self, root, result):
		if (root == None):
			return 0
		left = max(0, self.maxSumEndAt(root.left, result))
		right = max(0, self.maxSumEndAt(root.right, result))
		sumThroughRoot = root.val + left + right
		if (sumThroughRoot > result[0]):
			result[0] = sumThroughRoot
		return root.val + max(left, right)
	# @param root, a tree node
	# @return an integer
	def maxPathSum(self, root):
		if (not root):
			return 0
		result = [root.val]
		self.maxSumEndAt(root, result)
		return result[0]
		