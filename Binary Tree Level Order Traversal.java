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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        traverse(root, 0, result);
        return result;
    }
    private void traverse(TreeNode root, int level, List<List<Integer>> result) {
        if (root == null)
            return;
        while (result.size() <= level) {
            result.add(new ArrayList<Integer>());
        }
        result.get(level).add(root.val);
        traverse(root.left, level + 1, result);
        traverse(root.right, level + 1, result);
    }
}