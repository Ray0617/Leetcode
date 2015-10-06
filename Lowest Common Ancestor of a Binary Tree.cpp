/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool find(TreeNode* root, TreeNode* p) {
        // assert(p);
        if (!root)
            return false;
        return root == p || find(root->left, p) || find(root->right, p);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;
        if (root == p || root == q)
            return root;
        bool left_p = find(root->left, p);
        bool left_q = find(root->left, q);
        if (left_p && left_q)
            return lowestCommonAncestor(root->left, p, q);
        if (!left_p && !left_q)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};

