/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right)
    {
        if (left == 0 && right == 0)
            return true;
        if (left == 0 || right == 0)
            return false;
        if (left->val != right->val)
            return false;
        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
    bool isSymmetric(TreeNode *root) {
        if (root == 0)
            return true;
        return isMirror(root->left, root->right);
    }
};