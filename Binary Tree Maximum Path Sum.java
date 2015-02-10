/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public class Result {
        int m_maxPathSum = Integer.MIN_VALUE;
    };
    private int maxSumEndAt(TreeNode root, Result result) {
        if (root == null) {
            return 0;
        }
        int left = Math.max(0, maxSumEndAt(root.left, result));
        int right = Math.max(0, maxSumEndAt(root.right, result));
        int maxSumIncludingRoot = root.val + left + right;
        if (maxSumIncludingRoot > result.m_maxPathSum)
            result.m_maxPathSum = maxSumIncludingRoot;
        return root.val + Math.max(left, right);
    }
    public int maxPathSum(TreeNode root) {
        Result result = new Result();
        maxSumEndAt(root, result);
        return result.m_maxPathSum;
    }
}