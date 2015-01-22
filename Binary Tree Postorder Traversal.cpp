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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;
        if (!root)
            return ret;
        if (root->left) {
            vector<int> left = postorderTraversal(root->left);
            ret.insert(ret.end(), left.begin(), left.end());
        }
        if (root->right) {
            vector<int> right = postorderTraversal(root->right);
            ret.insert(ret.end(), right.begin(), right.end());
        }
        ret.push_back(root->val);
        return ret;
    }
};