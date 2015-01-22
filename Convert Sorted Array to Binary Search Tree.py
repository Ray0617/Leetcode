# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param num, a list of integers
    # @return a tree node
    def sortedArrayToBST(self, num):
        if (len(num) == 0):
            return None
        mid_pos = len(num) / 2
        left = num[0:mid_pos]
        mid = num[mid_pos]
        right = num[(mid_pos+1):len(num)]
        root = TreeNode(mid)
        root.left = self.sortedArrayToBST(left)
        root.right = self.sortedArrayToBST(right)
        return root
