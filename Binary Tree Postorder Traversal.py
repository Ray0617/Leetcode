# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of integers
    def postorderTraversal(self, root):
        ret = []
        if (root == None):
            return ret
        if (root.left != None):
            left = self.postorderTraversal(root.left)
            ret.extend(left)
        if (root.right != None):
            right = self.postorderTraversal(root.right)
            ret.extend(right)
        ret.append(root.val)
        return ret
        