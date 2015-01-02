/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root)
    : m_root(root)
    {
        TreeNode* node = m_root;
        while (node)
        {
            m_nodes.push_back(node);
            node = node->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !m_nodes.empty();
    }

    /** @return the next smallest number */
    int next() {
        if (m_nodes.empty())
            return 0;
        TreeNode* node = m_nodes.back();
        m_nodes.pop_back();
        int val = node->val;
        if (node->right)
        {
            node = node->right;
            m_nodes.push_back(node);
            while (node->left)
            {
                node = node->left;
                m_nodes.push_back(node);
            }
            
        }
        return val;
    }
private:
    TreeNode* m_root;
    std::vector<TreeNode*> m_nodes;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */