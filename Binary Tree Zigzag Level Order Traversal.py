# Definition for a  binary tree node
# class TreeNode:
#	 def __init__(self, x):
#		 self.val = x
#		 self.left = None
#		 self.right = None

class Solution:
	# @param root, a tree node
	# @return a list of lists of integers
	def zigzagLevelOrder(self, root):
		ret = []
		if (root == None):
			return ret
		prevLevel = [root]
		leftToRight = True
		while (len(prevLevel) > 0):
			val = []
			r = xrange(len(prevLevel))
			if (not leftToRight):
				r = range((len(prevLevel)-1), -1, -1)
			for i in r:
				val.append(prevLevel[i].val)
			leftToRight = not leftToRight
			ret.append(val)
			
			nextLevel = []
			for i in xrange(len(prevLevel)):
				if (prevLevel[i].left):
					nextLevel.append(prevLevel[i].left)
				if (prevLevel[i].right):
					nextLevel.append(prevLevel[i].right)
			prevLevel = nextLevel
		return ret