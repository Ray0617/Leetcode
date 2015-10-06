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
    bool isValidBST(TreeNode* root, int lower, int upper) {
        if (!root)
            return true;
        if (root->val < lower || root->val > upper)
            return false;
        if (root->val == INT_MIN && root->left)
            return false;
        if (root->val == INT_MAX && root->right)
            return false;
        return isValidBST(root->left, lower, root->val - 1) && isValidBST(root->right, root->val + 1, upper);
    }
    
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, INT_MIN, INT_MAX);
    }
};

