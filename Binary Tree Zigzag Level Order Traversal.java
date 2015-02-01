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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ret = new ArrayList<List<Integer>>();
        if (root == null)
            return ret;
        List<TreeNode> level = new ArrayList<TreeNode>();
        level.add(root);
        boolean leftToRight = true;
        while (!level.isEmpty()) {
            List<Integer> val = new ArrayList<Integer>();
            if (leftToRight) {
                for (TreeNode node : level) {
                    val.add(node.val);
                }
            }
            else {
                for (int i = level.size() - 1; i >= 0; i--) {
                    val.add(level.get(i).val);
                }
            }
            ret.add(val);
            leftToRight = !leftToRight;
            
            List<TreeNode> next = new ArrayList<TreeNode>();
            for (TreeNode node : level) {
                if (node.left != null)
                    next.add(node.left);
                if (node.right != null)
                    next.add(node.right);
            }
            level = next;
        }
        return ret;
    }
}