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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > ret;
        if (!root)
            return ret;
        ret.resize(height(root));
        traverse(root, 0, ret);
        return ret;
    }
private:
    void traverse(TreeNode* root, int level, vector<vector<int> >& ret) {
        if (!root)
            return;
        ret[level].push_back(root->val);
        traverse(root->left, level + 1, ret);
        traverse(root->right, level + 1, ret);
    }
    int height(TreeNode* root) {
        if (!root)
            return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
};