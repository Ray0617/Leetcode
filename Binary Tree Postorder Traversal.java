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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> ret = new ArrayList<Integer>();
        if (root == null)
            return ret;
        if (root.left != null) {
            List<Integer> left = postorderTraversal(root.left);
            ret.addAll(left);
        }
        if (root.right != null) {
            List<Integer> right = postorderTraversal(root.right);
            ret.addAll(right);
        }
        ret.add(root.val);
        return ret;
    }
}