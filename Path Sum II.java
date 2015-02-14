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
    private void findPath(TreeNode root, int target, List<Integer> path, List<List<Integer>> result) {
        if (root == null)
            return;
        if (root.left == null && root.right == null && root.val == target) {
            List<Integer> sol = new ArrayList<Integer>(path);
            sol.add(root.val);
            result.add(sol);
            return;
        }
        path.add(root.val);
        findPath(root.left, target - root.val, path, result);
        findPath(root.right, target - root.val, path, result);
        path.remove(path.size() - 1);
    }
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        List<Integer> path = new ArrayList<Integer>();
        findPath(root, sum, path, result);
        return result;
    }
}