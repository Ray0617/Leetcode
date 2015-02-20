/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void connect(TreeLinkNode root) {
        TreeLinkNode prevLevel = root;
        
        if (root == null)
            return;
        TreeLinkNode currLevel = root.left;
        
        while (currLevel != null) {
            TreeLinkNode prev = null;
            TreeLinkNode node = prevLevel;
            while (node != null) {
                if (node.left != null) {
                    if (prev != null)
                        prev.next = node.left;
                    prev = node.left;
                    if (node.right != null) {
                        prev.next = node.right;
                        prev = node.right;
                    }
                }
                node = node.next;
            }
            
            prevLevel = currLevel;
            currLevel = currLevel.left;
        }
    }
}