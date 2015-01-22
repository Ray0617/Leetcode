# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def height(self, root):
        if (root == None):
            return 0
        return max(self.height(root.left), self.height(root.right)) + 1
    # @param root, a tree node
    # @return a boolean
    def isBalanced(self, root):
        if (root == None):
            return True
        return self.isBalanced(root.left) and self.isBalanced(root.right) and abs(self.height(root.left)-self.height(root.right)) <= 1
