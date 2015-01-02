/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

public class BSTIterator {

    public BSTIterator(TreeNode root) {
        TreeNode node = root;
        while (node != null)
        {
            m_nodes.push(node);
            node = node.left;
        }
    }

    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return !m_nodes.isEmpty();
    }

    /** @return the next smallest number */
    public int next() {
        if (m_nodes.isEmpty())
        {
            //throw exception
            return 0;
        }
        TreeNode node = m_nodes.pop();
        int val = node.val;
        if (node.right != null)
        {
            node = node.right;
            m_nodes.push(node);
            while (node.left != null)
            {
                node = node.left;
                m_nodes.push(node);
            }
        }
        return val;
    }
    
    private Deque<TreeNode> m_nodes = new ArrayDeque<TreeNode>();
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = new BSTIterator(root);
 * while (i.hasNext()) v[f()] = i.next();
 */