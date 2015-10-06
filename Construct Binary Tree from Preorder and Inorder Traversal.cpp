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
    TreeNode* buildTree(vector<int>& preorder, int pre_start, int pre_end, vector<int>& inorder, int in_start, int in_end) {
        if (pre_start == pre_end)
            return nullptr;
        int root_val = preorder[pre_start];
        TreeNode* root = new TreeNode(root_val);
        int left_len = 0;
        while (inorder[in_start + left_len] != root_val)
            left_len++;
        root->left = buildTree(preorder, pre_start + 1, pre_start + 1 + left_len, inorder, in_start, in_start + left_len);
        root->right = buildTree(preorder, pre_start + 1 + left_len, pre_end, inorder, in_start + left_len + 1, in_end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // pre: root-left-right
        // in: left-root-right
        return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};

