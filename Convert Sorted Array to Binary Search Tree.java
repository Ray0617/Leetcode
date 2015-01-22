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
    public TreeNode sortedArrayToBST(int[] num) {
        if (num.length == 0)
            return null;
        int mid_pos = num.length / 2;
        int[] left = java.util.Arrays.copyOfRange(num, 0, mid_pos);
        int mid = num[mid_pos];
        int[] right = java.util.Arrays.copyOfRange(num, mid_pos + 1, num.length);
        TreeNode root = new TreeNode(mid);
        root.left = sortedArrayToBST(left);
        root.right = sortedArrayToBST(right);
        return root;
    }
}
